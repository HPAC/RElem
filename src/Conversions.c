#include "R-El.h"

SEXP toR_d(SEXP RptrA){
  ElInt width, height, bLength;
  ElMatrixWidth_d(toMatrix_d(RptrA),&width);
  ElMatrixHeight_d(toMatrix_d(RptrA),&height);
  bLength=height*width;
  double *buffer;
  ElMatrixBuffer_d(toMatrix_d(RptrA), &buffer);
  SEXP Rarray=PROTECT( allocVector(REALSXP,(int)bLength) );
  for (int i=0; i<bLength; i++)
    REAL(Rarray)[i]=buffer[i];
  UNPROTECT(1);
  return Rarray;
}
