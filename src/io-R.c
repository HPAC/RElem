#include "R-El.h"

SEXP display_i( SEXP Rptr, SEXP text ){
  ElDisplay_i( toMatrix_i(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP display_s( SEXP Rptr, SEXP text ){
  ElDisplay_s( toMatrix_s(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP display_d( SEXP Rptr, SEXP text ){
  ElDisplay_d( toMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP display_c( SEXP Rptr, SEXP text ){
  ElDisplay_c( toMatrix_c(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP display_z( SEXP Rptr, SEXP text ){
  ElDisplay_z( toMatrix_z(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP displayDist_i( SEXP Rptr, SEXP text ){
  ElDisplayDist_i( toDistMatrix_i(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP displayDist_s( SEXP Rptr, SEXP text ){
  ElDisplayDist_s( toDistMatrix_s(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP displayDist_d( SEXP Rptr, SEXP text ){
  ElDisplayDist_d( toDistMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP displayDist_c( SEXP Rptr, SEXP text ){
  ElDisplayDist_c( toDistMatrix_c(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP displayDist_z( SEXP Rptr, SEXP text ){
  ElDisplayDist_z( toDistMatrix_z(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP print_i( SEXP Rptr, SEXP text ){
  ElPrint_i( toMatrix_i(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP print_s( SEXP Rptr, SEXP text ){
  ElPrint_s( toMatrix_s(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP print_d( SEXP Rptr, SEXP text ){
  ElPrint_d( toMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP print_c( SEXP Rptr, SEXP text ){
  ElPrint_c( toMatrix_c(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP print_z( SEXP Rptr, SEXP text ){
  ElPrint_z( toMatrix_z(Rptr), toChar_p(text) );
  return R_NilValue;
}

SEXP printDist_i( SEXP Rptr, SEXP text ){
  ElPrintDist_i( toDistMatrix_i(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP printDist_s( SEXP Rptr, SEXP text ){
  ElPrintDist_s( toDistMatrix_s(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP printDist_d( SEXP Rptr, SEXP text ){
  ElPrintDist_d( toDistMatrix_d(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP printDist_c( SEXP Rptr, SEXP text ){
  ElPrintDist_c( toDistMatrix_c(Rptr), toChar_p(text) );
  return R_NilValue;
}
SEXP printDist_z( SEXP Rptr, SEXP text ){
  ElPrintDist_z( toDistMatrix_z(Rptr), toChar_p(text) );
  return R_NilValue;
}


SEXP read_d(SEXP Rptr, SEXP filename, SEXP format){
  ElRead_d( toMatrix_d(Rptr), toChar_p(filename),
            parseFormatText(format) );
  return R_NilValue;
}

SEXP read_i(SEXP Rptr, SEXP filename, SEXP format){
  ElRead_i( toMatrix_i(Rptr), toChar_p(filename),
            parseFormatText(format) );
  return R_NilValue;
}

SEXP read_z(SEXP Rptr, SEXP filename, SEXP format){
  ElRead_z( toMatrix_z(Rptr), toChar_p(filename),
            parseFormatText(format) );
  return R_NilValue;
}

SEXP readDist_d(SEXP Rptr, SEXP filename, SEXP format, SEXP sequential){
  ElReadDist_d( toDistMatrix_d(Rptr), toChar_p(filename),
                parseFormatText(format), toBool(sequential));
  return R_NilValue;
}

SEXP readDist_i(SEXP Rptr, SEXP filename, SEXP format, SEXP sequential){
  ElReadDist_i( toDistMatrix_i(Rptr), toChar_p(filename),
                parseFormatText(format), toBool(sequential));
  return R_NilValue;
}

SEXP readDist_z(SEXP Rptr, SEXP filename, SEXP format, SEXP sequential){
  ElReadDist_z( toDistMatrix_z(Rptr), toChar_p(filename),
                parseFormatText(format), toBool(sequential));
  return R_NilValue;
}

SEXP spy_d(SEXP Rptr, SEXP title, SEXP tol){
  ElSpy_d( toMatrix_d(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP spy_i(SEXP Rptr, SEXP title, SEXP tol){
  ElSpy_i( toMatrix_i(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP spy_z(SEXP Rptr, SEXP title, SEXP tol){
  ElSpy_z( toMatrix_z(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP spyDist_d(SEXP Rptr, SEXP title, SEXP tol){
  ElSpyDist_d( toDistMatrix_d(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP spyDist_i(SEXP Rptr, SEXP title, SEXP tol){
  ElSpyDist_i( toDistMatrix_i(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP spyDist_z(SEXP Rptr, SEXP title, SEXP tol){
  ElSpyDist_z( toDistMatrix_z(Rptr), toChar_p(title), toDouble(tol) );
  return R_NilValue;
}

SEXP write_d(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWrite_d( toMatrix_d(Rptr), toChar_p(basename), parseFormatText(format),
             toChar_p(title) );
  return R_NilValue;
}

SEXP write_i(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWrite_i( toMatrix_i(Rptr), toChar_p(basename), parseFormatText(format),
             toChar_p(title) );
  return R_NilValue;
}

SEXP write_z(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWrite_z( toMatrix_z(Rptr), toChar_p(basename), parseFormatText(format),
             toChar_p(title) );
  return R_NilValue;
}

SEXP writeDist_d(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWriteDist_d( toDistMatrix_d(Rptr), toChar_p(basename), 
                 parseFormatText(format), toChar_p(title) );
  return R_NilValue;
}

SEXP writeDist_i(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWriteDist_i( toDistMatrix_i(Rptr), toChar_p(basename), 
                 parseFormatText(format), toChar_p(title) );
  return R_NilValue;
}

SEXP writeDist_z(SEXP Rptr, SEXP basename, SEXP format, SEXP title){
  ElWriteDist_z( toDistMatrix_z(Rptr), toChar_p(basename), 
                 parseFormatText(format), toChar_p(title) );
  return R_NilValue;
}
