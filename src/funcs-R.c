#include "R-El.h"

SEXP inverse_d( SEXP RptrA){
  ElInverse_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP inverse_z( SEXP RptrA){
  ElInverse_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP inverseDist_d( SEXP RptrA){
  ElInverseDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP inverseDist_z( SEXP RptrA){
  ElInverseDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP inverseAfterLUPartialPiv_d( SEXP RptrA, SEXP Rptrp){
  ElInverseAfterLUPartialPiv_d( toMatrix_d(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP inverseAfterLUPartialPiv_z( SEXP RptrA, SEXP Rptrp){
  ElInverseAfterLUPartialPiv_z( toMatrix_z(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP inverseAfterLUPartialPivDist_d( SEXP RptrA, SEXP Rptrp){
  ElInverseAfterLUPartialPivDist_d( toDistMatrix_d(RptrA),
				    toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP inverseAfterLUPartialPivDist_z( SEXP RptrA, SEXP Rptrp){
  ElInverseAfterLUPartialPivDist_z( toDistMatrix_z(RptrA),
				    toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP hPDInverse_d( SEXP uplo, SEXP RptrA){
  ElHPDInverse_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPDInverse_z( SEXP uplo, SEXP RptrA){
  ElHPDInverse_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}
SEXP hPDInverseDist_d( SEXP uplo, SEXP RptrA){
  ElHPDInverseDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPDInverseDist_z( SEXP uplo, SEXP RptrA){
  ElHPDInverseDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianInverse_z( SEXP uplo, SEXP RptrA){
  ElHermitianInverse_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianInverseDist_z( SEXP uplo, SEXP RptrA){
  ElHermitianInverseDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP symmetricInverse_d( SEXP uplo, SEXP RptrA){
  ElSymmetricInverse_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP symmetricInverse_z( SEXP uplo, SEXP RptrA){
  ElSymmetricInverse_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP symmetricInverseDist_d( SEXP uplo, SEXP RptrA){
  ElSymmetricInverseDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP symmetricInverseDist_z( SEXP uplo, SEXP RptrA){
  ElSymmetricInverseDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP triangularInverse_d( SEXP uplo, SEXP unitDiag,  SEXP RptrA){
  ElTriangularInverse_d( parseUpLo(uplo), parseUnit(unitDiag),
			 toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP triangularInverse_z( SEXP uplo, SEXP unitDiag,  SEXP RptrA){
  ElTriangularInverse_z( parseUpLo(uplo), parseUnit(unitDiag),
			 toMatrix_z(RptrA) );
  return R_NilValue;
}


SEXP triangularInverseDist_d( SEXP uplo, SEXP unitDiag,  SEXP RptrA){
  ElTriangularInverseDist_d( parseUpLo(uplo), parseUnit(unitDiag),
			     toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP triangularInverseDist_z( SEXP uplo, SEXP unitDiag,  SEXP RptrA){
  ElTriangularInverseDist_z( parseUpLo(uplo), parseUnit(unitDiag),
			     toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP pseudoinverse_d( SEXP RptrA){
  ElPseudoinverse_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP pseudoinverse_z( SEXP RptrA){
  ElPseudoinverse_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP pseudoinverseDist_d( SEXP RptrA){
  ElPseudoinverseDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP pseudoinverseDist_z( SEXP RptrA){
  ElPseudoinverseDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}


SEXP hermitianPseudoinverse_d( SEXP uplo, SEXP RptrA){
  ElHermitianPseudoinverse_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianPseudoinverse_z( SEXP uplo, SEXP RptrA){
  ElHermitianPseudoinverse_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianPseudoinverseDist_d( SEXP uplo, SEXP RptrA){
  ElHermitianPseudoinverseDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianPseudoinverseDist_z( SEXP uplo, SEXP RptrA){
  ElHermitianPseudoinverseDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP sign_d( SEXP RptrA){
  ElSign_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP sign_z( SEXP RptrA){
  ElSign_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP signDist_d( SEXP RptrA){
  ElSignDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP signDist_z( SEXP RptrA){
  ElSignDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP signDecomp_d( SEXP RptrA, SEXP RptrN){
  ElSignDecomp_d( toMatrix_d(RptrA), toMatrix_d(RptrN) );
  return R_NilValue;
}

SEXP signDecomp_z( SEXP RptrA, SEXP RptrN){
  ElSignDecomp_z( toMatrix_z(RptrA), toMatrix_z(RptrN) );
  return R_NilValue;
}

SEXP signDecompDist_d( SEXP RptrA, SEXP RptrN){
  ElSignDecompDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrN) );
  return R_NilValue;
}

SEXP signDecompDist_z( SEXP RptrA, SEXP RptrN){
  ElSignDecompDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrN) );
  return R_NilValue;
}

SEXP hermitianSign_d( SEXP uplo, SEXP RptrA){
  ElHermitianSign_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianSign_z( SEXP uplo, SEXP RptrA){
  ElHermitianSign_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianSignDist_d( SEXP uplo, SEXP RptrA){
  ElHermitianSignDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianSignDist_z( SEXP uplo, SEXP RptrA){
  ElHermitianSignDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianSignDecomp_d( SEXP uplo, SEXP RptrA, SEXP RptrN){
  ElHermitianSignDecomp_d( parseUpLo(uplo), toMatrix_d(RptrA),
			 toMatrix_d(RptrN) );
  return R_NilValue;
}

SEXP hermitianSignDecomp_z( SEXP uplo, SEXP RptrA, SEXP RptrN){
  ElHermitianSignDecomp_z( parseUpLo(uplo), toMatrix_z(RptrA),
			 toMatrix_z(RptrN) );
  return R_NilValue;
}

SEXP hermitianSignDecompDist_d( SEXP uplo, SEXP RptrA, SEXP RptrN){
  ElHermitianSignDecompDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
			 toDistMatrix_d(RptrN) );
  return R_NilValue;
}

SEXP hermitianSignDecompDist_z( SEXP uplo, SEXP RptrA, SEXP RptrN){
  ElHermitianSignDecompDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA),
			 toDistMatrix_z(RptrN) );
  return R_NilValue;
}

SEXP squareRoot_d( SEXP RptrA){
  ElSquareRoot_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP squareRoot_z( SEXP RptrA){
  ElSquareRoot_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP squareRootDist_d( SEXP RptrA){
  ElSquareRootDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP squareRootDist_z( SEXP RptrA){
  ElSquareRootDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hPSDSquareRoot_d( SEXP uplo, SEXP RptrA){
  ElHPSDSquareRoot_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPSDSquareRoot_z( SEXP uplo, SEXP RptrA){
  ElHPSDSquareRoot_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hPSDSquareRootDist_d( SEXP uplo, SEXP RptrA){
  ElHPSDSquareRootDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPSDSquareRootDist_z( SEXP uplo, SEXP RptrA){
  ElHPSDSquareRootDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}
