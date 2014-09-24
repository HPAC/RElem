#include "R-El.h"

/* Gaussian Elimination
 */

SEXP gaussianElimination_d( SEXP RptrA, SEXP RptrB){
  ElGaussianElimination_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP gaussianEliminationDist_d( SEXP RptrA, SEXP RptrB){
  ElGaussianEliminationDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

/* General Linear Model
 */

SEXP gLM_d( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrY ){
  ElGLM_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toMatrix_d(RptrD),
           toMatrix_d(RptrY) );
  return R_NilValue;
}


SEXP gLMDist_d( SEXP RptrA, SEXP RptrB, SEXP RptrD, SEXP RptrY ){
  ElGLMDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
               toDistMatrix_d(RptrD), toDistMatrix_d(RptrY) );
  return R_NilValue;
}

/* Hermitian Solve
 */

SEXP hermitianSolve_z( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHermitianSolve_z( parseUpLo(uplo), parseOrientation(orientation),
                      toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP hermitianSolveDist_z
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHermitianSolveDist_z( parseUpLo(uplo), parseOrientation(orientation),
               toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

/* HDP Solve
 */

SEXP hPDSolve_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHPDSolve_d( parseUpLo(uplo), parseOrientation(orientation),
                toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP hPDSolveDist_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHPDSolveDist_d( parseUpLo(uplo), parseOrientation(orientation),
                    toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
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

/* Multi-shift Hessenberg solve
 */

SEXP multiShiftHessSolve_d
( SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrH, SEXP RptrShifts,
  SEXP RptrX ){
  ElMultiShiftHessSolve_d( parseUpLo(uplo), parseOrientation(orientation),
                           toDouble(alpha), toMatrix_d(RptrH),
                           toMatrix_d(RptrShifts), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP multiShiftHessSolveDist_d
( SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrH, SEXP RptrShifts,
  SEXP RptrX ){
  ElMultiShiftHessSolveDist_d( parseUpLo(uplo), parseOrientation(orientation),
                               toDouble(alpha), toDistMatrix_d(RptrH),
                               toDistMatrix_d(RptrShifts),
                               toDistMatrix_d(RptrX) );
  return R_NilValue;
}

/* Ridge Regression
 */

SEXP ridge_d( SEXP RptrA, SEXP RptrB, SEXP alpha, SEXP RptrX, SEXP alg){
  ElRidge_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toDouble(alpha),
                 toMatrix_d(RptrX), parseRidgeAlg(alg) );
  return R_NilValue;
}

SEXP ridgeDist_d( SEXP RptrA, SEXP RptrB, SEXP alpha, SEXP RptrX, SEXP alg){
  ElRidgeDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toDouble(alpha),
                 toDistMatrix_d(RptrX), parseRidgeAlg(alg) );
  return R_NilValue;
}

/* Symmetric Solve
 */

SEXP symmetricSolve_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSymmetricSolve_d( parseUpLo(uplo), parseOrientation(orientation),
           toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP symmetricSolveDist_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSymmetricSolveDist_d( parseUpLo(uplo), parseOrientation(orientation),
               toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

/* Tikhonov Regularization
 */

SEXP tikhonov_d( SEXP RptrA, SEXP RptrB, SEXP RptrGamma, SEXP RptrX, SEXP alg){
  ElTikhonov_d( toMatrix_d(RptrA), toMatrix_d(RptrB),
                toMatrix_d(RptrGamma), toMatrix_d(RptrX),
                parseTikhonovAlg(alg) );
  return R_NilValue;
}

SEXP tikhonovDist_d
( SEXP RptrA, SEXP RptrB, SEXP RptrGamma, SEXP RptrX, SEXP alg){
  ElTikhonovDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
                    toDistMatrix_d(RptrGamma), toDistMatrix_d(RptrX),
                    parseTikhonovAlg(alg) );
  return R_NilValue;
}


