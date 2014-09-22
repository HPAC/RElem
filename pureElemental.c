#include "R-El.h"

//Section: Environment
SEXP initialize(){
  int argc = 0;
  char **argv = NULL;
  ElInitialize(&argc,&argv);
  return R_NilValue;
}

SEXP finalize(){
  ElFinalize();
  return R_NilValue;
}

SEXP initialized(){
  SEXP Rresult=PROTECT(allocVector(LGLSXP,1));
  ElInitialized( (bool *)LOGICAL(Rresult) );
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


//Section Matrices  

SEXP uniform_d(SEXP Rptr, SEXP height, SEXP width){
  ElUniform_d( toMatrix_d(Rptr), toElInt(height), toElInt(width)
                   , 0, 1 );
  return R_NilValue;
}

SEXP uniformDist_d(SEXP Rptr, SEXP height, SEXP width){
  ElUniformDist_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width)
                   , 0, 1 );
  return R_NilValue;
}
