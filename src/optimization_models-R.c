#include "R-El.h"

/* Basis Pursuit
 */

SEXP bP_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  ElBP_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	 toMatrix_d(Matrixx));
  return R_NilValue;
}

SEXP bPDist_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  ElBPDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
	     toDistMatrix_d(Matrixx));
  return R_NilValue;
}

/* Basis Pursuit expert (pending) */


/* Chebyshev point
 */

SEXP cP_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  ElCP_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	 toMatrix_d(Matrixx));
  return R_NilValue;
}


SEXP cPDist_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  ElCPDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
	     toDistMatrix_d(Matrixx));
  return R_NilValue;
}

/* Expert Version Pending */

/* Dantzig selector
 */

SEXP dS_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  ElDS_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	 toDouble(lambda), toMatrix_d(Matrixx));
  return R_NilValue;
}


SEXP dSDist_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  ElDSDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
	     toDouble(lambda), toDistMatrix_d(Matrixx));
  return R_NilValue;
}

/* Expert version pending */

/* Least Absolute Value regression
 */

SEXP lAV_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  ElLAV_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	  toMatrix_d(Matrixx));
  return R_NilValue;
}


SEXP lAVDist_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixx){
  ElLAVDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
	      toDistMatrix_d(Matrixx));
  return R_NilValue;
}

/* Expert version pending */


/* Model Fit (PENDING) */

/* Non-negative matrix factorization
 */

SEXP nMF_d( SEXP MatrixA, SEXP MatrixX, SEXP MatrixY ){
  ElNMF_d( toMatrix_d(MatrixA), toMatrix_d(MatrixX), toMatrix_d(MatrixY) );
  return R_NilValue;
}

SEXP nMFDist_d( SEXP MatrixA, SEXP MatrixX, SEXP MatrixY ){
  ElNMFDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(MatrixX),
              toDistMatrix_d(MatrixY) );
  return R_NilValue;
}

/* Non-negative least squares
 */

SEXP nNLS_d( SEXP MatrixA, SEXP MatrixY, SEXP MatrixZ ){
  ElNNLS_d( toMatrix_d(MatrixA), toMatrix_d(MatrixY),
	    toMatrix_d(MatrixZ) );
  return R_NilValue;
}

SEXP nNLSDist_d( SEXP MatrixA, SEXP MatrixY, SEXP MatrixZ ){
  ElNNLSDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(MatrixY),
		toDistMatrix_d(MatrixZ));
  return R_NilValue;
}

/* Expert version pending */


/* Basis pursuit denoising */

SEXP bPDN_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  ElBPDN_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	   toDouble(lambda), toMatrix_d(Matrixx));
  return R_NilValue;
}


SEXP bPDNDist_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  ElBPDNDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
	       toDouble(lambda), toDistMatrix_d(Matrixx));
  return R_NilValue;
}
/* Expert version Pending */


/* Elastic net
 */

SEXP eN_d
( SEXP MatrixA, SEXP Matrixb, SEXP lambda1, SEXP lambda2, SEXP Matrixx){
  ElEN_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	 toDouble(lambda1), toDouble(lambda2),
	 toMatrix_d(Matrixx));
  return R_NilValue;
}


SEXP eNDist_d
( SEXP MatrixA, SEXP Matrixb, SEXP lambda1, SEXP lambda2, SEXP Matrixx){
  ElENDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
	     toDouble(lambda1), toDouble(lambda2),
	     toDistMatrix_d(Matrixx));
  return R_NilValue;
}

/* Expert versions pending */

/* Robust Principal component analysis */

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

/* Support Vector Machine
 */

SEXP sVM_d( SEXP MatrixA, SEXP Matrixd, SEXP lambda, SEXP Matrixz){
  ElSVM_d( toMatrix_d(MatrixA), toMatrix_d(Matrixd),
           toDouble(lambda), toMatrix_d(Matrixz) );
  return R_NilValue;
}

SEXP sVMDist_d( SEXP MatrixA, SEXP Matrixd, SEXP lambda, SEXP Matrixz){
  ElSVMDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixd),
               toDouble(lambda), toDistMatrix_d(Matrixz) );
  return R_NilValue;
}



/* Total variation denoising
 */

SEXP tV_d( SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  ElTV_d(toMatrix_d(Matrixb), toDouble(lambda),
	 toMatrix_d(Matrixx));
  return R_NilValue;
}


SEXP tVDist_d( SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  ElTVDist_d(toDistMatrix_d(Matrixb), toDouble(lambda),
	     toDistMatrix_d(Matrixx));
  return R_NilValue;
}

/* Expert version pending */
