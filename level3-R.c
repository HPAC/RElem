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
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftQuasiTrsm_d( parseSide(side), parseUpLo(uplo),
                           parseOrientation(orientation),toDouble(alpha),
                           toMatrix_d(RptrA), toMatrix_d(Rptrshifts),
                           toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiShiftQuasiTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftQuasiTrsmDist_d( parseSide(side), parseUpLo(uplo), 
                               parseOrientation(orientation),
                               toDouble(alpha), toDistMatrix_d(RptrA),
                               toDistMatrix_d(Rptrshifts),
                               toDistMatrix_d(RptrB) );
  return R_NilValue;
}


SEXP multiShiftTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, 
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftTrsm_d( parseSide(side), parseUpLo(uplo), 
                      parseOrientation(orientation), toDouble(alpha),
                      toMatrix_d(RptrA), toMatrix_d(Rptrshifts),
                      toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiShiftTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftTrsmDist_d( parseSide(side), parseUpLo(uplo), 
                          parseOrientation(orientation),toDouble(alpha),
                          toDistMatrix_d(RptrA), toDistMatrix_d(Rptrshifts),
                          toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP quasiTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsm_d( parseSide(side), parseUpLo(uplo),
                 parseOrientation(orientation), toDouble(alpha), 
                 toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP quasiTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsmDist_d( parseSide(side), parseUpLo(uplo), 
                     parseOrientation(orientation), toDouble(alpha), 
                     toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP symm_d
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElSymm_d( parseSide(side), parseUpLo(uplo), toDouble(alpha), 
            toMatrix_d(RptrA), toMatrix_d(RptrB), toDouble(beta), 
            toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP symmDist_d
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElSymmDist_d( parseSide(side), parseUpLo(uplo), toDouble(alpha), 
                toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toDouble(beta),
                toDistMatrix_d(RptrC) );
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
  ElSyrkDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                toDouble(alpha), toDistMatrix_d(RptrA), toDouble(beta),
                toDistMatrix_d(RptrC) );
  return R_NilValue;
}


SEXP syr2k_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, 
 SEXP RptrC){
  ElSyr2k_d(parseUpLo(uplo), parseOrientation(orientation), toDouble(alpha),
            toMatrix_d(RptrA), toMatrix_d(RptrB), toDouble(beta),
            toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP syr2kDist_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, 
 SEXP RptrC){
  ElSyr2kDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                 toDouble(alpha), toDistMatrix_d(RptrA), 
                 toDistMatrix_d(RptrA), toDouble(beta), 
                 toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP trdtrmm_d( SEXP uplo, SEXP RptrA){
  ElTrdtrmm_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trdtrmmDist_d( SEXP uplo, SEXP RptrA){
  ElTrdtrmmDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trdtrmmQuasi_d( SEXP uplo, SEXP RptrA, SEXP RptrdOff){
  ElTrdtrmmQuasi_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_d(RptrdOff) );
  return R_NilValue;
}

SEXP trdtrmmQuasiDist_d( SEXP uplo, SEXP RptrA, SEXP RptrdOff){
  ElTrdtrmmQuasiDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                        toDistMatrix_d(RptrdOff) );
  return R_NilValue;
}

SEXP trmm_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrmm_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation), 
            parseUnit(diag), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP trmmDist_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrmmDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
            parseUnit(diag), toDouble(alpha), toDistMatrix_d(RptrA),
            toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP trrk_d
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA,
  SEXP RptrB, SEXP beta, SEXP RptrC){
  ElTrrk_d( parseUpLo(uplo), parseOrientation(orientationA),
            parseOrientation(orientationB), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(RptrB), toDouble(beta), toMatrix_d(RptrC) ); 
  return R_NilValue;
}

SEXP trrkDist_d
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA,
  SEXP RptrB, SEXP beta, SEXP RptrC){
  ElTrrkDist_d( parseUpLo(uplo), parseOrientation(orientationA),
                parseOrientation(orientationB), toDouble(alpha),
                toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toDouble(beta),
                toDistMatrix_d(RptrC) ); 
  return R_NilValue;
}

/*
Trr2k not yet implemented for sequential
*/

SEXP trr2kDist_d
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP orientationC,
  SEXP orientationD, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP RptrC, SEXP RptrD,
  SEXP beta, SEXP RptrE ){
  ElTrr2kDist_d( parseUpLo(uplo), parseOrientation(orientationA), 
                 parseOrientation(orientationB), parseOrientation(orientationC),
                 parseOrientation(orientationD), toDouble(alpha), 
                 toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                 toDistMatrix_d(RptrC), toDistMatrix_d(RptrD), toDouble(beta), 
                 toDistMatrix_d(RptrE) );
  return R_NilValue;
}

SEXP trsm_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrsm_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
            parseUnit(diag), toDouble(alpha), toMatrix_d(RptrA),
            toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP trsmDist_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrsmDist_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                parseUnit(diag), toDouble(alpha), toDistMatrix_d(RptrA),
                toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP trstrm_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrstrm_d( parseSide(side), parseUpLo(uplo), parseOrientation(orientation), 
              parseUnit(diag), toDouble(alpha), toMatrix_d(RptrA),
              toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP trstrmDist_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrstrmDist_d( parseSide(side), parseUpLo(uplo), 
                  parseOrientation(orientation),
                  parseUnit(diag), toDouble(alpha), toDistMatrix_d(RptrA),
                  toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP trtrmm_d( SEXP uplo, SEXP RptrA){
  ElTrtrmm_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trtrmmDist_d( SEXP uplo, SEXP RptrA){
  ElTrtrmmDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP twoSidedTrmm_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrmm_d( parseUpLo(uplo), parseUnit(diag), toMatrix_d(RptrA),
                    toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrmmDist_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrmmDist_d( parseUpLo(uplo), parseUnit(diag), toDistMatrix_d(RptrA),
                    toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrsm_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrsm_d( parseUpLo(uplo), parseUnit(diag), toMatrix_d(RptrA),
                    toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrsmDist_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrsmDist_d( parseUpLo(uplo), parseUnit(diag), toDistMatrix_d(RptrA),
                    toDistMatrix_d(RptrB) );
  return R_NilValue;
}
