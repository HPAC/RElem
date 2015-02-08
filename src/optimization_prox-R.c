#include "R-El.h"

/* Clipping 
 */

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

/* Frobenius-norm proximal map
 */


SEXP frobeniusProx_d( SEXP MatrixA, SEXP rho){
  ElFrobeniusProx_d( toMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP frobeniusProxDist_d( SEXP MatrixA, SEXP rho){
  ElFrobeniusProxDist_d( toDistMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

/* Hinge loss proximal map
 */

SEXP hingeLossProx_d( SEXP MatrixA, SEXP rho){
  ElHingeLossProx_d( toMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP hingeLossProxDist_d( SEXP MatrixA, SEXP rho){
  ElHingeLossProxDist_d( toDistMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

/* Logistic proximal map
 */

SEXP logisticProx_d( SEXP MatrixA, SEXP rho){
  ElLogisticProx_d( toMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}

SEXP logisticProxDist_d( SEXP MatrixA, SEXP rho){
  ElLogisticProxDist_d( toDistMatrix_d(MatrixA), toDouble(rho) );
  return R_NilValue;
}


/* Singular value soft thresholding
 */

SEXP sVT_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSVT_d( toMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

SEXP sVTDist_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSVTDist_d( toDistMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

/* Soft Thresholding
 */

SEXP softThreshold_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSoftThreshold_d(toMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

SEXP softThresholdDist_d( SEXP MatrixA, SEXP rho, SEXP relative){
  ElSoftThresholdDist_d(toDistMatrix_d(MatrixA), toDouble(rho), toBool(relative) );
  return R_NilValue;
}

