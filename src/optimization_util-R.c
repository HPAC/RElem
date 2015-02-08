#include "R-El.h"

/* Coherence
 */

SEXP coherence_d( SEXP MatrixA ){
  SEXP coherence = PROTECT( allocVector(REALSXP,1) );
  ElCoherence_d( toMatrix_d(MatrixA), REAL(coherence) );
  UNPROTECT(1);
  return coherence;
}

SEXP coherenceDist_d( SEXP MatrixA ){
  SEXP coherence = PROTECT( allocVector(REALSXP,1) );
  ElCoherenceDist_d( toDistMatrix_d(MatrixA), REAL(coherence) );
  UNPROTECT(1);
  return coherence;
}

/* Covariance
 */

SEXP covariance_d( SEXP MatrixD, SEXP MatrixS ){
  ElCovariance_d( toMatrix_d(MatrixD), toMatrix_d(MatrixS) );
  return R_NilValue;
}

SEXP covarianceDist_d( SEXP MatrixD, SEXP MatrixS ){
  ElCovarianceDist_d( toDistMatrix_d(MatrixD), toDistMatrix_d(MatrixS) );
  return R_NilValue;
}

/* Log barrier
 */

SEXP logBarrier_d( SEXP uplo, SEXP MatrixA){
  SEXP barrier=PROTECT( allocVector(REALSXP,1));
  ElLogBarrier_d( parseUpLo(uplo), toMatrix_d(MatrixA),
                  REAL(barrier) );
  UNPROTECT(1);
  return barrier;
}

SEXP logBarrierDist_d( SEXP uplo, SEXP MatrixA){
  SEXP barrier=PROTECT( allocVector(REALSXP,1));
  ElLogBarrierDist_d( parseUpLo(uplo), toDistMatrix_d(MatrixA),
                      REAL(barrier) );
  UNPROTECT(1);
  return barrier;
}

/* Log det divergence */

SEXP logDetDiv_d( SEXP uplo, SEXP MatrixA, SEXP MatrixB){
  SEXP div=PROTECT( allocVector(REALSXP,1));
  ElLogDetDiv_d( parseUpLo(uplo), toMatrix_d(MatrixA),
                 toMatrix_d(MatrixB), REAL(div) );
  UNPROTECT(1);
  return div;
}

SEXP logDetDivDist_d( SEXP uplo, SEXP MatrixA, SEXP MatrixB){
  SEXP div=PROTECT( allocVector(REALSXP,1));
  ElLogDetDivDist_d( parseUpLo(uplo), toDistMatrix_d(MatrixA),
                     toDistMatrix_d(MatrixB), REAL(div) );
  UNPROTECT(1);
  return div;
}

