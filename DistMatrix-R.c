#include "R-El.h"


static void _clear(SEXP Rptr){
  if (R_ExternalPtrAddr(Rptr) != NULL){
    void *Cptr = (void *) R_ExternalPtrAddr(Rptr);
    free(Cptr);
    R_ClearExternalPtr(Rptr);
  }
}

SEXP newDistMatrix_i(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_i *pDMat = malloc(sizeof(ElDistMatrix_i));
  e=ElDistMatrixCreate_i(*(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_i"));
  return Rptr;
}
SEXP newDistMatrix_s(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_s *pDMat = malloc(sizeof(ElDistMatrix_s));
  e=ElDistMatrixCreate_s(*(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_s"));
  return Rptr;
}
SEXP newDistMatrix_d(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_d *pDMat = malloc(sizeof(ElDistMatrix_d));
  e=ElDistMatrixCreate_d(*(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_d"));
  return Rptr;
}
SEXP newDistMatrix_c(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_c *pDMat = malloc(sizeof(ElDistMatrix_c));
  e=ElDistMatrixCreate_c(*(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_c"));
  return Rptr;
}
SEXP newDistMatrix_z(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_z *pDMat = malloc(sizeof(ElDistMatrix_z));
  e=ElDistMatrixCreate_z(*(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_z"));
  return Rptr;
}

SEXP newDistMatrixSpecific_i(SEXP U, SEXP V, SEXP RptrGrid){
  ElError e;
  ElDistMatrix_i *pDMat = malloc(sizeof(ElDistMatrix_i));
  ElDist colD = parseDistText(U);
  ElDist rowD = parseDistText(V);
  /* Pending: check if the distribution is valid */
  e=ElDistMatrixCreateSpecific_i(colD, rowD, *(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_i"));
  return Rptr;
}

SEXP newDistMatrixSpecific_s(SEXP U, SEXP V, SEXP RptrGrid){
  ElError e;
  ElDistMatrix_s *pDMat = malloc(sizeof(ElDistMatrix_s));
  ElDist colD = parseDistText(U);
  ElDist rowD = parseDistText(V);
  /* Pending: check if the distribution is valid */
  e=ElDistMatrixCreateSpecific_s(colD, rowD, *(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_s"));
  return Rptr;
}

SEXP newDistMatrixSpecific_d(SEXP U, SEXP V, SEXP RptrGrid){
  ElError e;
  ElDistMatrix_d *pDMat = malloc(sizeof(ElDistMatrix_d));
  ElDist colD = parseDistText(U);
  ElDist rowD = parseDistText(V);
  /* Pending: check if the distribution is valid */
  e=ElDistMatrixCreateSpecific_d(colD, rowD, *(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_d"));
  return Rptr;
}

SEXP newDistMatrixSpecific_c(SEXP U, SEXP V, SEXP RptrGrid){
  ElError e;
  ElDistMatrix_c *pDMat = malloc(sizeof(ElDistMatrix_c));
  ElDist colD = parseDistText(U);
  ElDist rowD = parseDistText(V);
  /* Pending: check if the distribution is valid */
  e=ElDistMatrixCreateSpecific_c(colD, rowD, *(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_c"));
  return Rptr;
}

SEXP newDistMatrixSpecific_z(SEXP U, SEXP V, SEXP RptrGrid){
  ElError e;
  ElDistMatrix_z *pDMat = malloc(sizeof(ElDistMatrix_z));
  ElDist colD = parseDistText(U);
  ElDist rowD = parseDistText(V);
  /* Pending: check if the distribution is valid */
  e=ElDistMatrixCreateSpecific_z(colD, rowD, *(ElGrid *) R_ExternalPtrAddr(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_z"));
  return Rptr;
}

SEXP showDistData_d(SEXP Rptr){
  ElDistData data;
  ElDistMatrixDistData_d(*(ElDistMatrix_d *) R_ExternalPtrAddr(Rptr), &data);
  printf("Col Dist: %s\n",parseDistEnum(data.colDist));
  printf("Row Dist: %s\n",parseDistEnum(data.rowDist));
  return R_NilValue;
}




//////////
SEXP destroyDistMatrix_d(SEXP Rptr){
  ElDistMatrixDestroy_d( toDistMatrix_d(Rptr) );
  // TODO: Clean the pointer in R
  return R_NilValue;
}

SEXP emptyDistMatrix_d(SEXP Rptr){
  ElDistMatrixEmpty_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

//emptydata
//setgrid


SEXP resizeDistMatrix_d(SEXP Rptr, SEXP height, SEXP width){
  ElDistMatrixResize_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP resizeLDimDistMatrix_d(SEXP Rptr, SEXP height, SEXP width, SEXP ldim){
  ElDistMatrixResizeWithLDim_d( toDistMatrix_d(Rptr), toElInt(height),
                            toElInt(width), toElInt(ldim) );
  return R_NilValue;
}

//Make consistent

//Makesizec
/*
align
aligncols
 rows
 freeal
setroot
alignwith

aligncolsw
rowswith
alignand res
aligncolsandres
align rows and resize

*/

SEXP attachDistMatrix_d
(SEXP Rptr, SEXP height, SEXP width,  SEXP grid,
 SEXP colAlign, SEXP rowAlign, SEXP buffer, SEXP ldim, SEXP root){
  ElDistMatrixAttach_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width),
                        toGrid(grid), toElInt(colAlign),
                        toElInt(rowAlign),
                        toDouble_p(buffer), toElInt(ldim), toElInt(root) );
  return R_NilValue;
}

SEXP lockedAttachDistMatrix_d
(SEXP Rptr, SEXP height, SEXP width,  SEXP grid,
 SEXP colAlign, SEXP rowAlign, SEXP buffer, SEXP ldim, SEXP root){
  ElDistMatrixAttach_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width),
                        toGrid(grid), toElInt(colAlign), toElInt(rowAlign),
                        toDouble_p(buffer), toElInt(ldim), 
                        toElInt(root) );
  return R_NilValue;
}


SEXP heightDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixHeight_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP widthDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixWidth_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP diagonalLengthDistMatrix_d(SEXP Rptr, SEXP offset){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixDiagonalLength_d( toDistMatrix_d(Rptr), toElInt(offset), INTEGER(ans) );
  return ans;
}

SEXP viewingDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixViewing_d( toDistMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  return ans;
}

/*
SEXP fixedsizeDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixFixedSize_d( toDistMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  return ans;
}
*/

SEXP lockedDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixLocked_d( toDistMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  return ans;
}


/*
localheight
localwidth
*/

SEXP ldimDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixLDim_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

/*distmatristomatrix
  const distmatrixlockedmatrx
  allocated memory
 */

/* rplace by allocated memory
SEXP memorySizeDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixMemorySize_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}
*/

SEXP bufferDistMatrix_d(SEXP Rptr){
  double *buffer;
  ElDistMatrixBuffer_d( toDistMatrix_d(Rptr), &buffer);
  SEXP pBuff = PROTECT(R_MakeExternalPtr(buffer, R_NilValue, R_NilValue));
  UNPROTECT(1);
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  return pBuff;
}

SEXP lockedBufferDistMatrix_d(SEXP Rptr){
  const double *buffer;
  ElDistMatrixLockedBuffer_d( toDistMatrix_d(Rptr), &buffer);
  SEXP pBuff = PROTECT(R_MakeExternalPtr((void *)buffer, R_NilValue, R_NilValue));
  UNPROTECT(1);
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  return pBuff;
}
/*

Maaaany funcs

*/

SEXP getDistMatrix_d(SEXP Rptr, SEXP i, SEXP j){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixGet_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j), REAL(ans) );
  return ans;
}

SEXP setDistMatrix_d(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixSet_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j), toDouble(alpha) );
  return R_NilValue;
}

SEXP updateDistMatrix_d(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixUpdate_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j),
                    toDouble(alpha) );
  return R_NilValue;
}
/*
other bunch
 */
SEXP getDiagonalDistMatrix(SEXP Rptr, SEXP offset, SEXP Rptr_d){
  ElDistMatrixGetDiagonal_d( toDistMatrix_d(Rptr), toElInt(offset),
                         toDistMatrix_d_p(Rptr_d) );
  return R_NilValue;
}
  
/*
//Apparently they are not implemented here
SEXP setDiagonalDistMatrix(SEXP Rptr, SEXP Rptr_d, SEXP offset){
  ElDistMatrixSetDiagonal_d( toDistMatrix_d(Rptr), toDistMatrix_d(Rptr_d), 
                         toElInt(offset) );
  return R_NilValue;
}

SEXP updateDiagonalDistMatrix(SEXP Rptr, SEXP Rptr_d, SEXP offset){
  ElDistMatrixUpdateDiagonal_d( toDistMatrix_d(Rptr), toDistMatrix_d(Rptr_d), 
                         toElInt(offset) );
  return R_NilValue;
}

*/

//Think if it is better to return a matrix instead.
SEXP getSubmatrixDistMatrix(SEXP Rptr, SEXP rowInds, SEXP colInds, SEXP Rsub){
  ElDistMatrixGetSubmatrix_d( toDistMatrix_d(Rptr), 
                          length(rowInds), toElInt_p(rowInds), 
                          length(colInds), toElInt_p(colInds), 
                          toDistMatrix_d_p(Rsub) );
  return R_NilValue;
}
