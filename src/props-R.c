#include "R-El.h"

SEXP condition_d(SEXP RptrA, SEXP normType){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElCondition_d( toMatrix_d(RptrA), parseNorm(normType), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP condition_z(SEXP RptrA, SEXP normType){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElCondition_z( toMatrix_z(RptrA), parseNorm(normType), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP conditionDist_d(SEXP RptrA, SEXP normType){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElConditionDist_d( toDistMatrix_d(RptrA), parseNorm(normType), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP conditionDist_z(SEXP RptrA, SEXP normType){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElConditionDist_z( toDistMatrix_z(RptrA), parseNorm(normType), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusCondition_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusCondition_d( toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusCondition_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusCondition_z( toMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusConditionDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusConditionDist_d( toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusConditionDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusConditionDist_z( toDistMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP infinityCondition_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityCondition_d( toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP infinityCondition_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityCondition_z( toMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP infinityConditionDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityConditionDist_d( toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP infinityConditionDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityConditionDist_z( toDistMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP maxCondition_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxCondition_d( toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP maxCondition_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxCondition_z( toMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP maxConditionDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxConditionDist_d( toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP maxConditionDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxConditionDist_z( toDistMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP oneCondition_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElOneCondition_d( toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP oneCondition_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElOneCondition_z( toMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP oneConditionDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElOneConditionDist_d( toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP oneConditionDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElOneConditionDist_z( toDistMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP twoCondition_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElTwoCondition_d( toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP twoCondition_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElTwoCondition_z( toMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP twoConditionDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElTwoConditionDist_d( toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP Determinant_d( SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElDeterminant_d( toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP Determinant_z( SEXP RptrA){
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  complex_double val;
  ElDeterminant_z( toMatrix_z(RptrA), &val);
  COMPLEX(ans)[0].r = creal(val);
  COMPLEX(ans)[0].i = cimag(val);
  UNPROTECT(1);
  return ans;
}

SEXP DeterminantDist_d( SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElDeterminantDist_d( toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP DeterminantDist_z( SEXP RptrA){
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  complex_double val;
  ElDeterminantDist_z( toDistMatrix_z(RptrA), &val);
  COMPLEX(ans)[0].r = creal(val);
  COMPLEX(ans)[0].i = cimag(val);
  UNPROTECT(1);
  return ans;
}

SEXP HPDDeterminant_d( SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElHPDDeterminant_d( parseUpLo(uplo), toMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP HPDDeterminant_z( SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElHPDDeterminant_z( parseUpLo(uplo), toMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP HPDDeterminantDist_d( SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElHPDDeterminantDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP HPDDeterminantDist_z( SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElHPDDeterminantDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP twoConditionDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElTwoConditionDist_z( toDistMatrix_z(RptrA), REAL(ans));
  UNPROTECT(1);
  return ans;
}
	      
SEXP frobeniusNorm_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusNorm_d( toMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusNorm_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusNorm_z( toMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusNormDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusNormDist_d( toDistMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP frobeniusNormDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElFrobeniusNormDist_z( toDistMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricFrobeniusNorm_d(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricFrobeniusNorm_d( parseUpLo(uplo), toMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricFrobeniusNorm_z(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricFrobeniusNorm_z( parseUpLo(uplo), toMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricFrobeniusNormDist_d(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricFrobeniusNormDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                                  REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricFrobeniusNormDist_z(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricFrobeniusNormDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA),
                                  REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP infinityNorm_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityNorm_d( toMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}


SEXP infinityNorm_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityNorm_z( toMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP infinityNormDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityNormDist_d( toDistMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP infinityNormDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElInfinityNormDist_z( toDistMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricInfinityNorm_d(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricInfinityNorm_d( parseUpLo(uplo), toMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricInfinityNorm_z(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricInfinityNorm_z( parseUpLo(uplo), toMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricInfinityNormDist_d(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricInfinityNormDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                                 REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP symmetricInfinityNormDist_z(SEXP uplo, SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElSymmetricInfinityNormDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA),
                                 REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP maxNorm_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxNorm_d( toMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}


SEXP maxNorm_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxNorm_z( toMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP maxNormDist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxNormDist_d( toDistMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP maxNormDist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMaxNormDist_z( toDistMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}
