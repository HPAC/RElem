#include "R-El.h"

/* Linear solve
 */

SEXP linearSolve_d( SEXP RptrA, SEXP RptrB){
  ElLinearSolve_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP linearSolve_z( SEXP RptrA, SEXP RptrB){
  ElLinearSolve_z( toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP linearSolveDist_d( SEXP RptrA, SEXP RptrB){
  ElLinearSolveDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP linearSolveDist_z( SEXP RptrA, SEXP RptrB){
  ElLinearSolveDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

/* Symmetric Solve
 */

SEXP symmetricSolve_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSymmetricSolve_d( parseUpLo(uplo), parseOrientation(orientation),
                      toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP symmetricSolve_z( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSymmetricSolve_z( parseUpLo(uplo), parseOrientation(orientation),
                      toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP symmetricSolveDist_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSymmetricSolveDist_d( parseUpLo(uplo), parseOrientation(orientation),
                          toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP symmetricSolveDist_z
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSymmetricSolveDist_z( parseUpLo(uplo), parseOrientation(orientation),
                          toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
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

SEXP hPDSolve_z( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHPDSolve_z( parseUpLo(uplo), parseOrientation(orientation),
                toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP hPDSolveDist_d( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHPDSolveDist_d( parseUpLo(uplo), parseOrientation(orientation),
                    toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP hPDSolveDist_z( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElHPDSolveDist_z( parseUpLo(uplo), parseOrientation(orientation),
                    toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
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

SEXP multiShiftHessSolve_z
( SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrH, SEXP RptrShifts,
  SEXP RptrX ){
  ElMultiShiftHessSolve_z( parseUpLo(uplo), parseOrientation(orientation),
                           toDouble(alpha), toMatrix_z(RptrH),
                           toMatrix_z(RptrShifts), toMatrix_z(RptrX) );
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

SEXP multiShiftHessSolveDist_z
( SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrH, SEXP RptrShifts,
  SEXP RptrX ){
  ElMultiShiftHessSolveDist_z( parseUpLo(uplo), parseOrientation(orientation),
                               toDouble(alpha), toDistMatrix_z(RptrH),
                               toDistMatrix_z(RptrShifts),
                               toDistMatrix_z(RptrX) );
  return R_NilValue;
}
