#include "R-El.h"

SEXP gemv_d
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemv_d( parseOrientation(orientation), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(Rptrx), toDouble(beta), toMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP gemvDist_d
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemvDist_d( parseOrientation(orientation), toDouble(alpha), 
                toDistMatrix_d(RptrA), toDistMatrix_d(Rptrx),
                toDouble(beta), toDistMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP ger_d( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGer_d( toDouble(alpha), toMatrix_d(Rptrx), toMatrix_d(Rptry), 
           toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP gerDist_d( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGerDist_d( toDouble(alpha), toDistMatrix_d(Rptrx), toDistMatrix_d(Rptry),
               toDistMatrix_d(RptrA) );
  return R_NilValue;
}


/*
Hemv
Her
Her2
*/

SEXP quasiTrsv_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrx){
  ElQuasiTrsv_d( parseUpLo(uplo), parseOrientation(orientation),
                 toMatrix_d(RptrA), toMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP quasiTrsvDist_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrx){
  ElQuasiTrsvDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                     toDistMatrix_d(RptrA), toDistMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP symv_d
( SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemv_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(Rptrx), toDouble(beta), toMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP symvDist_d
(SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemvDist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(RptrA),
            toDistMatrix_d(Rptrx), toDouble(beta), toDistMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP syr_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElSyr_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(Rptrx),
           toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syrDist_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElSyrDist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(Rptrx),
               toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syr2_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElSyr2_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(Rptrx), 
            toMatrix_d(Rptry), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syr2Dist_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElSyr2Dist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(Rptrx),
                toDistMatrix_d(Rptry), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trmv_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrmv_d( parseUpLo(uplo), parseOrientation(orientation), parseUnit(diagunit),
            toMatrix_d(RptrA), toMatrix_d(Rptrx) );
  return R_NilValue;
}

/* Not implemented !!!
SEXP trmvDist_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrmvDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                parseUnit(diagunit), toDistMatrix_d(RptrA), 
                toDistMatrix_d(Rptrx) );
  return R_NilValue;
}
*/

SEXP trr_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA ){
  ElTrr_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(Rptrx), 
           toMatrix_d(Rptry), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trrDist_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA ){
  ElTrrDist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(Rptrx),
               toDistMatrix_d(Rptry), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trr2_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA ){
  ElTrr2_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrX),
            toMatrix_d(RptrY), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trr2Dist_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA ){
  ElTrr2Dist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(RptrX),
               toDistMatrix_d(RptrY), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trsv_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrsv_d( parseUpLo(uplo), parseOrientation(orientation), parseUnit(diagunit),
            toMatrix_d(RptrA), toMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP trsvDist_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrsvDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                parseUnit(diagunit), toDistMatrix_d(RptrA),
                toDistMatrix_d(Rptrx) );
  return R_NilValue;
}
