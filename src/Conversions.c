#include "R-El.h"
#include <stdio.h>
#include <string.h>

SEXP toR_d(SEXP RptrA){
  ElInt width, height, bLength;
  ElMatrixWidth_d(toMatrix_d(RptrA),&width);
  ElMatrixHeight_d(toMatrix_d(RptrA),&height);
  bLength=height*width;
  double *buffer;
  ElMatrixBuffer_d(toMatrix_d(RptrA), &buffer);
  SEXP Rarray=PROTECT( allocVector(REALSXP,(int)bLength) );
  for (ElInt i=0; i<bLength; i++)
    REAL(Rarray)[i]=buffer[i];
  UNPROTECT(1);
  return Rarray;
}

SEXP toR_i(SEXP RptrA){
  ElInt width, height, bLength;
  ElMatrixWidth_i(toMatrix_i(RptrA),&width);
  ElMatrixHeight_i(toMatrix_i(RptrA),&height);
  bLength=height*width;
  int *buffer;
  ElMatrixBuffer_i(toMatrix_i(RptrA), &buffer);
  SEXP Rarray=PROTECT( allocVector(INTSXP,(int)bLength) );
  for (ElInt i=0; i<bLength; i++)
    INTEGER(Rarray)[i]=buffer[i];
  UNPROTECT(1);
  return Rarray;
}


SEXP toR_z(SEXP RptrA){
  ElInt width, height, bLength;
  ElMatrixWidth_z(toMatrix_z(RptrA),&width);
  ElMatrixHeight_z(toMatrix_z(RptrA),&height);
  bLength=height*width;
  complex_double *buffer;
  ElMatrixBuffer_z(toMatrix_z(RptrA), &buffer);
  SEXP Rarray=PROTECT( allocVector(CPLXSXP,(int)bLength) );
  for (ElInt i=0; i<bLength; i++){
    COMPLEX(Rarray)[i].r = creal(buffer[i]);
    COMPLEX(Rarray)[i].i = cimag(buffer[i]);
  }
  UNPROTECT(1);
  return Rarray;
}

SEXP toEl_d(SEXP MatA, SEXP height, SEXP width){
  SEXP Rptr;
  Rptr = newMatrix_d();
  double *buffer;
  ElInt bsize;
  bsize = toElInt(height) * toElInt(width);
  buffer = malloc(sizeof(double) * bsize );
  memcpy((char *)buffer, (char *) REAL(MatA), sizeof(double) * bsize); 
  ElMatrixAttach_d(toMatrix_d(Rptr), toElInt(height), toElInt(width), buffer, toElInt(height));
  return Rptr;
}

SEXP toEl_z(SEXP MatA, SEXP height, SEXP width){
  SEXP Rptr;
  Rptr = newMatrix_z();
  complex_double *buffer;
  ElInt bsize;
  bsize = toElInt(height) * toElInt(width);
  buffer = malloc(sizeof(complex_double) * bsize );
  memcpy((char *)buffer, (char *) COMPLEX(MatA), sizeof(complex_double) * bsize); 
  ElMatrixAttach_z(toMatrix_z(Rptr), toElInt(height), toElInt(width), buffer, toElInt(height));
  return Rptr;
}

SEXP toEl_i(SEXP MatA, SEXP height, SEXP width){
  SEXP Rptr;
  Rptr = newMatrix_i();
  ElInt *buffer;
  ElInt bsize;
  bsize = toElInt(height) * toElInt(width);
  buffer = malloc(sizeof(ElInt) * bsize );
  //Copy Element by element to avoid problems when ElInt != int
  for (ElInt i=0; i<bsize; i++)
    buffer[i] = INTEGER(MatA)[i];
  ElMatrixAttach_i(toMatrix_i(Rptr), toElInt(height), toElInt(width), buffer, toElInt(height));
  return Rptr;
}
  
