#include "R-El.h"

/* General Linear Model
 */

SEXP gLM_d( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrX, SEXP RptrY ){
  ElGLM_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toMatrix_d(RptrD),
           toMatrix_d(RptrX), toMatrix_d(RptrY) );
  return R_NilValue;
}


SEXP gLMDist_d( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrX, SEXP RptrY ){
  ElGLMDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
               toDistMatrix_d(RptrD), toDistMatrix_d(RptrX),
	       toDistMatrix_d(RptrY) );
  return R_NilValue;
}

/* Least Squares
 */

SEXP leastSquares_d( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrX ){
  ElLeastSquares_d( parseOrientation(orientation), toMatrix_d(RptrA),
                        toMatrix_d(RptrB), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP leastSquaresDist_d( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrX ){
  ElLeastSquaresDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
                        toDistMatrix_d(RptrB), toDistMatrix_d(RptrX) );
  return R_NilValue;
}

/* Equality contrained Least Squares
 */

SEXP lSE_d( SEXP RptrA, SEXP RptrB, SEXP RptrC, SEXP RptrD, SEXP RptrX ){
  ElLSE_d( toMatrix_d(RptrA), toMatrix_d(RptrB),
           toMatrix_d(RptrC), toMatrix_d(RptrD),
           toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP lSEDist_d( SEXP RptrA, SEXP RptrB, SEXP RptrC, SEXP RptrD, SEXP RptrX ){
  ElLSEDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
               toDistMatrix_d(RptrC), toDistMatrix_d(RptrD),
               toDistMatrix_d(RptrX) );
  return R_NilValue;
}


/* Ridge Regression
 */

SEXP ridge_d
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP gamma, SEXP RptrX, SEXP alg){
  ElRidge_d( parseOrientation(orientation), toMatrix_d(RptrA), toMatrix_d(RptrB),
	     toDouble(gamma), toMatrix_d(RptrX), parseRidgeAlg(alg) );
  return R_NilValue;
}

SEXP ridgeDist_d
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP gamma, SEXP RptrX, SEXP alg){
  ElRidgeDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA), 
		 toDistMatrix_d(RptrB), toDouble(gamma),
                 toDistMatrix_d(RptrX), parseRidgeAlg(alg) );
  return R_NilValue;
}


/* Tikhonov Regularization
 */

SEXP tikhonov_d
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrGamma, SEXP RptrX, SEXP alg){
  ElTikhonov_d( parseOrientation(orientation), toMatrix_d(RptrA), toMatrix_d(RptrB),
                toMatrix_d(RptrGamma), toMatrix_d(RptrX),
                parseTikhonovAlg(alg) );
  return R_NilValue;
}

SEXP tikhonovDist_d
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrGamma, SEXP RptrX, SEXP alg){
  ElTikhonovDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
		    toDistMatrix_d(RptrB), toDistMatrix_d(RptrGamma),
		    toDistMatrix_d(RptrX), parseTikhonovAlg(alg) );
  return R_NilValue;
}


