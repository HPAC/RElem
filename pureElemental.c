#include "R-El.h"


static void _clear(SEXP Rptr){
  if (R_ExternalPtrAddr(Rptr) != NULL){
    void *Cptr = (void *) R_ExternalPtrAddr(Rptr);
    free(Cptr);
    R_ClearExternalPtr(Rptr);
  }
}

//Section: Environment
SEXP elInitialize(){
  int argc = 0;
  char **argv = NULL;
  ElInitialize(&argc,&argv);
  return R_NilValue;
}

SEXP elFinalize(){
  ElFinalize();
  return R_NilValue;
}

SEXP elInitialized(){
  bool Cresult;
  SEXP Rresult=PROTECT(allocVector(LGLSXP,1));
  ElInitialized(&Cresult);
  INTEGER(Rresult)[0]=Cresult;
  UNPROTECT(1);
  return Rresult;

}

SEXP printVersion(){
  ElPrintVersion(stdout);
  return R_NilValue;
}

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

//Section: aux functions


SEXP ReturnString(){
  SEXP text;
  text = PROTECT(allocVector(STRSXP,10));
  UNPROTECT(1);
  strcpy( (char *)CHAR(STRING_ELT(text,1)),"Hola Rod");
  return text;
}


//Section: Matrices (sequential)


//Section: Grids

SEXP newGrid(){
  ElConstGrid *pGrid = malloc(sizeof(ElConstGrid));
  ElDefaultGrid(pGrid);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pGrid, install("Grid"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  return Rptr;
}

//  *Check if it really necessary
SEXP newGridC(){
  ElGrid *pGrid = malloc(sizeof(ElGrid));
  ElGridCreate(MPI_COMM_WORLD, EL_COLUMN_MAJOR, pGrid);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pGrid, install("Grid"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  return Rptr;
}

//Section: DistMatrices


//Section Matrices  

SEXP uniformMatrix_d(SEXP Rptr, SEXP height, SEXP width){
  ElUniform_d( toMatrix_d(Rptr), toElInt(height), toElInt(width)
                   , 0, 1 );
  return R_NilValue;
}

SEXP uniformDistMatrix_d(SEXP Rptr, SEXP height, SEXP width){
  ElUniformDist_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width)
                   , 0, 1 );
  return R_NilValue;
}


//Section Lapack

SEXP hermitianEig_d(SEXP RptrA, SEXP Rptrw){
  //Assuming Lower and unsorted:
  ElMatrix_d A = *(ElMatrix_d *) R_ExternalPtrAddr(RptrA);
  ElMatrix_d w = *(ElMatrix_d *) R_ExternalPtrAddr(Rptrw);
  ElHermitianEig_d(EL_LOWER,A,w,EL_UNSORTED);
  return R_NilValue;
}

SEXP hermitianEigDist_d(SEXP RptrA, SEXP Rptrw){
  //Assuming Lower and unsorted:
  ElDistMatrix_d A = *(ElDistMatrix_d *) R_ExternalPtrAddr(RptrA);
  ElDistMatrix_d w = *(ElDistMatrix_d *) R_ExternalPtrAddr(Rptrw);
  ElHermitianEigDist_d(EL_LOWER,A,w,EL_UNSORTED);
  return R_NilValue;
}

SEXP hermitianEigPair_d(SEXP RptrA, SEXP Rptrw, SEXP RptrZ){
  //Assuming Lower and unsorted:
  ElMatrix_d A = *(ElMatrix_d *) R_ExternalPtrAddr(RptrA);
  ElMatrix_d w = *(ElMatrix_d *) R_ExternalPtrAddr(Rptrw);
  ElMatrix_d Z = *(ElMatrix_d *) R_ExternalPtrAddr(RptrZ);
  ElHermitianEigPair_d(EL_LOWER,A,w,Z,EL_UNSORTED);
  return R_NilValue;
}

SEXP hermitianEigPairDist_d(SEXP RptrA, SEXP Rptrw, SEXP RptrZ){
  //Assuming Lower and unsorted:
  ElDistMatrix_d A = *(ElDistMatrix_d *) R_ExternalPtrAddr(RptrA);
  ElDistMatrix_d w = *(ElDistMatrix_d *) R_ExternalPtrAddr(Rptrw);
  ElDistMatrix_d Z = *(ElDistMatrix_d *) R_ExternalPtrAddr(RptrZ);
  ElHermitianEigPairDist_d(EL_LOWER,A,w,Z,EL_UNSORTED);
  return R_NilValue;
}

ElHermitianEigSubset_d subsetParamsIdx_d(ElInt idxa, ElInt idxb){
  ElHermitianEigSubset_d subset;
  ElHermitianEigSubsetDefault_d(&subset);
  subset.indexSubset = true;
  subset.lowerIndex = idxa;
  subset.upperIndex = idxb;
  return subset;
}

SEXP hermitianEigPairPartialDist_d(SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP idx1, SEXP idx2){
  ElInt idxa = (ElInt)INTEGER(idx1)[0];
  ElInt idxb = (ElInt)INTEGER(idx2)[0];
  ElHermitianEigSubset_d subset = subsetParamsIdx_d(idxa,idxb);
  ElDistMatrix_d A = *(ElDistMatrix_d *) R_ExternalPtrAddr(RptrA);
  ElDistMatrix_d w = *(ElDistMatrix_d *) R_ExternalPtrAddr(Rptrw);
  ElDistMatrix_d Z = *(ElDistMatrix_d *) R_ExternalPtrAddr(RptrZ);
  ElError e;
  e = ElHermitianEigPairPartialDist_d(EL_LOWER,A,w,Z,EL_UNSORTED, subset);
  EL_ABORT_ON_ERROR(e);
  return R_NilValue;
}
