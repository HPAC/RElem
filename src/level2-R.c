#include "R-El.h"

SEXP gemv_i
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemv_i( parseOrientation(orientation), toDouble(alpha), toMatrix_i(RptrA),
            toMatrix_i(Rptrx), toElInt(beta), toMatrix_i(Rptry) );
  return R_NilValue;
}

SEXP gemv_d
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemv_d( parseOrientation(orientation), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(Rptrx), toDouble(beta), toMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP gemv_z
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemv_z( parseOrientation(orientation), toDComplex(alpha), toMatrix_z(RptrA),
            toMatrix_z(Rptrx), toDComplex(beta), toMatrix_z(Rptry) );
  return R_NilValue;
}

SEXP gemvDist_i
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemvDist_i( parseOrientation(orientation), toDouble(alpha), 
                toDistMatrix_i(RptrA), toDistMatrix_i(Rptrx),
                toElInt(beta), toDistMatrix_i(Rptry) );
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

SEXP gemvDist_z
( SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrx,
  SEXP beta, SEXP Rptry){
  ElGemvDist_z( parseOrientation(orientation), toDComplex(alpha), 
                toDistMatrix_z(RptrA), toDistMatrix_z(Rptrx),
                toDComplex(beta), toDistMatrix_z(Rptry) );
  return R_NilValue;
}
/*
SEXP ger_i( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGer_i( toElInt(alpha), toMatrix_i(Rptrx), toMatrix_i(Rptry), 
           toMatrix_i(RptrA) );
  return R_NilValue;
}
*/
SEXP ger_d( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGer_d( toDouble(alpha), toMatrix_d(Rptrx), toMatrix_d(Rptry), 
           toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP ger_z( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGer_z( toDComplex(alpha), toMatrix_z(Rptrx), toMatrix_z(Rptry), 
           toMatrix_z(RptrA) );
  return R_NilValue;
}
/*
SEXP gerDist_i( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGerDist_i( toElInt(alpha), toDistMatrix_i(Rptrx), toDistMatrix_i(Rptry),
               toDistMatrix_i(RptrA) );
  return R_NilValue;
}
*/
SEXP gerDist_d( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGerDist_d( toDouble(alpha), toDistMatrix_d(Rptrx), toDistMatrix_d(Rptry),
               toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP gerDist_z( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGerDist_z( toDComplex(alpha), toDistMatrix_z(Rptrx), toDistMatrix_z(Rptry),
               toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP geru_z( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGeru_z( toDComplex(alpha), toMatrix_z(Rptrx), toMatrix_z(Rptry),
	    toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP geruDist_z( SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElGeruDist_z( toDComplex(alpha), toDistMatrix_z(Rptrx), toDistMatrix_z(Rptry),
               toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hemv_z
( SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElHemv_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(RptrA),
	    toMatrix_z(Rptrx), toDComplex(beta), toMatrix_z(Rptry) );
  return R_NilValue;
}

SEXP hemvDist_z
( SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElHemvDist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(RptrA),
	    toDistMatrix_z(Rptrx), toDComplex(beta), toDistMatrix_z(Rptry) );
  return R_NilValue;
}

SEXP her_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElHer_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(Rptrx),
	   toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP herDist_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElHerDist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(Rptrx),
	       toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP her2_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElHer2_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(Rptrx),
	    toMatrix_z(Rptry), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP her2Dist_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElHer2Dist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(Rptrx),
		toDistMatrix_z(Rptry), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP quasiTrsv_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrx){
  ElQuasiTrsv_d( parseUpLo(uplo), parseOrientation(orientation),
                 toMatrix_d(RptrA), toMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP quasiTrsv_z( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrx){
  ElQuasiTrsv_z( parseUpLo(uplo), parseOrientation(orientation),
                 toMatrix_z(RptrA), toMatrix_z(Rptrx) );
  return R_NilValue;
}

SEXP quasiTrsvDist_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrx){
  ElQuasiTrsvDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                     toDistMatrix_d(RptrA), toDistMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP quasiTrsvDist_z( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrx){
  ElQuasiTrsvDist_z( parseUpLo(uplo), parseOrientation(orientation), 
                     toDistMatrix_z(RptrA), toDistMatrix_z(Rptrx) );
  return R_NilValue;
}

SEXP symv_i
( SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemv_i( parseUpLo(uplo), toElInt(alpha), toMatrix_i(RptrA),
            toMatrix_i(Rptrx), toElInt(beta), toMatrix_i(Rptry) );
  return R_NilValue;
}

SEXP symv_d
( SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemv_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(Rptrx), toDouble(beta), toMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP symv_z
( SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemv_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(RptrA),
            toMatrix_z(Rptrx), toDComplex(beta), toMatrix_z(Rptry) );
  return R_NilValue;
}

SEXP symvDist_i
(SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemvDist_i( parseUpLo(uplo), toElInt(alpha), toDistMatrix_i(RptrA),
		toDistMatrix_i(Rptrx), toElInt(beta), toDistMatrix_i(Rptry) );
  return R_NilValue;
}

SEXP symvDist_d
(SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemvDist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(RptrA),
		toDistMatrix_d(Rptrx), toDouble(beta), toDistMatrix_d(Rptry) );
  return R_NilValue;
}

SEXP symvDist_z
(SEXP uplo, SEXP alpha, SEXP RptrA, SEXP Rptrx, SEXP beta, SEXP Rptry){
  ElGemvDist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(RptrA),
            toDistMatrix_z(Rptrx), toDComplex(beta), toDistMatrix_z(Rptry) );
  return R_NilValue;
}

SEXP syr_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElSyr_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(Rptrx),
           toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syr_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElSyr_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(Rptrx),
           toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP syrDist_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElSyrDist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(Rptrx),
               toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syrDist_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP RptrA){
  ElSyrDist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(Rptrx),
               toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP syr2_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElSyr2_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(Rptrx), 
            toMatrix_d(Rptry), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syr2_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElSyr2_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(Rptrx), 
            toMatrix_z(Rptry), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP syr2Dist_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElSyr2Dist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(Rptrx),
                toDistMatrix_d(Rptry), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP syr2Dist_z( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA){
  ElSyr2Dist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(Rptrx),
                toDistMatrix_z(Rptry), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP trmv_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrmv_d( parseUpLo(uplo), parseOrientation(orientation), parseUnit(diagunit),
            toMatrix_d(RptrA), toMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP trmv_z
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrmv_z( parseUpLo(uplo), parseOrientation(orientation), parseUnit(diagunit),
            toMatrix_z(RptrA), toMatrix_z(Rptrx) );
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

SEXP trr_i( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA ){
  ElTrr_i( parseUpLo(uplo), toElInt(alpha), toMatrix_i(Rptrx), 
           toMatrix_i(Rptry), toMatrix_i(RptrA) );
  return R_NilValue;
}

SEXP trr_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA ){
  ElTrr_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(Rptrx), 
           toMatrix_d(Rptry), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trr_z
( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA, SEXP conjugate){
  ElTrr_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(Rptrx), 
           toMatrix_z(Rptry), toMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP trrDist_d( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA ){
  ElTrrDist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(Rptrx),
               toDistMatrix_d(Rptry), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trrDist_i( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA ){
  ElTrrDist_i( parseUpLo(uplo), toElInt(alpha), toDistMatrix_i(Rptrx),
               toDistMatrix_i(Rptry), toDistMatrix_i(RptrA) );
  return R_NilValue;
}

SEXP trrDist_z
( SEXP uplo, SEXP alpha, SEXP Rptrx, SEXP Rptry, SEXP RptrA, SEXP conjugate ){
  ElTrrDist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(Rptrx),
               toDistMatrix_z(Rptry), toDistMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP trr2_i( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA ){
  ElTrr2_i( parseUpLo(uplo), toElInt(alpha), toMatrix_i(RptrX),
            toMatrix_i(RptrY), toMatrix_i(RptrA) );
  return R_NilValue;
}

SEXP trr2_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA ){
  ElTrr2_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrX),
            toMatrix_d(RptrY), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trr2_z
( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA, SEXP conjugate ){
  ElTrr2_z( parseUpLo(uplo), toDComplex(alpha), toMatrix_z(RptrX),
            toMatrix_z(RptrY), toMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP trr2Dist_i( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA ){
  ElTrr2Dist_i( parseUpLo(uplo), toElInt(alpha), toDistMatrix_i(RptrX),
		toDistMatrix_i(RptrY), toDistMatrix_i(RptrA) );
  return R_NilValue;
}

SEXP trr2Dist_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA ){
  ElTrr2Dist_d( parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(RptrX),
		toDistMatrix_d(RptrY), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trr2Dist_z
( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP RptrA, SEXP conjugate ){
  ElTrr2Dist_z( parseUpLo(uplo), toDComplex(alpha), toDistMatrix_z(RptrX),
		toDistMatrix_z(RptrY), toDistMatrix_z(RptrA),
		toBool(conjugate) );
  return R_NilValue;
}

SEXP trsv_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrsv_d( parseUpLo(uplo), parseOrientation(orientation), parseUnit(diagunit),
            toMatrix_d(RptrA), toMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP trsv_z
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrsv_z( parseUpLo(uplo), parseOrientation(orientation), parseUnit(diagunit),
            toMatrix_z(RptrA), toMatrix_z(Rptrx) );
  return R_NilValue;
}

SEXP trsvDist_d
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrsvDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                parseUnit(diagunit), toDistMatrix_d(RptrA),
                toDistMatrix_d(Rptrx) );
  return R_NilValue;
}

SEXP trsvDist_z
( SEXP uplo, SEXP orientation, SEXP diagunit, SEXP RptrA, SEXP Rptrx){
  ElTrsvDist_z( parseUpLo(uplo), parseOrientation(orientation), 
                parseUnit(diagunit), toDistMatrix_z(RptrA),
                toDistMatrix_z(Rptrx) );
  return R_NilValue;
}
