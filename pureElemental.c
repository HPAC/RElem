#include "R-El.h"

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
  ElHermitianEig_d(EL_LOWER, toMatrix_d(RptrA), toMatrix_d(Rptrw), EL_UNSORTED);
  return R_NilValue;
}

SEXP hermitianEigDist_d(SEXP RptrA, SEXP Rptrw){
  //Assuming Lower and unsorted:
  ElHermitianEigDist_d( EL_LOWER,toDistMatrix_d(RptrA), toDistMatrix_d(Rptrw), EL_UNSORTED );
  return R_NilValue;
}

SEXP hermitianEigPair_d(SEXP RptrA, SEXP Rptrw, SEXP RptrZ){
  //Assuming Lower and unsorted:
  ElHermitianEigPair_d(EL_LOWER,toMatrix_d(RptrA), toMatrix_d(Rptrw),
                       toMatrix_d(RptrZ), EL_UNSORTED);
  return R_NilValue;
}

SEXP hermitianEigPairDist_d(SEXP RptrA, SEXP Rptrw, SEXP RptrZ){
  //Assuming Lower and unsorted:
  ElHermitianEigPairDist_d( EL_LOWER, toDistMatrix_d(RptrA), toDistMatrix_d(Rptrw), 
                            toDistMatrix_d(RptrZ), EL_UNSORTED );
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
  ElError e;
  e = ElHermitianEigPairPartialDist_d( EL_LOWER, toDistMatrix_d(RptrA), 
                                       toDistMatrix_d(Rptrw), toDistMatrix_d(RptrZ),
                                       EL_UNSORTED, subset );
  EL_ABORT_ON_ERROR(e);
  return R_NilValue;
}
