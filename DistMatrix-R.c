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
  e=ElDistMatrixCreate_i( toGrid(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr( pDMat, install("DistMatrix"),
                                          R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_i"));
  return Rptr;
}
SEXP newDistMatrix_s(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_s *pDMat = malloc(sizeof(ElDistMatrix_s));
  e=ElDistMatrixCreate_s( toGrid(RptrGrid), pDMat );
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                        R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_s"));
  return Rptr;
}
SEXP newDistMatrix_d(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_d *pDMat = malloc(sizeof(ElDistMatrix_d));
  e=ElDistMatrixCreate_d( toGrid(RptrGrid), pDMat );
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                         R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_d"));
  return Rptr;
}
SEXP newDistMatrix_c(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_c *pDMat = malloc(sizeof(ElDistMatrix_c));
  e=ElDistMatrixCreate_c( toGrid(RptrGrid), pDMat );
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                         R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_c"));
  return Rptr;
}
SEXP newDistMatrix_z(SEXP RptrGrid){
  ElError e;
  ElDistMatrix_z *pDMat = malloc(sizeof(ElDistMatrix_z));
  e=ElDistMatrixCreate_z(toGrid(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                        R_NilValue));
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
  e=ElDistMatrixCreateSpecific_i(colD, rowD, 
                                 toGrid(RptrGrid), 
                                 pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                        R_NilValue));
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
  e=ElDistMatrixCreateSpecific_s(colD, rowD, toGrid(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                         R_NilValue) );
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
  e=ElDistMatrixCreateSpecific_d(colD, rowD, toGrid(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                         R_NilValue) );
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
  e=ElDistMatrixCreateSpecific_c(colD, rowD, toGrid(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                         R_NilValue) );
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
  e=ElDistMatrixCreateSpecific_z(colD, rowD, toGrid(RptrGrid), pDMat);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr(pDMat, install("DistMatrix"),
                                         R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_z"));
  return Rptr;
}

SEXP showDistData_d(SEXP Rptr){
  ElDistData data;
  ElDistMatrixDistData_d( toDistMatrix_d(Rptr), &data);
  printf("Col Dist: %s\n",parseDistEnum(data.colDist));
  printf("Row Dist: %s\n",parseDistEnum(data.rowDist));
  return R_NilValue;
}


SEXP destroyDistMatrix_d(SEXP Rptr){
  ElDistMatrixDestroy_d( toDistMatrix_d(Rptr) );
  // TODO: Clean the pointer in R
  return R_NilValue;
}

SEXP emptyDistMatrix_d(SEXP Rptr){
  ElDistMatrixEmpty_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP emptyDataDistMatrix_d(SEXP Rptr){
  ElDistMatrixEmptyData_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP setGridDistMatrix_d(SEXP Rptr, SEXP RptrGrid){
  ElDistMatrixSetGrid_d( toDistMatrix_d(Rptr) , toGrid(RptrGrid) );
  return R_NilValue;
}

SEXP resizeDistMatrix_d(SEXP Rptr, SEXP height, SEXP width){
  ElDistMatrixResize_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP resizeLDimDistMatrix_d(SEXP Rptr, SEXP height, SEXP width, SEXP ldim){
  ElDistMatrixResizeWithLDim_d( toDistMatrix_d(Rptr), toElInt(height),
                            toElInt(width), toElInt(ldim) );
  return R_NilValue;
}


SEXP makeConsistentDistMatrix_d(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeConsistent_d( toDistMatrix_d(Rptr), toBool(includeViewers) );
  return R_NilValue;
}

SEXP makeSizeConsistentDistMatrix_d(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeSizeConsistent_d( toDistMatrix_d(Rptr), 
                                    toBool(includeViewers) );
  return R_NilValue;
}

SEXP alignDistMatrix_d
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlign_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                       toElInt(rowAlign), toBool(constrain) );
  return R_NilValue;
}

SEXP alignColsDistMatrix_d( SEXP Rptr, SEXP colAlign, SEXP constrain){
  ElDistMatrixAlignCols_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP alignRowsDistMatrix_d( SEXP Rptr, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlignRows_d( toDistMatrix_d(Rptr), toElInt(rowAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP freeAlignments_d(SEXP Rptr){
  ElDistMatrixFreeAlignments_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP setRootDistMatrix_d(SEXP Rptr, SEXP root){
  ElDistMatrixSetRoot_d( toDistMatrix_d(Rptr), toElInt(root) );
  return R_NilValue;
}
/* Check 
SEXP alignWithDistMatrix_d
( SEXP Rptr, SEXP colDist, SEXP rowDist, SEXP colAlign, SEXP rowAlign,
  SEXP root, SEXP grid, SEXP includeViewers){
  ElDistMatrixAlignWith_d( toDistMatrix_d(Rptr),  toBool(includeViewers) );
  return R_NilValue;
}
alignColsWith
alignRowsWith
*/

SEXP alignAndResizeDistMatrix_d
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP height, SEXP width,
  SEXP force, SEXP constrain){
  ElDistMatrixAlignAndResize_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                                toElInt(rowAlign), toElInt(height), 
                                toElInt(width), toBool(force),
                                toBool(constrain) );
  return R_NilValue;
}

SEXP alignColsAndResizeDistMatrix_d
( SEXP Rptr, SEXP colAlign, SEXP height, SEXP width, SEXP force,
  SEXP constrain){
  ElDistMatrixAlignColsAndResize_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                                    toElInt(height), toElInt(width), 
                                    toBool(force), toBool(constrain) );
  return R_NilValue;
}

SEXP alignRowsAndResizeDistMatrix_d
( SEXP Rptr, SEXP rowAlign, SEXP height, SEXP width, SEXP force,
  SEXP constrain){
  ElDistMatrixAlignRowsAndResize_d( toDistMatrix_d(Rptr), toElInt(rowAlign),
                                    toElInt(height), toElInt(width),
                                    toBool(force), toBool(constrain) );
  return R_NilValue;
}

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
  ElDistMatrixLockedAttach_d( toDistMatrix_d(Rptr), toElInt(height), 
                              toElInt(width), toGrid(grid), toElInt(colAlign),
                              toElInt(rowAlign), toDouble_p(buffer),
                              toElInt(ldim), toElInt(root) );
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
  ElDistMatrixDiagonalLength_d( toDistMatrix_d(Rptr), toElInt(offset), 
                                INTEGER(ans) );
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

SEXP localHeightDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixLocalHeight_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP localWidthDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixLocalWidth_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP ldimDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixLDim_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP matrixDistMatrix_d(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixMatrix_d( toDistMatrix_d(RptrA), toMatrix_d_p(RptrAM) );
  return R_NilValue;
}

SEXP lockedMatrixDistMatrix_d(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixLockedMatrix_d( toDistMatrix_d(RptrA),
                              (ElConstMatrix_d *)toMatrix_d_p(RptrAM) );
  return R_NilValue;
}


SEXP allocatedMemoryDistMatrix_d(SEXP Rptr){
  size_t mem;
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixAllocatedMemory_d( toDistMatrix_d(Rptr), &mem );
  INTEGER(ans)[0]=(int)mem;
  return ans;
}


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
  SEXP pBuff = PROTECT( R_MakeExternalPtr((void *)buffer, R_NilValue, 
                                         R_NilValue) );
  UNPROTECT(1);
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  return pBuff;
}

SEXP gridDistMatrix(SEXP RptrA, SEXP RptrGrid){
  ElDistMatrixGrid_d( toDistMatrix_d(RptrA),
                      (ElConstGrid *)toGrid_p(RptrGrid) );
  return R_NilValue;
}

SEXP colConstrainedDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixColConstrained_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  return ans;
}

SEXP rowConstrainedDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRowConstrained_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  return ans;
}

SEXP rootConstrainedDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRootConstrained_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  return ans;
}

SEXP colAlignDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixColAlign_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP rowAlignDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRowAlign_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP colShiftDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixColShift_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP rowShiftDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRowShift_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP colRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixColRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP rowRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRowRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP partialColRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixPartialColRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP partialRowRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixPartialRowRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP partialUnionColRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixPartialUnionColRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP partialUnionRowRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixPartialUnionRowRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP distRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixDistRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP crossRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixCrossRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP redundantRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRedundantRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP rootDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixRoot_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  return ans;
}

SEXP participatingDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  UNPROTECT(1);
  ElDistMatrixParticipating_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  return ans;
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
  ElDistMatrixSet_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j), 
                     toDouble(alpha) );
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
