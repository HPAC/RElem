#include "R-El.h"

SEXP median_i(SEXP RptrA){
  ElValueInt_i values;
  ElMedian_i( toMatrix_i(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(INTSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  INTEGER(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP median_d(SEXP RptrA){
  ElValueInt_d values;
  ElMedian_d( toMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP medianDist_i(SEXP RptrA){
  ElValueInt_i values;
  ElMedianDist_i( toDistMatrix_i(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(INTSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  INTEGER(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP medianDist_d(SEXP RptrA){
  ElValueInt_d values;
  ElMedianDist_d( toDistMatrix_d(RptrA), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP sort_i( SEXP RptrA, SEXP sortType){
  ElSort_i( toMatrix_i(RptrA), parseSort(sortType) );
  return R_NilValue;
}

SEXP sort_d( SEXP RptrA, SEXP sortType){
  ElSort_d( toMatrix_d(RptrA), parseSort(sortType) );
  return R_NilValue;
}

SEXP sortDist_i( SEXP RptrA, SEXP sortType){
  ElSortDist_i( toDistMatrix_i(RptrA), parseSort(sortType) );
  return R_NilValue;
}

SEXP sortDist_d( SEXP RptrA, SEXP sortType){
  ElSortDist_d( toDistMatrix_d(RptrA), parseSort(sortType) );
  return R_NilValue;
}

SEXP taggedSortDist_i(SEXP RptrA, SEXP sortType){
  ElValueInt_i values;
  ElTaggedSortDist_i( toDistMatrix_i(RptrA), parseSort(sortType), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(INTSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  INTEGER(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP taggedSortDist_d(SEXP RptrA, SEXP sortType){
  ElValueInt_d values;
  ElTaggedSortDist_d( toDistMatrix_d(RptrA), parseSort(sortType), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}


SEXP taggedSort_i(SEXP RptrA, SEXP sortType){
  ElValueInt_i values;
  ElTaggedSort_i( toMatrix_i(RptrA), parseSort(sortType), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(INTSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  INTEGER(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}

SEXP taggedSort_d(SEXP RptrA, SEXP sortType){
  ElValueInt_d values;
  ElTaggedSort_d( toMatrix_d(RptrA), parseSort(sortType), &values );
  SEXP ans=PROTECT( allocVector(VECSXP,2) );
  SEXP idx=PROTECT( allocVector(INTSXP,1) );
  SEXP val=PROTECT( allocVector(REALSXP,1) );
  SEXP names=PROTECT( allocVector(STRSXP,2) );
  REAL(val)[0]=values.value;
  INTEGER(idx)[0]=values.index;
  SET_STRING_ELT(names, 0, mkChar("value"));
  SET_STRING_ELT(names, 1, mkChar("index"));
  SET_VECTOR_ELT(ans, 0, val);
  SET_VECTOR_ELT(ans, 1, idx);
  setAttrib(ans, R_NamesSymbol, names);
  UNPROTECT(4);
  return ans;
}
