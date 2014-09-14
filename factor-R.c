#include "R-El.h"

ElLDLPivotType parsePivotType(SEXP ptype){
  char *text=(char*) CHAR( STRING_ELT(ptype,0) );
  //  printf("The distro is: %s\n",text);
  if (strcmp("EL_BUNCH_KAUFMAN_A",text)==0) return EL_BUNCH_KAUFMAN_A;
  if (strcmp("EL_BUNCH_KAUFMAN_C",text)==0) return EL_BUNCH_KAUFMAN_C;
  if (strcmp("EL_BUNCH_KAUFMAN_D",text)==0) return EL_BUNCH_KAUFMAN_D;
  if (strcmp("EL_BUNCH_KAUFMAN_BOUNDED",text)==0) 
    return EL_BUNCH_KAUFMAN_BOUNDED;
  if (strcmp("EL_BUNCH_PARLETT",text)==0) return EL_BUNCH_PARLETT;
  return EL_BUNCH_KAUFMAN_A;
}



SEXP cholesky_d( SEXP uplo, SEXP RptrA){
  ElCholesky_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP choleskyDist_d( SEXP uplo, SEXP RptrA){
  ElCholeskyDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP solveAfterCholesky_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB){
  ElSolveAfterCholesky_d( parseUpLo(uplo), parseOrientation(orientation),
                          toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyDist_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB){
  ElSolveAfterCholeskyDist_d( parseUpLo(uplo), parseOrientation(orientation),
                          toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP reverseCholesky_d( SEXP uplo, SEXP RptrA){
  ElReverseCholesky_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP reverseCholeskyDist_d( SEXP uplo, SEXP RptrA){
  ElReverseCholeskyDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP choleskyPiv_d( SEXP uplo, SEXP RptrA, SEXP Rptrp){
  ElCholeskyPiv_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP choleskyPivDist_d( SEXP uplo, SEXP RptrA, SEXP Rptrp){
  ElCholeskyPivDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                       toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP solveAfterCholeskyFullPiv_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterCholeskyFullPiv_d( parseUpLo(uplo), parseOrientation(orientation),
                                 toMatrix_d(RptrA), toMatrix_i(Rptrp),
                                 toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyFullPivDist_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterCholeskyFullPivDist_d( parseUpLo(uplo), 
                                     parseOrientation(orientation),
                                     toDistMatrix_d(RptrA), 
                                     toDistMatrix_i(Rptrp),
                                     toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP choleskyMod_d( SEXP uplo, SEXP RptrT, SEXP alpha, SEXP RptrV){
  ElCholeskyMod_d( parseUpLo(uplo), toMatrix_d(RptrT), toDouble(alpha),
                   toMatrix_d(RptrV) );
  return R_NilValue;
}

SEXP choleskyModDist_d( SEXP uplo, SEXP RptrT, SEXP alpha, SEXP RptrV){
  ElCholeskyModDist_d( parseUpLo(uplo), toDistMatrix_d(RptrT), toDouble(alpha),
                   toDistMatrix_d(RptrV) );
  return R_NilValue;
}

SEXP hPSDcholesky_d( SEXP uplo, SEXP RptrA){
  ElHPSDCholesky_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPSDcholeskyDist_d( SEXP uplo, SEXP RptrA){
  ElHPSDCholeskyDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lDL_d( SEXP RptrA ){
  ElLDL_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lDLDist_d( SEXP RptrA ){
  ElLDLDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lDLPiv_d( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP pivotType){
  ElLDLPiv_d( toMatrix_d(RptrA), toMatrix_d(RptrdSub), toMatrix_i(Rptrp),
              parsePivotType(pivotType) );
  return R_NilValue;
}

SEXP lDLPivDist_d( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP pivotType){
  ElLDLPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrdSub), 
                  toDistMatrix_i(Rptrp), parsePivotType(pivotType) );
  return R_NilValue;
}
