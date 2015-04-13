#include "R-El.h"

/* Least Squares
 */

SEXP leastSquares_d( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrX ){
  ElLeastSquares_d( parseOrientation(orientation), toMatrix_d(RptrA),
                        toMatrix_d(RptrB), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP leastSquares_z( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrX ){
  ElLeastSquares_z( parseOrientation(orientation), toMatrix_z(RptrA),
                        toMatrix_z(RptrB), toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP leastSquaresDist_d( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrX ){
  ElLeastSquaresDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
                        toDistMatrix_d(RptrB), toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP leastSquaresDist_z( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrX ){
  ElLeastSquaresDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA),
                        toDistMatrix_z(RptrB), toDistMatrix_z(RptrX) );
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

SEXP ridge_z
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP gamma, SEXP RptrX, SEXP alg){
  ElRidge_z( parseOrientation(orientation), toMatrix_z(RptrA), toMatrix_z(RptrB),
	     toDouble(gamma), toMatrix_z(RptrX), parseRidgeAlg(alg) );
  return R_NilValue;
}

SEXP ridgeDist_d
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP gamma, SEXP RptrX, SEXP alg){
  ElRidgeDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA), 
		 toDistMatrix_d(RptrB), toDouble(gamma),
                 toDistMatrix_d(RptrX), parseRidgeAlg(alg) );
  return R_NilValue;
}

SEXP ridgeDist_z
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP gamma, SEXP RptrX, SEXP alg){
  ElRidgeDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA), 
		 toDistMatrix_z(RptrB), toDouble(gamma),
                 toDistMatrix_z(RptrX), parseRidgeAlg(alg) );
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

SEXP tikhonov_z
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrGamma, SEXP RptrX, SEXP alg){
  ElTikhonov_z( parseOrientation(orientation), toMatrix_z(RptrA), toMatrix_z(RptrB),
                toMatrix_z(RptrGamma), toMatrix_z(RptrX),
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

SEXP tikhonovDist_z
( SEXP orientation, SEXP RptrA, SEXP RptrB, SEXP RptrGamma, SEXP RptrX, SEXP alg){
  ElTikhonovDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA),
		    toDistMatrix_z(RptrB), toDistMatrix_z(RptrGamma),
		    toDistMatrix_z(RptrX), parseTikhonovAlg(alg) );
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

SEXP lSE_z( SEXP RptrA, SEXP RptrB, SEXP RptrC, SEXP RptrD, SEXP RptrX ){
  ElLSE_z( toMatrix_z(RptrA), toMatrix_z(RptrB),
           toMatrix_z(RptrC), toMatrix_z(RptrD),
           toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP lSEDist_d( SEXP RptrA, SEXP RptrB, SEXP RptrC, SEXP RptrD, SEXP RptrX ){
  ElLSEDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
               toDistMatrix_d(RptrC), toDistMatrix_d(RptrD),
               toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP lSEDist_z( SEXP RptrA, SEXP RptrB, SEXP RptrC, SEXP RptrD, SEXP RptrX ){
  ElLSEDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
               toDistMatrix_z(RptrC), toDistMatrix_z(RptrD),
               toDistMatrix_z(RptrX) );
  return R_NilValue;
}

/* General Linear Model
 */

SEXP gLM_d( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrX, SEXP RptrY ){
  ElGLM_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toMatrix_d(RptrD),
           toMatrix_d(RptrX), toMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP gLM_z( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrX, SEXP RptrY ){
  ElGLM_z( toMatrix_z(RptrA), toMatrix_z(RptrB), toMatrix_z(RptrD),
           toMatrix_z(RptrX), toMatrix_z(RptrY) );
  return R_NilValue;
}

SEXP gLMDist_d( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrX, SEXP RptrY ){
  ElGLMDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
               toDistMatrix_d(RptrD), toDistMatrix_d(RptrX),
	       toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP gLMDist_z( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrX, SEXP RptrY ){
  ElGLMDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
               toDistMatrix_z(RptrD), toDistMatrix_z(RptrX),
	       toDistMatrix_z(RptrY) );
  return R_NilValue;
}






