#include "R-El.h"

// B = A^H
SEXP adjoint_z( SEXP RptrA, SEXP RptrB){
  ElAdjoint_z( toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP adjointDist_z( SEXP RptrA, SEXP RptrB){
  ElAdjointDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP axpy_d( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpy_d( toDouble(alpha), toMatrix_d(RptrX), toMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP axpy_z( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpy_z( toDComplex(alpha), toMatrix_z(RptrX), toMatrix_z(RptrY) );
  return R_NilValue;
}

SEXP axpyDist_d( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyDist_d( toDouble(alpha), toDistMatrix_d(RptrX), toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP axpyDist_z( SEXP alpha, SEXP RptrX, SEXP RptrY){
  ElAxpyDist_z( toDComplex(alpha), toDistMatrix_z(RptrX), toDistMatrix_z(RptrY) );
  return R_NilValue;
}

SEXP axpyTrapezoid_d
( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP offset){
  ElAxpyTrapezoid_d( parseUpLo(uplo), toDComplex(alpha), toMatrix_d(RptrX), 
                     toMatrix_d(RptrY), toElInt(offset) );
  return R_NilValue;
}

SEXP axpyTrapezoid_z
( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP offset){
  ElAxpyTrapezoid_z( parseUpLo(uplo), toDouble(alpha), toMatrix_z(RptrX), 
                     toMatrix_z(RptrY), toElInt(offset) );
  return R_NilValue;
}

SEXP axpyTrapezoidDist_d
( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP offset){
  ElAxpyTrapezoidDist_d( parseUpLo(uplo), toDouble(alpha),
                         toDistMatrix_d(RptrX), toDistMatrix_d(RptrY),
                         toElInt(offset) );
  return R_NilValue;
}

SEXP axpyTrapezoidDist_z
( SEXP uplo, SEXP alpha, SEXP RptrX, SEXP RptrY, SEXP offset){
  ElAxpyTrapezoidDist_z( parseUpLo(uplo), toDComplex(alpha),
                         toDistMatrix_z(RptrX), toDistMatrix_z(RptrY),
                         toElInt(offset) );
  return R_NilValue;
}

SEXP conjugate_z(SEXP RptrA){
  ElConjugate_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP conjugateDist_z(SEXP RptrA){
  ElConjugateDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

//B=A
SEXP copy_d( SEXP A, SEXP B){
  ElCopy_d( toMatrix_d(A), toMatrix_d(B) );
  return R_NilValue;
}

SEXP copy_z( SEXP A, SEXP B){
  ElCopy_z( toMatrix_z(A), toMatrix_z(B) );
  return R_NilValue;
}

SEXP copyDist_d( SEXP A, SEXP B){
  ElCopyDist_d( toDistMatrix_d(A), toDistMatrix_d(B) );
  return R_NilValue;
}

SEXP copyDist_z( SEXP A, SEXP B){
  ElCopyDist_z( toDistMatrix_z(A), toDistMatrix_z(B) );
  return R_NilValue;
}

SEXP diagonalScale_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScale_d( parseSide(side), toMatrix_d(Rptrd), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalScale_z( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScale_z( parseSide(side), parseOrientation(orientation), 
		     toMatrix_z(Rptrd), toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleDist_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScaleDist_d( parseSide(side), toDistMatrix_d(Rptrd),
                         toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleDist_z( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalScaleDist_z( parseSide(side), parseOrientation(orientation),
			 toDistMatrix_z(Rptrd), toDistMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP diagonalScaleTrapezoid_d
( SEXP side, SEXP uplo, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoid_d( parseSide(side), parseUpLo(uplo),
                              toMatrix_d(Rptrd), toMatrix_d(RptrX),
                              toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalScaleTrapezoid_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoid_z( parseSide(side), parseUpLo(uplo),
			      parseOrientation(orientation),
                              toMatrix_z(Rptrd), toMatrix_z(RptrX),
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

SEXP diagonalScaleTrapezoidDist_z
( SEXP side, SEXP uplo, SEXP orientation, SEXP Rptrd, SEXP RptrX, SEXP offset){
  ElDiagonalScaleTrapezoidDist_z( parseSide(side), parseUpLo(uplo), 
				  parseOrientation(orientation),
                                  toDistMatrix_z(Rptrd), toDistMatrix_z(RptrX),
                                  toElInt(offset) );
  return R_NilValue;
}

SEXP diagonalSolve_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolve_d( parseSide(side), toMatrix_d(Rptrd), toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalSolve_z( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolve_z( parseSide(side), parseOrientation(orientation),
		     toMatrix_z(Rptrd), toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP diagonalSolveDist_d( SEXP side, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolveDist_d( parseSide(side), toDistMatrix_d(Rptrd),
			 toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP diagonalSolveDist_z( SEXP side, SEXP orientation, SEXP Rptrd, SEXP RptrX){
  ElDiagonalSolveDist_z( parseSide(side), parseOrientation(orientation), 
			 toDistMatrix_z(Rptrd), toDistMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP dot_d( SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElDot_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP dot_z( SEXP RptrA, SEXP RptrB){
  complex_double result;
  ElDot_z( toMatrix_z(RptrA), toMatrix_z(RptrB), &result );
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  COMPLEX(ans)[0].r = creal(result);
    COMPLEX(ans)[0].i = cimag(result);
  UNPROTECT(1);
  return ans;
}

SEXP dotDist_d( SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElDotDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP dotDist_z( SEXP RptrA, SEXP RptrB){
  complex_double result;
  ElDotDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), &result );
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  COMPLEX(ans)[0].r = creal(result);
  COMPLEX(ans)[0].i = cimag(result);
  UNPROTECT(1);
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

SEXP fill_z(SEXP Rptr, SEXP alpha){
  ElFill_z( toMatrix_z(Rptr), toDComplex(alpha) );
  return R_NilValue;
}

SEXP fillDist_d(SEXP Rptr, SEXP alpha){
  ElFillDist_d( toDistMatrix_d(Rptr), toDouble(alpha) );
  return R_NilValue;
}

SEXP fillDist_z(SEXP Rptr, SEXP alpha){
  ElFillDist_z( toDistMatrix_z(Rptr), toDComplex(alpha) );
  return R_NilValue;
}

SEXP fillDiagonal_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElFillDiagonal_d( toMatrix_d(RptrA), toDouble(alpha),
		    toElInt(offset) );
  return R_NilValue;
}

SEXP fillDiagonal_z(SEXP RptrA, SEXP alpha, SEXP offset){
  ElFillDiagonal_z( toMatrix_z(RptrA), toDComplex(alpha),
		    toElInt(offset) );
  return R_NilValue;
}

SEXP fillDiagonalDist_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElFillDiagonalDist_d( toDistMatrix_d(RptrA), toDouble(alpha),
			toElInt(offset) );
  return R_NilValue;
}

SEXP fillDiagonalDist_z(SEXP RptrA, SEXP alpha, SEXP offset){
  ElFillDiagonalDist_z( toDistMatrix_z(RptrA), toDComplex(alpha),
			toElInt(offset) );
  return R_NilValue;
}

SEXP hadamard_d(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamard_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP hadamard_z(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamard_z( toMatrix_z(RptrA), toMatrix_z(RptrB), toMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP hadamardDist_d(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamardDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
                    toDistMatrix_d(RptrC) );
  return R_NilValue;
}

SEXP hadamardDist_z(SEXP RptrA, SEXP RptrB, SEXP RptrC){
  ElHadamardDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
                    toDistMatrix_z(RptrC) );
  return R_NilValue;
}

SEXP hilbertSchmidt_d(SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElHilbertSchmidt_d( toMatrix_d(RptrA), toMatrix_d(RptrB), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP hilbertSchmidt_z(SEXP RptrA, SEXP RptrB){
  complex_double result;
  ElHilbertSchmidt_z( toMatrix_z(RptrA), toMatrix_z(RptrB), &result );
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  COMPLEX(ans)[0].r = creal(result);
  COMPLEX(ans)[0].i = cimag(result);
  UNPROTECT(1);
  return ans;
}

SEXP hilbertSchmidtDist_d(SEXP RptrA, SEXP RptrB){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElHilbertSchmidtDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP hilbertSchmidtDist_z(SEXP RptrA, SEXP RptrB){
  complex_double result;
  ElHilbertSchmidtDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), 
                          &result );
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  COMPLEX(ans)[0].r = creal(result);
  COMPLEX(ans)[0].i = cimag(result);
  UNPROTECT(1);
  return ans;
}

SEXP imagPart_d(SEXP RptrA, SEXP RptrAIm){
  ElImagPart_d( toMatrix_d(RptrA), toMatrix_d(RptrA));
  return R_NilValue;
}

SEXP imagPart_z(SEXP RptrA, SEXP RptrAIm){
  ElImagPart_z( toMatrix_z(RptrA), toMatrix_d(RptrA));
  return R_NilValue;
}

SEXP imagPartDist_d(SEXP RptrA, SEXP RptrAIm){
  ElImagPartDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrA));
  return R_NilValue;
}

SEXP imagPartDist_z(SEXP RptrA, SEXP RptrAIm){
  ElImagPartDist_z( toDistMatrix_z(RptrA), toDistMatrix_d(RptrA));
  return R_NilValue;
}



/* IndexDependentFill
   ================== */

/* IndexDependentMap
   ================== */


/* Make Hermitian
   ============== */

SEXP makeHermitian_z(SEXP uplo, SEXP RptrA){
  ElMakeHermitian_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP makeHermitianDist_z(SEXP uplo, SEXP RptrA){
  ElMakeHermitianDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP makeReal_z(SEXP RptrA){
  ElMakeReal_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP makeRealDist_z(SEXP RptrA){
  ElMakeRealDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP makeSymmetric_d(SEXP uplo, SEXP RptrA){
  ElMakeSymmetric_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP makeSymmetric_z(SEXP uplo, SEXP RptrA){
  ElMakeSymmetric_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP makeSymmetricDist_d(SEXP uplo, SEXP RptrA){
  ElMakeSymmetricDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP makeSymmetricDist_z(SEXP uplo, SEXP RptrA){
  ElMakeSymmetricDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP makeTrapezoidal_d(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidal_d( parseUpLo(uplo), toMatrix_d(RptrA), toElInt(offset) );
  return R_NilValue;
}

SEXP makeTrapezoidal_z(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidal_z( parseUpLo(uplo), toMatrix_z(RptrA), toElInt(offset) );
  return R_NilValue;
}

SEXP makeTrapezoidalDist_d(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidalDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                           toElInt(offset) );
  return R_NilValue;
}

SEXP makeTrapezoidalDist_z(SEXP uplo, SEXP RptrA, SEXP offset){ 
  ElMakeTrapezoidalDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), 
                           toElInt(offset) );
  return R_NilValue;
}

SEXP max_d(SEXP RptrA){
  ElEntry_d values;
  ElMax_d( toMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP maxDist_d(SEXP RptrA){
  ElEntry_d values;
  ElMaxDist_d( toDistMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


SEXP symmetricMax_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  ElSymmetricMax_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMaxDist_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  ElSymmetricMaxDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMax_d(SEXP RptrA){
  ElValueInt_d values;
  ElVectorMax_d( toMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMaxDist_d(SEXP RptrA){
  ElValueInt_d values;
  ElVectorMaxDist_d( toDistMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP maxAbs_d(SEXP RptrA){
  ElEntry_d values;
  ElMaxAbs_d( toMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP maxAbs_z(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMaxAbs_z( toMatrix_z(RptrA), &values );
  REAL(val)[0] = values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP maxAbsDist_d(SEXP RptrA){
  ElEntry_d values;
  ElMaxAbsDist_d( toDistMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP maxAbsDist_z(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMaxAbsDist_z( toDistMatrix_z(RptrA), &values );
  REAL(val)[0] = values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


SEXP symmetricMaxAbs_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMax_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


SEXP symmetricMaxAbs_z(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMaxAbs_z( parseUpLo(uplo), toMatrix_z(RptrA), &values );
  REAL(val)[0] = values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


SEXP symmetricMaxAbsDist_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMaxDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMaxAbsDist_z(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMaxAbsDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), &values );
  REAL(val)[0] = values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


SEXP vectorMaxAbs_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMaxAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMaxAbs_z(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMaxAbs_z( toMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMaxAbsDist_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMaxAbsDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMaxAbsDist_z(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMaxAbsDist_z( toDistMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


//Min

SEXP min_d(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMin_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP minDist_d(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMinDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMin_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMin_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMinDist_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMinDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMin_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMin_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMinDist_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMinDist_d( toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP minAbs_d(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMinAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP minAbs_z(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMinAbs_z( toMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP minAbsDist_z(SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElMinAbsDist_z( toDistMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMinAbs_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMinAbs_d( parseUpLo(uplo), toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMinAbsDist_d(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMinAbsDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP symmetricMinAbsDist_z(SEXP uplo, SEXP RptrA){
  ElEntry_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,2) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElSymmetricMinAbsDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.i;
  INTEGER(coords)[1]=values.j;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("indices"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMinAbs_d(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMinAbs_d( toMatrix_d(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMinAbs_z(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMinAbs_z( toMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP vectorMinAbsDist_z(SEXP RptrA){
  ElValueInt_d values;
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP coords=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  ElVectorMinAbsDist_z( toDistMatrix_z(RptrA), &values );
  REAL(val)[0]=values.value;
  INTEGER(coords)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, coords);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP nrm2_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElNrm2_d( toMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP nrm2_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElNrm2_z( toMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP nrm2Dist_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElNrm2Dist_d( toDistMatrix_d(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP nrm2Dist_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElNrm2Dist_z( toDistMatrix_z(RptrA), REAL(ans) );
  UNPROTECT(1);
  return ans;
}


SEXP realPart_d(SEXP RptrA, SEXP RptrAreal){
  ElRealPart_d(toMatrix_d(RptrA), toMatrix_d(RptrAreal));
  return R_NilValue;
}

SEXP realPart_z(SEXP RptrA, SEXP RptrAreal){
  ElRealPart_z(toMatrix_z(RptrA), toMatrix_d(RptrAreal));
  return R_NilValue;
}

SEXP realPartDist_d(SEXP RptrA, SEXP RptrAreal){
  ElRealPartDist_d(toDistMatrix_d(RptrA), toDistMatrix_d(RptrAreal));
  return R_NilValue;
}

SEXP realPartDist_z(SEXP RptrA, SEXP RptrAreal){
  ElRealPartDist_z(toDistMatrix_z(RptrA), toDistMatrix_d(RptrAreal));
  return R_NilValue;
}


SEXP scale_d(SEXP alpha, SEXP RptrA){
  ElScale_d( toDouble(alpha), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP scale_z(SEXP alpha, SEXP RptrA){
  ElScale_z( toDComplex(alpha), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP scaleDist_d(SEXP alpha, SEXP RptrA){
  ElScaleDist_d( toDouble(alpha), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP scaleDist_z(SEXP alpha, SEXP RptrA){
  ElScaleDist_z( toDComplex(alpha), toDistMatrix_z(RptrA) );
  return R_NilValue;
}


SEXP scaleTrapezoid_d(SEXP alpha, SEXP uplo, SEXP RptrA, SEXP offset){
  ElScaleTrapezoid_d( toDouble(alpha), parseUpLo(uplo), toMatrix_d(RptrA),
                      toElInt(offset) );
  return R_NilValue;
}

SEXP scaleTrapezoid_z(SEXP alpha, SEXP uplo, SEXP RptrA, SEXP offset){
  ElScaleTrapezoid_z( toDComplex(alpha), parseUpLo(uplo), toMatrix_z(RptrA),
                      toElInt(offset) );
  return R_NilValue;
}

SEXP scaleTrapezoidDist_d(SEXP alpha, SEXP uplo, SEXP RptrA, SEXP offset){
  ElScaleTrapezoidDist_d( toDouble(alpha), parseUpLo(uplo), 
                          toDistMatrix_d(RptrA), toElInt(offset) );
  return R_NilValue;
}


SEXP scaleTrapezoidDist_z(SEXP alpha, SEXP uplo, SEXP RptrA, SEXP offset){
  ElScaleTrapezoidDist_z( toDComplex(alpha), parseUpLo(uplo), 
                          toDistMatrix_z(RptrA), toElInt(offset) );
  return R_NilValue;
}

SEXP shift_d( SEXP RptrA, SEXP alpha){
  ElShift_d (toMatrix_d(RptrA), toDouble(alpha) );
  return R_NilValue;
}

SEXP shift_z( SEXP RptrA, SEXP alpha){
  ElShift_z (toMatrix_z(RptrA), toDouble(alpha) );
  return R_NilValue;
}

SEXP shiftDist_d( SEXP RptrA, SEXP alpha){
  ElShiftDist_d (toDistMatrix_d(RptrA), toDouble(alpha) );
  return R_NilValue;
}

SEXP shiftDist_z( SEXP RptrA, SEXP alpha){
  ElShiftDist_z (toDistMatrix_z(RptrA), toDouble(alpha) );
  return R_NilValue;
}

SEXP shiftDiagonal_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElShiftDiagonal_d( toMatrix_d(RptrA), toDouble(alpha), toElInt(offset) );
  return R_NilValue;
}

SEXP shiftDiagonal_z(SEXP RptrA, SEXP alpha, SEXP offset){
  ElShiftDiagonal_z( toMatrix_z(RptrA), toDouble(alpha), toElInt(offset) );
  return R_NilValue;
}

SEXP shiftDiagonalDist_d(SEXP RptrA, SEXP alpha, SEXP offset){
  ElShiftDiagonalDist_d( toDistMatrix_d(RptrA), toDouble(alpha), 
                       toElInt(offset) );
  return R_NilValue;
}

SEXP shiftDiagonalDist_z(SEXP RptrA, SEXP alpha, SEXP offset){
  ElShiftDiagonalDist_z( toDistMatrix_z(RptrA), toDouble(alpha), 
                       toElInt(offset) );
  return R_NilValue;
}


SEXP swap_d(SEXP orientation, SEXP RptrX, SEXP RptrY){
  ElSwap_d( parseOrientation(orientation), toMatrix_d(RptrX), 
            toMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP swap_z(SEXP orientation, SEXP RptrX, SEXP RptrY){
  ElSwap_z( parseOrientation(orientation), toMatrix_z(RptrX), 
            toMatrix_z(RptrY) );
  return R_NilValue;
}

SEXP swapDist_d(SEXP orientation, SEXP RptrX, SEXP RptrY){
  ElSwapDist_d( parseOrientation(orientation), toDistMatrix_d(RptrX),
                toDistMatrix_d(RptrY) );
  return R_NilValue;
}

SEXP swapDist_z(SEXP orientation, SEXP RptrX, SEXP RptrY){
  ElSwapDist_z( parseOrientation(orientation), toDistMatrix_z(RptrX),
                toDistMatrix_z(RptrY) );
  return R_NilValue;
}

SEXP rowSwap_d(SEXP RptrA, SEXP to, SEXP from){
  ElRowSwap_d( toMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP rowSwap_z(SEXP RptrA, SEXP to, SEXP from){
  ElRowSwap_z( toMatrix_z(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP rowSwapDist_d(SEXP RptrA, SEXP to, SEXP from){
  ElRowSwapDist_d( toDistMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP rowSwapDist_z(SEXP RptrA, SEXP to, SEXP from){
  ElRowSwapDist_z( toDistMatrix_z(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP colSwap_d(SEXP RptrA, SEXP to, SEXP from){
  ElColSwap_d( toMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP colSwap_z(SEXP RptrA, SEXP to, SEXP from){
  ElColSwap_z( toMatrix_z(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP colSwapDist_d(SEXP RptrA, SEXP to, SEXP from){
  ElColSwapDist_d( toDistMatrix_d(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP colSwapDist_z(SEXP RptrA, SEXP to, SEXP from){
  ElColSwapDist_z( toDistMatrix_z(RptrA), toElInt(to), toElInt(from) );
  return R_NilValue;
}

SEXP symmetricSwap_d(SEXP uplo, SEXP RptrA, SEXP to, SEXP from){
  ElSymmetricSwap_d( parseUpLo(uplo), toMatrix_d(RptrA), toElInt(to), 
                     toElInt(from) );
  return R_NilValue;
}

SEXP symmetricSwap_z(SEXP uplo, SEXP RptrA, SEXP to, SEXP from){
  ElSymmetricSwap_z( parseUpLo(uplo), toMatrix_z(RptrA), toElInt(to), 
                     toElInt(from) );
  return R_NilValue;
}

SEXP symmetricSwapDist_d(SEXP uplo, SEXP RptrA, SEXP to, SEXP from){
  ElSymmetricSwapDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), toElInt(to), 
                         toElInt(from) );
  return R_NilValue;
}

SEXP symmetricSwapDist_z(SEXP uplo, SEXP RptrA, SEXP to, SEXP from){
  ElSymmetricSwapDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), toElInt(to), 
                         toElInt(from) );
  return R_NilValue;
}

SEXP transpose_d(SEXP RptrA, SEXP RptrB){
  ElTranspose_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP transpose_z(SEXP RptrA, SEXP RptrB){
  ElTranspose_z( toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP transposeDist_d(SEXP RptrA, SEXP RptrB){
  ElTransposeDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP transposeDist_z(SEXP RptrA, SEXP RptrB){
  ElTransposeDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP zero_d(SEXP RptrA){
  ElZero_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP zero_z(SEXP RptrA){
  ElZero_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP zeroDist_d(SEXP RptrA){
  ElZeroDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP zeroDist_z(SEXP RptrA){
  ElZeroDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}
