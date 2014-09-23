#include "R-El.h"

SEXP axpy_d( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpy_d( toDouble(alpha), toMatrix_d(RptrX), toMatrix_d(RptrY) );
  return R_NilValue;
}
SEXP axpyDist_d( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyDist_d( toDouble(alpha), toDistMatrix_d(RptrX), toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP axpyTriangle_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyTriangle_d( parseUpLo(uplo), toDouble(alpha), toMatrix_d(RptrX), 
                    toMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP axpyTriangleDist_d( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyTriangleDist_d( parseUpLo(uplo), toDouble(alpha),
                        toDistMatrix_d(RptrX), toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP copy_d( SEXP A, SEXP B){
  ElCopy_d( toMatrix_d(A), toMatrix_d(B) );
  return R_NilValue;
}

SEXP copyDist_d( SEXP A, SEXP B){
  ElCopyDist_d( toDistMatrix_d(A), toDistMatrix_d(B) );
  return R_NilValue;
}

SEXP diagonalScale_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScale_d( parseSide(side), toMatrix_d(Rptrd), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleDist_d( SEXP side,  SEXP Rptrd, SEXP RptrX){
  ElDiagonalScaleDist_d( parseSide(side), toDistMatrix_d(Rptrd),
                         toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleTrapezoid_d
( SEXP side, SEXP uplo, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoid_d( parseSide(side), parseUpLo(uplo),
                              toMatrix_d(Rptrd), toMatrix_d(RptrX),
                              toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalScaleTrapezoidDist_d
( SEXP side, SEXP uplo, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoidDist_d( parseSide(side), parseUpLo(uplo), 
                                  toDistMatrix_d(Rptrd), toDistMatrix_d(RptrX),
                                  toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalSolve_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolve_d( parseSide(side), toMatrix_d(Rptrd), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalSolveDist_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolveDist_d( parseSide(side), toDistMatrix_d(Rptrd),
                         toDistMatrix_d(RptrX) );
  return R_NilValue;
}

/*
SEXP diagonalSolveTrapezoid_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalSolveTrapezoid_d( parseSide(side), parseUpLo(uplo), 
                              parseOrientation(orientation),
                              toMatrix_d(Rptrd), toMatrix_d(RptrX),
                              toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalSolveTrapezoidDist_d
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalSolveTrapezoidDist_d( parseSide(side), parseUpLo(uplo), 
                                  parseOrientation(orientation),
                                  toDistMatrix_d(Rptrd), toDistMatrix_d(RptrX),
                                  toElInt(offset) );
  return R_NilValue;
}
*/

SEXP dot_d( SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDot_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  return ans;
}
SEXP dotDist_d( SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDotDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), REAL(ans) );
  return ans;
}

SEXP dotu_d( SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDotu_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  return ans;
}
SEXP dotuDist_d( SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDotuDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), REAL(ans) );
  return ans;
}

/*
Figure out how to do for the entry filling, 
decide if it is worth to do in C or R
*/

SEXP fill_d(SEXP Rptr, SEXP alpha){
  ElFill_d( toMatrix_d(Rptr), toDouble(alpha) );
  return R_NilValue;
}

SEXP fillDist_d(SEXP Rptr, SEXP alpha){
  ElFillDist_d( toDistMatrix_d(Rptr), toDouble(alpha) );
  return R_NilValue;
}

SEXP hadamard_d(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamard_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP hadamardDist_d(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamardDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
                    toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP hilbertSchmidt_d(SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElHilbertSchmidt_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  return ans;
}

SEXP hilbertSchmidtDist_d(SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElHilbertSchmidtDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                          REAL(ans) );
  return ans;
}

/* IndexDependentFill
   ================== */

/* IndexDependentMap
   ================== */


/* Make Hermitian
   ============== */

/* Make Real
   ============== */

SEXP makeSymmetric_d(SEXP uplo, SEXP RptrA){
  ElMakeSymmetric_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP makeSymmetricDist_d(SEXP uplo, SEXP RptrA){
  ElMakeSymmetricDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}


SEXP makeTrapezoidal_d(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidal_d( parseUpLo(uplo), toMatrix_d(RptrA), toElInt(offset) );
  return R_NilValue;
}

SEXP makeTrapezoidalDist_d(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidalDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                           toElInt(offset) );
  return R_NilValue;
}

SEXP makeTriangular_d(SEXP uplo, SEXP RptrA){
  ElMakeTriangular_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP makeTriangularDist_d(SEXP uplo, SEXP RptrA){
  ElMakeTriangularDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP max_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMax_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP maxDist_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMaxDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMax_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMax_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMaxDist_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMaxDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMax_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMax_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMaxDist_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMaxDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP maxAbs_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMaxAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP maxAbsDist_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMaxAbsDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMaxAbs_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMax_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMaxAbsDist_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMaxDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMaxAbs_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMaxAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMaxAbsDist_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMaxAbsDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}


//Min

SEXP min_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMin_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP minDist_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMinDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMin_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMin_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMinDist_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMinDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMin_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMin_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMinDist_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMinDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP minAbs_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMinAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP minAbsDist_d(SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElMinAbsDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMinAbs_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMinAbs_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP symmetricMinAbsDist_d(SEXP uplo, SEXP RptrA){
  ElValueIntPair_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElSymmetricMinAbsDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.indices[0];
  INTEGER(coords)[1]=values.indices[1];
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMinAbs_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMinAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP vectorMinAbsDist_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  UNPROTECT(4);
  ElVectorMinAbsDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  return ans;
}

SEXP nrm2_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElNrm2_d( toMatrix_d(RptrA), REAL(ans) );
  return ans;
}

SEXP nrm2Dist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElNrm2Dist_d( toDistMatrix_d(RptrA), REAL(ans) );
  return ans;
}

SEXP scale_d(SEXP alpha, SEXP RptrA){
  ElScale_d( toDouble(alpha), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP scaleDist_d(SEXP alpha, SEXP RptrA){
  ElScaleDist_d( toDouble(alpha), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP scaleTrapezoid(SEXP alpha, SEXP uplo, SEXP RptrA, SEXP offset){
  ElScaleTrapezoid_d( toDouble(alpha), parseUpLo(uplo), toMatrix_d(RptrA),
                      toElInt(offset) );
  return R_NilValue;
}

SEXP scaleTrapezoidDist(SEXP alpha, SEXP uplo, SEXP RptrA, SEXP offset){
  ElScaleTrapezoidDist_d( toDouble(alpha), parseUpLo(uplo), 
                          toDistMatrix_d(RptrA), toElInt(offset) );
  return R_NilValue;
}

SEXP setDiagonal_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElSetDiagonal_d( toMatrix_d(RptrA), toDouble(alpha), toElInt(offset) );
  return R_NilValue;
}

SEXP setDiagonalDist_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElSetDiagonalDist_d( toDistMatrix_d(RptrA), toDouble(alpha), 
                       toElInt(offset) );
  return R_NilValue;
}

SEXP swap_d(SEXP orientation, SEXP RptrX, SEXP RptrY){
  ElSwap_d( parseOrientation(orientation), toMatrix_d(RptrX), 
            toMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP swapDist_d(SEXP orientation, SEXP RptrX, SEXP RptrY){
  ElSwapDist_d( parseOrientation(orientation), toDistMatrix_d(RptrX),
                toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP rowSwap_d(SEXP RptrA, SEXP to, SEXP from){
  ElRowSwap_d( toMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP rowSwapDist_d(SEXP RptrA, SEXP to, SEXP from){
  ElRowSwapDist_d( toDistMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP colSwap_d(SEXP RptrA, SEXP to, SEXP from){
  ElColSwap_d( toMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP colSwapDist_d(SEXP RptrA, SEXP to, SEXP from){
  ElColSwapDist_d( toDistMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP symmetricSwap_d(SEXP uplo, SEXP RptrA, SEXP to, SEXP from){
  ElSymmetricSwap_d( parseUpLo(uplo), toMatrix_d(RptrA), toElInt(to), 
                     toElInt(from) );
  return R_NilValue;
}

SEXP symmetricSwapDist_d(SEXP uplo, SEXP RptrA, SEXP to, SEXP from){
  ElSymmetricSwapDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), toElInt(to), 
                         toElInt(from) );
  return R_NilValue;
}

SEXP transpose_d(SEXP RptrA, SEXP RptrB){
  ElTranspose_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP transposeDist_d(SEXP RptrA, SEXP RptrB){
  ElTransposeDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP updateDiagonal_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElUpdateDiagonal_d( toMatrix_d(RptrA), toDouble(alpha), toElInt(offset) );
  return R_NilValue;
}

SEXP updateDiagonalDist(SEXP RptrA, SEXP alpha, SEXP offset){
  ElUpdateDiagonalDist_d( toDistMatrix_d(RptrA), toDouble(alpha), 
                          toElInt(offset) );
  return R_NilValue;
}

SEXP zero_d(SEXP RptrA){
  ElZero_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP zeroDist_d(SEXP RptrA){
  ElZeroDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}
