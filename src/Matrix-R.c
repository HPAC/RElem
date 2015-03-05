#include "R-El.h"


static void _clear(SEXP Rptr){
  if (R_ExternalPtrAddr(Rptr) != NULL){
    void *Cptr = (void *) R_ExternalPtrAddr(Rptr);
    free(Cptr);
    R_ClearExternalPtr(Rptr);
  }
}

//ElMatrixCreate:
SEXP newMatrix_i(){
  ElError e;
  ElMatrix_i *pMat = malloc(sizeof(ElMatrix_i));
  e=ElMatrixCreate_i(pMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pMat, install("Matrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  //setAttrib(Rptr, R_ClassSymbol, mkString("ElMatrix_i"));
  UNPROTECT(1);
  return Rptr;
}
SEXP newMatrix_s(){
  ElError e;
  ElMatrix_s *pMat = malloc(sizeof(ElMatrix_s));
  e=ElMatrixCreate_s(pMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pMat, install("Matrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  //setAttrib(Rptr, R_ClassSymbol, mkString("ElMatrix_s"));
  UNPROTECT(1);
  return Rptr;
}
SEXP newMatrix_d(){
  ElError e;
  ElMatrix_d *pMat = malloc(sizeof(ElMatrix_d));
  e=ElMatrixCreate_d(pMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pMat, install("Matrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  //setAttrib(Rptr, R_ClassSymbol, mkString("ElMatrix_d"));
  UNPROTECT(1);
  return Rptr;
}
SEXP newMatrix_c(){
  ElError e;
  ElMatrix_c *pMat = malloc(sizeof(ElMatrix_c));
  e=ElMatrixCreate_c(pMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pMat, install("Matrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  //setAttrib(Rptr, R_ClassSymbol, mkString("ElMatrix_c"));
  UNPROTECT(1);
  return Rptr;
}
SEXP newMatrix_z(){
  ElError e;
  ElMatrix_z *pMat = malloc(sizeof(ElMatrix_z));
  e=ElMatrixCreate_z(pMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pMat, install("Matrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  //setAttrib(Rptr, R_ClassSymbol, mkString("ElMatrix_z"));
  UNPROTECT(1);
  return Rptr;
}

//ElMatrixDestroy:
SEXP destroyMatrix_i(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElMatrixDestroy_i( toMatrix_i(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));      
  return R_NilValue;
}

SEXP destroyMatrix_s(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElMatrixDestroy_s( toMatrix_s(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));      
  return R_NilValue;
}

SEXP destroyMatrix_d(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElMatrixDestroy_d( toMatrix_d(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));      
  return R_NilValue;
}

SEXP destroyMatrix_c(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElMatrixDestroy_c( toMatrix_c(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));      
  return R_NilValue;
}

SEXP destroyMatrix_z(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElMatrixDestroy_z( toMatrix_z(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));      
  return R_NilValue;
}



SEXP emptyMatrix_d(SEXP Rptr){
  ElMatrixEmpty_d( toMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP resizeMatrix_d(SEXP Rptr, SEXP height, SEXP width){
  ElMatrixResize_d( toMatrix_d(Rptr), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP resizeLDimMatrix_d(SEXP Rptr, SEXP height, SEXP width, SEXP ldim){
  ElMatrixResizeWithLDim_d( toMatrix_d(Rptr), toElInt(height),
                            toElInt(width), toElInt(ldim) );
  return R_NilValue;
}

SEXP attachMatrix_d
(SEXP Rptr, SEXP height, SEXP width, SEXP buffer, SEXP ldim){
  ElMatrixAttach_d( toMatrix_d(Rptr), toElInt(height), toElInt(width),
                    toDouble_p(buffer), toElInt(ldim) );
  return R_NilValue;
}

SEXP lockedAttachMatrix_d
(SEXP Rptr, SEXP height, SEXP width, SEXP buffer, SEXP ldim){
  ElMatrixLockedAttach_d( toMatrix_d(Rptr), toElInt(height), toElInt(width),
                          (const double *)toDouble_p(buffer), toElInt(ldim) );
  return R_NilValue;
}

SEXP controlMatrix_d
(SEXP Rptr, SEXP height, SEXP width, SEXP buffer, SEXP ldim){
  ElMatrixControl_d( toMatrix_d(Rptr), toElInt(height), toElInt(width),
                    toDouble_p(buffer), toElInt(ldim) );
  return R_NilValue;
}

// B<-A
/* only in blas now
SEXP copyMatrix_d(SEXP RptrA, SEXP RptrB){
  ElMatrixCopy_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}
*/
SEXP heightMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElMatrixHeight_d( toMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP widthMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElMatrixWidth_d( toMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP ldimMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElMatrixLDim_d( toMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP memorySizeMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElMatrixMemorySize_d( toMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP diagonalLenghtMatrix_d(SEXP Rptr, SEXP offset){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElMatrixDiagonalLength_d( toMatrix_d(Rptr), toElInt(offset), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP bufferMatrix_d(SEXP Rptr){
  double *buffer;
  ElMatrixBuffer_d( toMatrix_d(Rptr), &buffer);
  SEXP pBuff = PROTECT(R_MakeExternalPtr(buffer, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  UNPROTECT(1);
  return pBuff;
}

SEXP lockedBufferMatrix_d(SEXP Rptr){
  const double *buffer;
  ElMatrixLockedBuffer_d( toMatrix_d(Rptr), &buffer);
  SEXP pBuff = PROTECT(R_MakeExternalPtr( (void *)buffer, R_NilValue, 
                                          R_NilValue));
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  UNPROTECT(1);
  return pBuff;
}

SEXP viewingMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElMatrixViewing_d( toMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  return ans;
}


SEXP fixedsizeMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElMatrixFixedSize_d( toMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP lockedMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElMatrixLocked_d( toMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP getMatrix_d(SEXP Rptr, SEXP i, SEXP j){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElMatrixGet_d( toMatrix_d(Rptr), toElInt(i), toElInt(j), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP setMatrix_d(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElMatrixSet_d( toMatrix_d(Rptr), toElInt(i), toElInt(j), toDouble(alpha) );
  return R_NilValue;
}

SEXP updateMatrix_d(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElMatrixUpdate_d( toMatrix_d(Rptr), toElInt(i), toElInt(j),
                    toDouble(alpha) );
  return R_NilValue;
}
/*
SEXP updateSubmatrixMatrix
(SEXP Rptr, SEXP rowInds, SEXP colInds, SEXP alpha, SEXP Rsub){
  ElMatrixUpdateSubmatrix_d( toMatrix_d(Rptr), toElInt_p(rowInds), 
                          toElInt_p(colInds), toDouble(alpha),
                          toMatrix_d(Rsub) );
  return R_NilValue;
}

*/
