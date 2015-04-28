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

SEXP gemm_i
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemm_i( parseOrientation(orientationA), parseOrientation(orientationB),
            toElInt(alpha), toMatrix_i(RptrA), toMatrix_i(RptrB), 
            toElInt(beta), toMatrix_i(RptrC) );
  return R_NilValue;
}

SEXP gemm_d
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemm_d( parseOrientation(orientationA), parseOrientation(orientationB),
            toDouble(alpha), toMatrix_d(RptrA), toMatrix_d(RptrB), 
            toDouble(beta), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP gemm_z
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemm_z( parseOrientation(orientationA), parseOrientation(orientationB),
            toDComplex(alpha), toMatrix_z(RptrA), toMatrix_z(RptrB), 
            toDComplex(beta), toMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP gemmDist_i
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemmDist_i( parseOrientation(orientationA), parseOrientation(orientationB),
                toElInt(alpha), toDistMatrix_i(RptrA), toDistMatrix_i(RptrB), 
                toElInt(beta), toDistMatrix_i(RptrC) );
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

SEXP gemmDist_z
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC){
  ElGemmDist_z( parseOrientation(orientationA), parseOrientation(orientationB),
                toDComplex(alpha), toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
                toDComplex(beta), toDistMatrix_z(RptrC) );
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

SEXP gemmXDist_z
(SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA, SEXP RptrB,
 SEXP beta, SEXP RptrC, SEXP algo){
  ElGemmXDist_z( parseOrientation(orientationA), parseOrientation(orientationB),
		 toDComplex(alpha), toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
                 toDComplex(beta), toDistMatrix_z(RptrC), parseGemmAlgo(algo) );
  return R_NilValue;
}


SEXP hemm_z
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElHemm_z( parseSide(side), parseUpLo(uplo), toDComplex(alpha), toMatrix_z(RptrA),
	    toMatrix_z(RptrB), toDComplex(beta), toMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP hemmDist_z
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElHemmDist_z( parseSide(side), parseUpLo(uplo), toDComplex(alpha),
		toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), toDComplex(beta),
		toDistMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP herk_z
(SEXP side, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElHerk_z( parseSide(side), parseOrientation(orientation), toDComplex(alpha),
	    toMatrix_z(RptrA), toDComplex(beta), toMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP herkDist_z
(SEXP side, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElHerkDist_z( parseSide(side), parseOrientation(orientation), toDComplex(alpha),
		toDistMatrix_z(RptrA), toDComplex(beta), toDistMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP her2k_z
(SEXP side, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElHer2k_z( parseSide(side), parseOrientation(orientation), toDComplex(alpha),
	     toMatrix_z(RptrA), toMatrix_z(RptrB), toDComplex(beta),
	     toMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP her2kDist_z
(SEXP side, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElHer2kDist_z( parseSide(side), parseOrientation(orientation), toDComplex(alpha),
		 toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), toDComplex(beta),
		 toDistMatrix_z(RptrC) );
  return R_NilValue;
}


SEXP multiShiftQuasiTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftQuasiTrsm_d( parseSide(side), parseUpLo(uplo),
                           parseOrientation(orientation),toDouble(alpha),
                           toMatrix_d(RptrA), toMatrix_d(Rptrshifts),
                           toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiShiftQuasiTrsm_z
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftQuasiTrsm_z( parseSide(side), parseUpLo(uplo),
                           parseOrientation(orientation),toDouble(alpha),
                           toMatrix_z(RptrA), toMatrix_z(Rptrshifts),
                           toMatrix_z(RptrB) );
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

SEXP multiShiftQuasiTrsmDist_z
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftQuasiTrsmDist_z( parseSide(side), parseUpLo(uplo), 
                               parseOrientation(orientation),
                               toDouble(alpha), toDistMatrix_z(RptrA),
                               toDistMatrix_z(Rptrshifts),
                               toDistMatrix_z(RptrB) );
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

SEXP multiShiftTrsm_z
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, 
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftTrsm_z( parseSide(side), parseUpLo(uplo), 
                      parseOrientation(orientation), toDouble(alpha),
                      toMatrix_z(RptrA), toMatrix_z(Rptrshifts),
                      toMatrix_z(RptrB) );
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

SEXP multiShiftTrsmDist_z
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA,
 SEXP Rptrshifts, SEXP RptrB){
  ElMultiShiftTrsmDist_z( parseSide(side), parseUpLo(uplo), 
                          parseOrientation(orientation),toDouble(alpha),
                          toDistMatrix_z(RptrA), toDistMatrix_z(Rptrshifts),
                          toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP quasiTrsm_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsm_d( parseSide(side), parseUpLo(uplo),
                 parseOrientation(orientation), toDouble(alpha), 
                 toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP quasiTrsm_z
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsm_z( parseSide(side), parseUpLo(uplo),
                 parseOrientation(orientation), toDouble(alpha), 
                 toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP quasiTrsmDist_d
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsmDist_d( parseSide(side), parseUpLo(uplo), 
                     parseOrientation(orientation), toDouble(alpha), 
                     toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP quasiTrsmDist_z
(SEXP side, SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB){
  ElQuasiTrsmDist_z( parseSide(side), parseUpLo(uplo), 
                     parseOrientation(orientation), toDouble(alpha), 
                     toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
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


SEXP symm_z
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElSymm_z( parseSide(side), parseUpLo(uplo), toDouble(alpha), 
            toMatrix_z(RptrA), toMatrix_z(RptrB), toDouble(beta), 
            toMatrix_z(RptrC) );
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

SEXP symmDist_z
(SEXP side, SEXP uplo, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta,
 SEXP RptrC){
  ElSymmDist_z( parseSide(side), parseUpLo(uplo), toDouble(alpha), 
                toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), toDouble(beta),
                toDistMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP syrk_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElSyrk_d(parseUpLo(uplo), parseOrientation(orientation),  toDouble(alpha),
           toMatrix_d(RptrA), toDouble(beta), toMatrix_d(RptrC) );
  return R_NilValue;
}


SEXP syrk_z
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElSyrk_z(parseUpLo(uplo), parseOrientation(orientation),  toDouble(alpha),
           toMatrix_z(RptrA), toDouble(beta), toMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP syrkDist_d
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElSyrkDist_d( parseUpLo(uplo), parseOrientation(orientation), 
                toDouble(alpha), toDistMatrix_d(RptrA), toDouble(beta),
                toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP syrkDist_z
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP beta, SEXP RptrC){
  ElSyrkDist_z( parseUpLo(uplo), parseOrientation(orientation), 
                toDouble(alpha), toDistMatrix_z(RptrA), toDouble(beta),
                toDistMatrix_z(RptrC) );
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

SEXP syr2k_z
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, 
 SEXP RptrC){
  ElSyr2k_z(parseUpLo(uplo), parseOrientation(orientation), toDouble(alpha),
            toMatrix_z(RptrA), toMatrix_z(RptrB), toDouble(beta),
            toMatrix_z(RptrC) );
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


SEXP syr2kDist_z
(SEXP uplo, SEXP orientation, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, 
 SEXP RptrC){
  ElSyr2kDist_z( parseUpLo(uplo), parseOrientation(orientation), 
                 toDouble(alpha), toDistMatrix_z(RptrA), 
                 toDistMatrix_z(RptrA), toDouble(beta), 
                 toDistMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP trdtrmm_d( SEXP uplo, SEXP RptrA){
  ElTrdtrmm_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}


SEXP trdtrmm_z( SEXP uplo, SEXP RptrA, SEXP conjugate){
  ElTrdtrmm_z( parseUpLo(uplo), toMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP trdtrmmDist_d( SEXP uplo, SEXP RptrA){
  ElTrdtrmmDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trdtrmmDist_z( SEXP uplo, SEXP RptrA, SEXP conjugate){
  ElTrdtrmmDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP trdtrmmQuasi_d( SEXP uplo, SEXP RptrA, SEXP RptrdOff){
  ElTrdtrmmQuasi_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_d(RptrdOff) );
  return R_NilValue;
}

SEXP trdtrmmQuasi_z( SEXP uplo, SEXP RptrA, SEXP RptrdOff, SEXP conjugate){
  ElTrdtrmmQuasi_z( parseUpLo(uplo), toMatrix_z(RptrA), toMatrix_z(RptrdOff),
		    toBool(conjugate) );
  return R_NilValue;
}

SEXP trdtrmmQuasiDist_d( SEXP uplo, SEXP RptrA, SEXP RptrdOff){
  ElTrdtrmmQuasiDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                        toDistMatrix_d(RptrdOff) );
  return R_NilValue;
}

SEXP trdtrmmQuasiDist_z( SEXP uplo, SEXP RptrA, SEXP RptrdOff, SEXP conjugate){
  ElTrdtrmmQuasiDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), 
                        toDistMatrix_z(RptrdOff), toBool(conjugate) );
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

SEXP trmm_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrmm_z( parseSide(side), parseUpLo(uplo), parseOrientation(orientation), 
            parseUnit(diag), toDouble(alpha), toMatrix_z(RptrA),
            toMatrix_z(RptrB) );
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

SEXP trmmDist_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrmmDist_z( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
            parseUnit(diag), toDouble(alpha), toDistMatrix_z(RptrA),
            toDistMatrix_z(RptrB) );
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

SEXP trrk_z
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA,
  SEXP RptrB, SEXP beta, SEXP RptrC){
  ElTrrk_z( parseUpLo(uplo), parseOrientation(orientationA),
            parseOrientation(orientationB), toDouble(alpha), toMatrix_z(RptrA),
            toMatrix_z(RptrB), toDouble(beta), toMatrix_z(RptrC) ); 
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

SEXP trrkDist_z
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP alpha, SEXP RptrA,
  SEXP RptrB, SEXP beta, SEXP RptrC){
  ElTrrkDist_z( parseUpLo(uplo), parseOrientation(orientationA),
                parseOrientation(orientationB), toDouble(alpha),
                toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), toDouble(beta),
                toDistMatrix_z(RptrC) ); 
  return R_NilValue;
}

/*
Trr2k not yet implemented for sequential
*/

SEXP trr2kDist_d
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP orientationC,
  SEXP orientationD, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, SEXP RptrC,
  SEXP RptrD, SEXP gamma, SEXP RptrE ){
  ElTrr2kDist_d( parseUpLo(uplo), parseOrientation(orientationA), 
                 parseOrientation(orientationB), parseOrientation(orientationC),
                 parseOrientation(orientationD), toDouble(alpha), 
                 toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toDouble(beta),
                 toDistMatrix_d(RptrC), toDistMatrix_d(RptrD), toDouble(gamma), 
                 toDistMatrix_d(RptrE) );
  return R_NilValue;
}

SEXP trr2kDist_z
( SEXP uplo, SEXP orientationA, SEXP orientationB, SEXP orientationC,
  SEXP orientationD, SEXP alpha, SEXP RptrA, SEXP RptrB, SEXP beta, SEXP RptrC,
  SEXP RptrD, SEXP gamma, SEXP RptrE ){
  ElTrr2kDist_z( parseUpLo(uplo), parseOrientation(orientationA), 
                 parseOrientation(orientationB), parseOrientation(orientationC),
                 parseOrientation(orientationD), toDouble(alpha), 
                 toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), toDouble(beta),
                 toDistMatrix_z(RptrC), toDistMatrix_z(RptrD), toDouble(gamma), 
                 toDistMatrix_z(RptrE) );
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

SEXP trsm_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrsm_z( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
            parseUnit(diag), toDouble(alpha), toMatrix_z(RptrA),
            toMatrix_z(RptrB) );
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

SEXP trsmDist_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrsmDist_z( parseSide(side), parseUpLo(uplo), parseOrientation(orientation),
                parseUnit(diag), toDouble(alpha), toDistMatrix_z(RptrA),
                toDistMatrix_z(RptrB) );
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

SEXP trstrm_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrstrm_z( parseSide(side), parseUpLo(uplo), parseOrientation(orientation), 
              parseUnit(diag), toDouble(alpha), toMatrix_z(RptrA),
              toMatrix_z(RptrB) );
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

SEXP trstrmDist_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP diag, SEXP alpha, SEXP RptrA, 
  SEXP RptrB){
  ElTrstrmDist_z( parseSide(side), parseUpLo(uplo), 
                  parseOrientation(orientation),
                  parseUnit(diag), toDouble(alpha), toDistMatrix_z(RptrA),
                  toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP trtrmm_d( SEXP uplo, SEXP RptrA){
  ElTrtrmm_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}


SEXP trtrmm_z( SEXP uplo, SEXP RptrA, SEXP conjugate){
  ElTrtrmm_z( parseUpLo(uplo), toMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP trtrmmDist_d( SEXP uplo, SEXP RptrA){
  ElTrtrmmDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP trtrmmDist_z( SEXP uplo, SEXP RptrA, SEXP conjugate){
  ElTrtrmmDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP twoSidedTrmm_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrmm_d( parseUpLo(uplo), parseUnit(diag), toMatrix_d(RptrA),
                    toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrmm_z( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrmm_z( parseUpLo(uplo), parseUnit(diag), toMatrix_z(RptrA),
                    toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrmmDist_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrmmDist_d( parseUpLo(uplo), parseUnit(diag), toDistMatrix_d(RptrA),
                    toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrmmDist_z( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrmmDist_z( parseUpLo(uplo), parseUnit(diag), toDistMatrix_z(RptrA),
                    toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrsm_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrsm_d( parseUpLo(uplo), parseUnit(diag), toMatrix_d(RptrA),
                    toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrsm_z( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrsm_z( parseUpLo(uplo), parseUnit(diag), toMatrix_z(RptrA),
                    toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrsmDist_d( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrsmDist_d( parseUpLo(uplo), parseUnit(diag), toDistMatrix_d(RptrA),
			toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP twoSidedTrsmDist_z( SEXP uplo, SEXP diag, SEXP RptrA, SEXP RptrB){
  ElTwoSidedTrsmDist_z( parseUpLo(uplo), parseUnit(diag), toDistMatrix_z(RptrA),
			toDistMatrix_z(RptrB) );
  return R_NilValue;
}
