#include "R-El.h"

SEXP axpy_d( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpy_d( toDouble(alpha), toMatrix_d(RptrX), toMatrix_d(RptrY) );
  return R_NilValue;
}
SEXP axpyDist_d( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyDist_d( toDouble(alpha), toDistMatrix_d(RptrX), toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP axpyTriangle_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyTriangle_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrX), toMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP axpyTriangleDist_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyTriangleDist_d( parseUpLo(uplo), toDouble(alpha),
                        toDistMatrix_d(RptrX), toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP copy_d( SEXP A, SEXP B){
  ElCopy_d( toMatrix_d(A), toMatrix_d(B) );
  return R_NilValue;
}

SEXP copyDist_d( SEXP A, SEXP B){
  ElCopyDist_d( toDistMatrix_d(A), toDistMatrix_d(B) );
  return R_NilValue;
}

SEXP diagonalScale_d( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScale_d( parseSide(side), parseOrientation(orientation),
                     toMatrix_d(Rptrd), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleDist_d( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScaleDist_d( parseSide(side), parseOrientation(orientation),
                     toDistMatrix_d(Rptrd), toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleTrapezoid_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoid_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                     toMatrix_d(Rptrd), toMatrix_d(RptrX), toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalScaleTrapezoidDist_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoidDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                     toDistMatrix_d(Rptrd), toDistMatrix_d(RptrX), toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalSolve_d( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolve_d( parseSide(side), parseOrientation(orientation),
                     toMatrix_d(Rptrd), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalSolveDist_d( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolveDist_d( parseSide(side), parseOrientation(orientation),
                     toDistMatrix_d(Rptrd), toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalSolveTrapezoid_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalSolveTrapezoid_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                     toMatrix_d(Rptrd), toMatrix_d(RptrX), toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalSolveTrapezoidDist_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalSolveTrapezoidDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                     toDistMatrix_d(Rptrd), toDistMatrix_d(RptrX), toElInt(offset) );
  return R_NilValue;
}

SEXP dot_d( SEXP RptrA, SEXP RptrB, SEXP prod){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDot_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  return ans;
}
SEXP dotDist_d( SEXP RptrA, SEXP RptrB, SEXP prod){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDotDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), REAL(ans) );
  return ans;
}

SEXP dotu_d( SEXP RptrA, SEXP RptrB, SEXP prod){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDotu_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  return ans;
}
SEXP dotuDist_d( SEXP RptrA, SEXP RptrB, SEXP prod){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDotuDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), REAL(ans) );
  return ans;
}

//Figure out how to do for the entry filling, decide if it is worth to do in C or R

SEXP fill_d(SEXP Rptr, SEXP alpha){
  ElFill_d( toMatrix_d(Rptr), toDouble(alpha) );
  return R_NilValue;
}

SEXP fillDist_d(SEXP Rptr, SEXP alpha){
  ElFillDist_d( toDistMatrix_d(Rptr), toDouble(alpha) );
  return R_NilValue;
}

SEXP hadamard_d(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamard_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP hadamardDist_d(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamardDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP hilbertSchmidt_d(SEXP RptrA, SEXP RptrB, SEXP prod){
  ElHilbertSchmidt_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toDouble_p(prod) );
  return R_NilValue;
}

SEXP hilbertSchmidtDist_d(SEXP RptrA, SEXP RptrB, SEXP prod){
  ElHilbertSchmidtDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toDouble_p(prod) );
  return R_NilValue;
}

/* IndexDependentFill
   ================== */

/* IndexDependentMap
   ================== */

SEXP makeTrapezoidal(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidal_d( parseUpLo(uplo), toMatrix_d(RptrA), toElInt(offset) );
  return R_NilValue;
}

SEXP makeTrapezoidalDist(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidalDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), toElInt(offset) );
  return R_NilValue;
}
