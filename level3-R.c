#include "R-El.h"

ElGemmAlgorithm parseGemmAlgo(SEXP algo){
  char *text = (char*)toChar_p(algo);
  if (strcmp("EL_GEMM_DEFAULT", text) == 0) return EL_GEMM_DEFAULT;
  if (strcmp("EL_GEMM_SUMMA_A", text) == 0) return EL_GEMM_SUMMA_A;
  if (strcmp("EL_GEMM_SUMMA_B", text) == 0) return EL_GEMM_SUMMA_B;
  if (strcmp("EL_GEMM_SUMMA_C", text) == 0) return EL_GEMM_SUMMA_C;
  if (strcmp("EL_GEMM_SUMMA_DOT", text) == 0) return EL_GEMM_SUMMA_DOT;
  if (strcmp("EL_GEMM_CANNON", text) == 0) return EL_GEMM_CANNON; 
  return EL_GEMM_DEFAULT;
}

SEXP gemm_d
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemm_d( parseOrientation(orientationA), parseOrientation(orientationB),
            toDouble(alpha), toMatrix_d(RptrA), toMatrix_d(RptrB), 
            toDouble(beta), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP gemmDist_d
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemmDist_d( parseOrientation(orientationA), parseOrientation(orientationB),
                toDouble(alpha), toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                toDouble(beta), toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP gemmXDist_d
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC, SEXP algo){
  ElGemmXDist_d( parseOrientation(orientationA), parseOrientation(orientationB),
                toDouble(alpha), toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                 toDouble(beta), toDistMatrix_d(RptrC), parseGemmAlgo(algo) );
  return R_NilValue;
}

/* Pending

Hemm
Herk
Her2k

*/

SEXP multiShiftQuasiTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrshifts,
 SEXP RptrB){
  ElMultiShiftQuasiTrsm_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                      toDouble(alpha), toMatrix_d(RptrA), toMatrix_d(Rptrshifts),
                      toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiShiftQuasiTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrshifts,
 SEXP RptrB){
  ElMultiShiftQuasiTrsmDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                          toDouble(alpha), toDistMatrix_d(RptrA), toDistMatrix_d(Rptrshifts),
                          toDistMatrix_d(RptrB) );
  return R_NilValue;
}


SEXP multiShiftTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrshifts,
 SEXP RptrB){
  ElMultiShiftTrsm_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                      toDouble(alpha), toMatrix_d(RptrA), toMatrix_d(Rptrshifts),
                      toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiShiftTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP Rptrshifts,
 SEXP RptrB){
  ElMultiShiftTrsmDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                          toDouble(alpha), toDistMatrix_d(RptrA), toDistMatrix_d(Rptrshifts),
                          toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP QuasiTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsm_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                      toDouble(alpha), toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP QuasiTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsmDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                          toDouble(alpha), toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP symm_d
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, SEXP RptrC){
  ElSymm_d( parseSide(side), parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(RptrB), toDouble(beta), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP symmDist_d
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, SEXP RptrC){
  ElSymmDist_d( parseSide(side), parseUpLo(uplo), toDouble(alpha), toDistMatrix_d(RptrA),
            toDistMatrix_d(RptrB), toDouble(beta), toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP syrk_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElSyrk_d(parseUpLo(uplo), parseOrientation(orientation),  toDouble(alpha),
           toMatrix_d(RptrA), toDouble(beta), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP syrkDist_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElSyrkDist_d( parseUpLo(uplo), parseOrientation(orientation), toDouble(alpha),
            toDistMatrix_d(RptrA), toDouble(beta), toDistMatrix_d(RptrC) );
  return R_NilValue;
}


SEXP syr2k_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, SEXP RptrC){
  ElSyr2k_d(parseUpLo(uplo), parseOrientation(orientation), toDouble(alpha),
            toMatrix_d(RptrA), toMatrix_d(RptrB), toDouble(beta),
            toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP syr2kDist_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, SEXP RptrC){
  ElSyr2kDist_d( parseUpLo(uplo), parseOrientation(orientation), toDouble(alpha),
                 toDistMatrix_d(RptrA), toDistMatrix_d(RptrA), toDouble(beta),
                 toDistMatrix_d(RptrC) );
  return R_NilValue;
}
