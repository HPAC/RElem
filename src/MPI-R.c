#include "R-El.h"

SEXP getWorldRank(){
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  SEXP Rank = PROTECT( allocVector(INTSXP,1));
  INTEGER(Rank)[0]=rank;
  UNPROTECT(1);
  return Rank;
}

SEXP getWorldSize(){
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  SEXP Size = PROTECT( allocVector(INTSXP,1));
  INTEGER(Size)[0]=size;
  UNPROTECT(1);
  return Size;
}

SEXP wTime(){
  SEXP WTime = PROTECT( allocVector(REALSXP,1));
  REAL(WTime)[0]=MPI_Wtime();
  UNPROTECT(1);
  return WTime;
}

SEXP worldBarrier(){
  MPI_Barrier(MPI_COMM_WORLD);
  return R_NilValue;
}

SEXP allReduce( SEXP var, SEXP count, SEXP datatype, SEXP op, SEXP comm){
  SEXP ans;
  if( parseMPIDatatype(datatype) == MPI_DOUBLE){
    ans = PROTECT( allocVector(REALSXP, toElInt(count)) );
    MPI_Allreduce( REAL(var), REAL(ans), toElInt(count), parseMPIDatatype(datatype),
                   parseMPIOp(op), toComm(comm) );
    UNPROTECT(1);
  }
  else{
    if( parseMPIDatatype(datatype) == MPI_INTEGER){
      ans = PROTECT( allocVector(INTSXP, toElInt(count)) );
      MPI_Allreduce( INTEGER(var), INTEGER(ans), toElInt(count),
                     parseMPIDatatype(datatype),
                     parseMPIOp(op), toComm(comm) );
      UNPROTECT(1);
    }
    else{
      printf("Not defined for this datatype\n");
      ans=R_NilValue;
    }
  }
  return ans;
}

MPI_Datatype parseMPIDatatype(SEXP type){
  char *text=(char*) CHAR( STRING_ELT(type,0) );
  if (strcmp("DOUBLE",text)==0) return MPI_DOUBLE;
  if (strcmp("INTEGER",text)==0) return MPI_INTEGER;
  return MPI_DOUBLE;
}

MPI_Op parseMPIOp(SEXP Op){
  char *text=(char*) CHAR( STRING_ELT(Op,0) );
  if (strcmp("SUM",text)==0) return MPI_SUM;
  if (strcmp("MIN",text)==0) return MPI_MIN;
  if (strcmp("MAX",text)==0) return MPI_MAX;
  return MPI_SUM;
}

/* Destructor and Creator MPI_Comm */

static void _clear(SEXP Rptr){
  if (R_ExternalPtrAddr(Rptr) != NULL){
    void *Cptr = (void *) R_ExternalPtrAddr(Rptr);
    free(Cptr);
    R_ClearExternalPtr(Rptr);
  }
}

SEXP newMPIComm(){
  MPI_Comm *pComm = malloc(sizeof(MPI_Comm));
  *pComm = MPI_COMM_WORLD;
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pComm, R_NilValue , R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  setAttrib(Rptr, R_ClassSymbol, mkString("p_MPI_Comm"));
  UNPROTECT(1);
  return Rptr;
}


  
