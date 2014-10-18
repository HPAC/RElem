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
