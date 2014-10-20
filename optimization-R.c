#include "R-El.h"

SEXP basisPursuit_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElBasisPursuit_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
                   toMatrix_d(Matrixx), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP basisPursuitDist_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElBasisPursuitDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
                       toDistMatrix_d(Matrixx), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP lasso_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLasso_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb), toDouble(lambda),
            toMatrix_d(Matrixz), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP lassoDist_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLassoDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
                 toDouble(lambda), toDistMatrix_d(Matrixz), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP linearProgram_d
( SEXP MatrixA, SEXP Matrixb, SEXP Matrixc, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLinearProgram_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
                    toMatrix_d(Matrixc), toMatrix_d(Matrixz),
                    INTEGER(numIts) );
 UNPROTECT(1);
  return numIts;
} 

SEXP linearProgramDist_d
( SEXP MatrixA, SEXP Matrixb, SEXP Matrixc, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLinearProgramDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
                        toDistMatrix_d(Matrixc), toDistMatrix_d(Matrixz),
                        INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP logisticRegression_d
( SEXP MatrixA, SEXP Matrixq, SEXP Matrixz, SEXP gamma, SEXP penalty){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLogisticRegression_d( toMatrix_d(MatrixA), toMatrix_d(Matrixq),
                          toMatrix_d(Matrixz), toDouble(gamma),
                          parseRegularization(penalty), INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
} 

SEXP logisticRegressionDist_d
( SEXP MatrixA, SEXP Matrixq, SEXP Matrixz, SEXP gamma, SEXP penalty){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLogisticRegressionDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixq),
                              toDistMatrix_d(Matrixz), toDouble(gamma),
                              parseRegularization(penalty), INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
} 

/* pending model fit */

SEXP nMF_d( SEXP MatrixA, SEXP MatrixX, SEXP MatrixY ){
  ElNMF_d( toMatrix_d(MatrixA), toMatrix_d(MatrixX), toMatrix_d(MatrixY) );
  return R_NilValue;
}

SEXP nMFDist_d( SEXP MatrixA, SEXP MatrixX, SEXP MatrixY ){
  ElNMFDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(MatrixX),
              toDistMatrix_d(MatrixY) );
  return R_NilValue;
}

SEXP nonNegativeLeastSquares_d( SEXP MatrixA, SEXP MatrixY, SEXP MatrixZ ){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElNonNegativeLeastSquares_d( toMatrix_d(MatrixA), toMatrix_d(MatrixY),
                               toMatrix_d(MatrixZ), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP nonNegativeLeastSquaresDist_d( SEXP MatrixA, SEXP MatrixY, SEXP MatrixZ ){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElNonNegativeLeastSquaresDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(MatrixY),
                                   toDistMatrix_d(MatrixZ), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP rPCA_d( SEXP MatrixM, SEXP MatrixL, SEXP MatrixS){
  ElRPCA_d( toMatrix_d(MatrixM), toMatrix_d(MatrixL),
            toMatrix_d(MatrixS) );
  return R_NilValue;
}

SEXP rPCADist_d( SEXP MatrixM, SEXP MatrixL, SEXP MatrixS){
  ElRPCADist_d( toDistMatrix_d(MatrixM), toDistMatrix_d(MatrixL),
                toDistMatrix_d(MatrixS) );
  return R_NilValue;
}

SEXP sVM_d( SEXP MatrixG, SEXP Matrixq, SEXP Matrixz, SEXP gamma){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElSVM_d( toMatrix_d(MatrixG), toMatrix_d(Matrixq),
           toMatrix_d(Matrixz), toDouble(gamma), INTEGER(numIts) );
  UNPROTECT(1);
  return R_NilValue;
}

SEXP sVMDist_d( SEXP MatrixG, SEXP Matrixq, SEXP Matrixz, SEXP gamma){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElSVMDist_d( toDistMatrix_d(MatrixG), toDistMatrix_d(Matrixq),
               toDistMatrix_d(Matrixz), toDouble(gamma), INTEGER(numIts) );
  UNPROTECT(1);
  return R_NilValue;
}

SEXP lowerClip_d( SEXP MatrixX, SEXP lowerbound){
  ElLowerClip_d( toMatrix_d(MatrixX), toDouble(lowerbound) );
  return R_NilValue;
}

SEXP lowerClipDist_d( SEXP MatrixX, SEXP lowerbound){
  ElLowerClipDist_d( toDistMatrix_d(MatrixX), toDouble(lowerbound) );
  return R_NilValue;
}

SEXP upperClip_d( SEXP MatrixX, SEXP upperbound){
  ElUpperClip_d( toMatrix_d(MatrixX), toDouble(upperbound) );
  return R_NilValue;
}

SEXP upperClipDist_d( SEXP MatrixX, SEXP upperbound){
  ElUpperClipDist_d( toDistMatrix_d(MatrixX), toDouble(upperbound) );
  return R_NilValue;
}

SEXP clip_d( SEXP MatrixX, SEXP lowerbound, SEXP upperbound){
  ElClip_d( toMatrix_d(MatrixX), toDouble(lowerbound), toDouble(upperbound) );
  return R_NilValue;
}

SEXP clipDist_d( SEXP MatrixX, SEXP lowerbound, SEXP upperbound){
  ElClipDist_d( toDistMatrix_d(MatrixX), toDouble(lowerbound), toDouble(upperbound) );
  return R_NilValue;
}

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

SEXP covariance_d( SEXP MatrixD, SEXP MatrixS ){
  ElCovariance_d( toMatrix_d(MatrixD), toMatrix_d(MatrixS) );
  return R_NilValue;
}

SEXP covarianceDist_d( SEXP MatrixD, SEXP MatrixS ){
  ElCovarianceDist_d( toDistMatrix_d(MatrixD), toDistMatrix_d(MatrixS) );
  return R_NilValue;
}

SEXP frobeniusProx_d( SEXP MatrixA, SEXP rho){
  ElFrobeniusProx_d( toMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP frobeniusProxDist_d( SEXP MatrixA, SEXP rho){
  ElFrobeniusProxDist_d( toDistMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP hingeLossProx_d( SEXP MatrixA, SEXP rho){
  ElHingeLossProx_d( toMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP hingeLossProxDist_d( SEXP MatrixA, SEXP rho){
  ElHingeLossProxDist_d( toDistMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP logBarrier_d( SEXP uplo, SEXP MatrixA){
  SEXP barrier=PROTECT( allocVector(REALSXP,1));
  ElLogBarrier_d( parseUpLo(uplo), toMatrix_d(MatrixA),
                  REAL(barrier) );
  return R_NilValue;
}

SEXP logBarrierDist_d( SEXP uplo, SEXP MatrixA){
  SEXP barrier=PROTECT( allocVector(REALSXP,1));
  ElLogBarrierDist_d( parseUpLo(uplo), toDistMatrix_d(MatrixA),
                      REAL(barrier) );
  return R_NilValue;
}

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

SEXP logisticProx_d( SEXP MatrixA, SEXP rho){
  ElLogisticProx_d( toMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP logisticProxDist_d( SEXP MatrixA, SEXP rho){
  ElLogisticProxDist_d( toDistMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP sVT_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSVT_d( toMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

SEXP sVTDist_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSVTDist_d( toDistMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

SEXP softThreshold_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSoftThreshold_d(toMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

SEXP softThresholdDist_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSoftThresholdDist_d(toDistMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

