#include "R-El.h"

SEXP displayMatrix_d( SEXP Rptr, SEXP text ){
  ElDisplay_d( toMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP displayDistMatrix_d( SEXP Rptr, SEXP text ){
  ElDisplayDist_d( toDistMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP printMatrix_d(SEXP Rptr, SEXP text ){
  ElPrint_d( toMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP printDistMatrix_d(SEXP Rptr, SEXP text ){
  ElPrintDist_d( toDistMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP readMatrix_d(SEXP Rptr, SEXP filename, SEXP format){
  ElRead_d( toMatrix_d(Rptr), toChar_p(filename),
            parseFormatText(format) );
  return R_NilValue;
}

SEXP readDistMatrix_d(SEXP Rptr, SEXP filename, SEXP format, SEXP sequential){
  ElReadDist_d( toDistMatrix_d(Rptr), toChar_p(filename),
                parseFormatText(format), toBool(sequential));
  return R_NilValue;
}

SEXP spyMatrix_d(SEXP Rptr, SEXP title, SEXP tol){
  ElSpy_d( toMatrix_d(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP spyDistMatrix_d(SEXP Rptr, SEXP title, SEXP tol){
  ElSpyDist_d( toDistMatrix_d(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP writeMatrix_d(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWrite_d( toMatrix_d(Rptr), toChar_p(basename), parseFormatText(format),
             toChar_p(title) );
  return R_NilValue;
}

SEXP writeDistMatrix_d(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWriteDist_d( toDistMatrix_d(Rptr), toChar_p(basename), 
                 parseFormatText(format), toChar_p(title) );
  return R_NilValue;
}
