#include "R-El.h"

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
