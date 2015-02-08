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

/* ADMM  */

SEXP bPADMM_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElBPADMM_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	     toMatrix_d(Matrixz), INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
}

SEXP bPADMMDist_d( SEXP MatrixA, SEXP Matrixb, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElBPADMMDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
		 toDistMatrix_d(Matrixz), INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
}

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

/* Logistic Regression
 */


SEXP logisticRegression_d
( SEXP MatrixQ, SEXP Matrixq, SEXP Matrixz, SEXP gamma, SEXP penalty){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLogisticRegression_d( toMatrix_d(MatrixQ), toMatrix_d(Matrixq),
                          toMatrix_d(Matrixz), toDouble(gamma),
                          parseRegularization(penalty), INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
} 

SEXP logisticRegressionDist_d
( SEXP MatrixQ, SEXP Matrixq, SEXP Matrixz, SEXP gamma, SEXP penalty){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElLogisticRegressionDist_d( toDistMatrix_d(MatrixQ), toDistMatrix_d(Matrixq),
                              toDistMatrix_d(Matrixz), toDouble(gamma),
                              parseRegularization(penalty), INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
} 

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

/* ADMM */

SEXP nNLSADMM_d( SEXP MatrixA, SEXP MatrixB, SEXP MatrixX ){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElNNLSADMM_d( toMatrix_d(MatrixA), toMatrix_d(MatrixB),
		toMatrix_d(MatrixX), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP nNLSADMMDist_d( SEXP MatrixA, SEXP MatrixB, SEXP MatrixX ){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElNNLSADMMDist_d( toDistMatrix_d(MatrixA), toDistMatrix_d(MatrixB),
		    toDistMatrix_d(MatrixX), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

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

/* ADMM */

SEXP bPDNADMM_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElBPDNADMM_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	       toDouble(lambda), toMatrix_d(Matrixx),
	       INTEGER(numIts));
  UNPROTECT(1);
  return numIts;
}


SEXP bPDNADMMDist_d( SEXP MatrixA, SEXP Matrixb, SEXP lambda, SEXP Matrixx){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElBPDNADMMDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
		   toDouble(lambda), toDistMatrix_d(Matrixx),
		   INTEGER(numIts));
  UNPROTECT(1);
  return numIts;

}

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


/* ADDM */
SEXP sVMADMM_d( SEXP MatrixG, SEXP Matrixq, SEXP gamma, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElSVMADMM_d( toMatrix_d(MatrixG), toMatrix_d(Matrixq),
	       toDouble(gamma), toMatrix_d(Matrixz), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
}

SEXP sVMADMMDist_d( SEXP MatrixG, SEXP Matrixq, SEXP gamma, SEXP Matrixz){
  SEXP numIts = PROTECT( allocVector(INTSXP,1) );
  ElSVMADMMDist_d( toDistMatrix_d(MatrixG), toDistMatrix_d(Matrixq),
		   toDouble(gamma), toDistMatrix_d(Matrixz), INTEGER(numIts) );
  UNPROTECT(1);
  return numIts;
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
