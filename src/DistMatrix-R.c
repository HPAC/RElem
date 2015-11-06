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
  //setAttrib(Rptr, R_ClassSymbol, mkString("ElDistMatrix_i"));
  UNPROTECT(1);
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
  return Rptr;
}

SEXP showDistData_i(SEXP Rptr){
  ElElementalData data;
  ElDistMatrixDistData_i( toDistMatrix_i(Rptr), &data);
  printf("Col Dist: %s\n",parseDistEnum(data.colDist));
  printf("Row Dist: %s\n",parseDistEnum(data.rowDist));
  return R_NilValue;
}

SEXP showDistData_d(SEXP Rptr){
  ElElementalData data;
  ElDistMatrixDistData_d( toDistMatrix_d(Rptr), &data);
  printf("Col Dist: %s\n",parseDistEnum(data.colDist));
  printf("Row Dist: %s\n",parseDistEnum(data.rowDist));
  return R_NilValue;
}

SEXP showDistData_z(SEXP Rptr){
  ElElementalData data;
  ElDistMatrixDistData_z( toDistMatrix_z(Rptr), &data);
  printf("Col Dist: %s\n",parseDistEnum(data.colDist));
  printf("Row Dist: %s\n",parseDistEnum(data.rowDist));
  return R_NilValue;
}

SEXP distCommDistMatrix_i(SEXP RptrA, SEXP Rptrc){
  ElDistMatrixDistComm_i( toDistMatrix_i(RptrA), toComm_p(Rptrc) );
  return R_NilValue;
}

SEXP distCommDistMatrix_d(SEXP RptrA, SEXP Rptrc){
  ElDistMatrixDistComm_d( toDistMatrix_d(RptrA), toComm_p(Rptrc) );
  return R_NilValue;
}

SEXP distCommDistMatrix_z(SEXP RptrA, SEXP Rptrc){
  ElDistMatrixDistComm_z( toDistMatrix_z(RptrA), toComm_p(Rptrc) );
  return R_NilValue;
}

SEXP destroyDistMatrix_d(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElDistMatrixDestroy_d( toDistMatrix_d(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));
  return R_NilValue;
}

SEXP destroyDistMatrix_i(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElDistMatrixDestroy_i( toDistMatrix_i(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));
  return R_NilValue;
}

SEXP destroyDistMatrix_z(SEXP Rptr){
  if ( isDestroyed(Rptr) ){
    /* printf("Destroyed from before\n"); */
    return R_NilValue;
  }
  ElDistMatrixDestroy_z( toDistMatrix_z(Rptr) );
  setAttrib(Rptr, install("destroyed"), mkString("Y"));
  return R_NilValue;
}

SEXP emptyDistMatrix_i(SEXP Rptr){
  ElDistMatrixEmpty_i( toDistMatrix_i(Rptr) );
  return R_NilValue;
}

SEXP emptyDistMatrix_d(SEXP Rptr){
  ElDistMatrixEmpty_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP emptyDistMatrix_z(SEXP Rptr){
  ElDistMatrixEmpty_z( toDistMatrix_z(Rptr) );
  return R_NilValue;
}

SEXP emptyDataDistMatrix_i(SEXP Rptr){
  ElDistMatrixEmptyData_i( toDistMatrix_i(Rptr) );
  return R_NilValue;
}

SEXP emptyDataDistMatrix_d(SEXP Rptr){
  ElDistMatrixEmptyData_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP emptyDataDistMatrix_z(SEXP Rptr){
  ElDistMatrixEmptyData_z( toDistMatrix_z(Rptr) );
  return R_NilValue;
}

SEXP setGridDistMatrix_i(SEXP Rptr, SEXP RptrGrid){
  ElDistMatrixSetGrid_i( toDistMatrix_i(Rptr) , toGrid(RptrGrid) );
  return R_NilValue;
}

SEXP setGridDistMatrix_d(SEXP Rptr, SEXP RptrGrid){
  ElDistMatrixSetGrid_d( toDistMatrix_d(Rptr) , toGrid(RptrGrid) );
  return R_NilValue;
}

SEXP setGridDistMatrix_z(SEXP Rptr, SEXP RptrGrid){
  ElDistMatrixSetGrid_z( toDistMatrix_z(Rptr) , toGrid(RptrGrid) );
  return R_NilValue;
}

SEXP resizeDistMatrix_i(SEXP Rptr, SEXP height, SEXP width){
  ElDistMatrixResize_i( toDistMatrix_i(Rptr), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP resizeDistMatrix_d(SEXP Rptr, SEXP height, SEXP width){
  ElDistMatrixResize_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP resizeDistMatrix_z(SEXP Rptr, SEXP height, SEXP width){
  ElDistMatrixResize_z( toDistMatrix_z(Rptr), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP resizeLDimDistMatrix_i(SEXP Rptr, SEXP height, SEXP width, SEXP ldim){
  ElDistMatrixResizeWithLDim_i( toDistMatrix_i(Rptr), toElInt(height),
				toElInt(width), toElInt(ldim) );
  return R_NilValue;
}

SEXP resizeLDimDistMatrix_d(SEXP Rptr, SEXP height, SEXP width, SEXP ldim){
  ElDistMatrixResizeWithLDim_d( toDistMatrix_d(Rptr), toElInt(height),
				toElInt(width), toElInt(ldim) );
  return R_NilValue;
}

SEXP resizeLDimDistMatrix_z(SEXP Rptr, SEXP height, SEXP width, SEXP ldim){
  ElDistMatrixResizeWithLDim_z( toDistMatrix_z(Rptr), toElInt(height),
				toElInt(width), toElInt(ldim) );
  return R_NilValue;
}

SEXP makeConsistentDistMatrix_i(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeConsistent_i( toDistMatrix_i(Rptr), toBool(includeViewers) );
  return R_NilValue;
}

SEXP makeConsistentDistMatrix_d(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeConsistent_d( toDistMatrix_d(Rptr), toBool(includeViewers) );
  return R_NilValue;
}

SEXP makeConsistentDistMatrix_z(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeConsistent_z( toDistMatrix_z(Rptr), toBool(includeViewers) );
  return R_NilValue;
}

SEXP makeSizeConsistentDistMatrix_i(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeSizeConsistent_i( toDistMatrix_i(Rptr), 
                                    toBool(includeViewers) );
  return R_NilValue;
}

SEXP makeSizeConsistentDistMatrix_d(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeSizeConsistent_d( toDistMatrix_d(Rptr), 
                                    toBool(includeViewers) );
  return R_NilValue;
}

SEXP makeSizeConsistentDistMatrix_z(SEXP Rptr, SEXP includeViewers){
  ElDistMatrixMakeSizeConsistent_z( toDistMatrix_z(Rptr), 
                                    toBool(includeViewers) );
  return R_NilValue;
}

SEXP alignDistMatrix_i
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlign_i( toDistMatrix_i(Rptr), toElInt(colAlign),
                       toElInt(rowAlign), toBool(constrain) );
  return R_NilValue;
}

SEXP alignDistMatrix_d
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlign_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                       toElInt(rowAlign), toBool(constrain) );
  return R_NilValue;
}

SEXP alignDistMatrix_z
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlign_z( toDistMatrix_z(Rptr), toElInt(colAlign),
                       toElInt(rowAlign), toBool(constrain) );
  return R_NilValue;
}

SEXP alignColsDistMatrix_i( SEXP Rptr, SEXP colAlign, SEXP constrain){
  ElDistMatrixAlignCols_i( toDistMatrix_i(Rptr), toElInt(colAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP alignColsDistMatrix_d( SEXP Rptr, SEXP colAlign, SEXP constrain){
  ElDistMatrixAlignCols_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP alignColsDistMatrix_z( SEXP Rptr, SEXP colAlign, SEXP constrain){
  ElDistMatrixAlignCols_z( toDistMatrix_z(Rptr), toElInt(colAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP alignRowsDistMatrix_i( SEXP Rptr, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlignRows_i( toDistMatrix_i(Rptr), toElInt(rowAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP alignRowsDistMatrix_d( SEXP Rptr, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlignRows_d( toDistMatrix_d(Rptr), toElInt(rowAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP alignRowsDistMatrix_z( SEXP Rptr, SEXP rowAlign, SEXP constrain){
  ElDistMatrixAlignRows_z( toDistMatrix_z(Rptr), toElInt(rowAlign),
                           toBool(constrain) );
  return R_NilValue;
}

SEXP freeAlignments_i(SEXP Rptr){
  ElDistMatrixFreeAlignments_i( toDistMatrix_i(Rptr) );
  return R_NilValue;
}

SEXP freeAlignments_d(SEXP Rptr){
  ElDistMatrixFreeAlignments_d( toDistMatrix_d(Rptr) );
  return R_NilValue;
}

SEXP freeAlignments_z(SEXP Rptr){
  ElDistMatrixFreeAlignments_z( toDistMatrix_z(Rptr) );
  return R_NilValue;
}

SEXP setRootDistMatrix_i(SEXP Rptr, SEXP root, SEXP constrain){
  ElDistMatrixSetRoot_i( toDistMatrix_i(Rptr), toElInt(root),
                         toBool(constrain) );
  return R_NilValue;
}

SEXP setRootDistMatrix_d(SEXP Rptr, SEXP root, SEXP constrain){
  ElDistMatrixSetRoot_d( toDistMatrix_d(Rptr), toElInt(root),
                         toBool(constrain) );
  return R_NilValue;
}

SEXP setRootDistMatrix_z(SEXP Rptr, SEXP root, SEXP constrain){
  ElDistMatrixSetRoot_z( toDistMatrix_z(Rptr), toElInt(root),
                         toBool(constrain) );
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

SEXP alignAndResizeDistMatrix_i
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP height, SEXP width,
  SEXP force, SEXP constrain){
  ElDistMatrixAlignAndResize_i( toDistMatrix_i(Rptr), toElInt(colAlign),
                                toElInt(rowAlign), toElInt(height), 
                                toElInt(width), toBool(force),
                                toBool(constrain) );
  return R_NilValue;
}

SEXP alignAndResizeDistMatrix_d
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP height, SEXP width,
  SEXP force, SEXP constrain){
  ElDistMatrixAlignAndResize_d( toDistMatrix_d(Rptr), toElInt(colAlign),
                                toElInt(rowAlign), toElInt(height), 
                                toElInt(width), toBool(force),
                                toBool(constrain) );
  return R_NilValue;
}

SEXP alignAndResizeDistMatrix_z
( SEXP Rptr, SEXP colAlign, SEXP rowAlign, SEXP height, SEXP width,
  SEXP force, SEXP constrain){
  ElDistMatrixAlignAndResize_z( toDistMatrix_z(Rptr), toElInt(colAlign),
                                toElInt(rowAlign), toElInt(height), 
                                toElInt(width), toBool(force),
                                toBool(constrain) );
  return R_NilValue;
}

SEXP alignColsAndResizeDistMatrix_i
( SEXP Rptr, SEXP colAlign, SEXP height, SEXP width, SEXP force,
  SEXP constrain){
  ElDistMatrixAlignColsAndResize_i( toDistMatrix_i(Rptr), toElInt(colAlign),
                                    toElInt(height), toElInt(width), 
                                    toBool(force), toBool(constrain) );
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

SEXP alignColsAndResizeDistMatrix_z
( SEXP Rptr, SEXP colAlign, SEXP height, SEXP width, SEXP force,
  SEXP constrain){
  ElDistMatrixAlignColsAndResize_z( toDistMatrix_z(Rptr), toElInt(colAlign),
                                    toElInt(height), toElInt(width), 
                                    toBool(force), toBool(constrain) );
  return R_NilValue;
}

SEXP alignRowsAndResizeDistMatrix_i
( SEXP Rptr, SEXP rowAlign, SEXP height, SEXP width, SEXP force,
  SEXP constrain){
  ElDistMatrixAlignRowsAndResize_i( toDistMatrix_i(Rptr), toElInt(rowAlign),
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

SEXP alignRowsAndResizeDistMatrix_z
( SEXP Rptr, SEXP rowAlign, SEXP height, SEXP width, SEXP force,
  SEXP constrain){
  ElDistMatrixAlignRowsAndResize_z( toDistMatrix_z(Rptr), toElInt(rowAlign),
                                    toElInt(height), toElInt(width),
                                    toBool(force), toBool(constrain) );
  return R_NilValue;
}

SEXP attachDistMatrix_i
(SEXP Rptr, SEXP height, SEXP width,  SEXP grid,
 SEXP colAlign, SEXP rowAlign, SEXP buffer, SEXP ldim, SEXP root){
  ElDistMatrixAttach_i( toDistMatrix_i(Rptr), toElInt(height), toElInt(width),
                        toGrid(grid), toElInt(colAlign),
                        toElInt(rowAlign),
                        toElInt_p(buffer), toElInt(ldim), toElInt(root) );
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

SEXP lockedAttachDistMatrix_i
(SEXP Rptr, SEXP height, SEXP width,  SEXP grid,
 SEXP colAlign, SEXP rowAlign, SEXP buffer, SEXP ldim, SEXP root){
  ElDistMatrixLockedAttach_i( toDistMatrix_i(Rptr), toElInt(height), 
                              toElInt(width), toGrid(grid), toElInt(colAlign),
                              toElInt(rowAlign), toElInt_p(buffer),
                              toElInt(ldim), toElInt(root) );
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

SEXP heightDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixHeight_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP heightDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixHeight_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP heightDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixHeight_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP widthDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixWidth_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP widthDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixWidth_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP widthDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixWidth_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP diagonalLengthDistMatrix_i(SEXP Rptr, SEXP offset){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixDiagonalLength_i( toDistMatrix_i(Rptr), toElInt(offset), 
                                INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP diagonalLengthDistMatrix_d(SEXP Rptr, SEXP offset){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixDiagonalLength_d( toDistMatrix_d(Rptr), toElInt(offset), 
                                INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP diagonalLengthDistMatrix_z(SEXP Rptr, SEXP offset){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixDiagonalLength_z( toDistMatrix_z(Rptr), toElInt(offset), 
                                INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP viewingDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixViewing_i( toDistMatrix_i(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP viewingDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixViewing_d( toDistMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP viewingDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixViewing_z( toDistMatrix_z(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

/*
SEXP fixedsizeDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixFixedSize_d( toDistMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}
*/

SEXP lockedDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixLocked_i( toDistMatrix_i(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP lockedDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixLocked_d( toDistMatrix_d(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP lockedDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixLocked_z( toDistMatrix_z(Rptr), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP localHeightDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLocalHeight_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP localHeightDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLocalHeight_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP localHeightDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLocalHeight_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP localWidthDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLocalWidth_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP localWidthDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLocalWidth_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP localWidthDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLocalWidth_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP ldimDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLDim_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP ldimDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLDim_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP ldimDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixLDim_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP matrixDistMatrix_i(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixMatrix_i( toDistMatrix_i(RptrA), toMatrix_i_p(RptrAM) );
  return R_NilValue;
}

SEXP matrixDistMatrix_d(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixMatrix_d( toDistMatrix_d(RptrA), toMatrix_d_p(RptrAM) );
  return R_NilValue;
}

SEXP matrixDistMatrix_z(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixMatrix_z( toDistMatrix_z(RptrA), toMatrix_z_p(RptrAM) );
  return R_NilValue;
}

SEXP lockedMatrixDistMatrix_i(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixLockedMatrix_i( toDistMatrix_i(RptrA),
                              (ElConstMatrix_i *)toMatrix_i_p(RptrAM) );
  return R_NilValue;
}

SEXP lockedMatrixDistMatrix_d(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixLockedMatrix_d( toDistMatrix_d(RptrA),
                              (ElConstMatrix_d *)toMatrix_d_p(RptrAM) );
  return R_NilValue;
}

SEXP lockedMatrixDistMatrix_z(SEXP RptrA, SEXP RptrAM){
  ElDistMatrixLockedMatrix_z( toDistMatrix_z(RptrA),
                              (ElConstMatrix_z *)toMatrix_z_p(RptrAM) );
  return R_NilValue;
}

SEXP allocatedMemoryDistMatrix_i(SEXP Rptr){
  size_t mem;
  ElDistMatrixAllocatedMemory_i( toDistMatrix_i(Rptr), &mem );
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  INTEGER(ans)[0]=(int)mem;
  UNPROTECT(1);
  return ans;
}

SEXP allocatedMemoryDistMatrix_d(SEXP Rptr){
  size_t mem;
  ElDistMatrixAllocatedMemory_d( toDistMatrix_d(Rptr), &mem );
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  INTEGER(ans)[0]=(int)mem;
  UNPROTECT(1);
  return ans;
}

SEXP allocatedMemoryDistMatrix_z(SEXP Rptr){
  size_t mem;
  ElDistMatrixAllocatedMemory_z( toDistMatrix_z(Rptr), &mem );
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  INTEGER(ans)[0]=(int)mem;
  UNPROTECT(1);
  return ans;
}

SEXP bufferDistMatrix_i(SEXP Rptr){
  ElInt *buffer;
  ElDistMatrixBuffer_i( toDistMatrix_i(Rptr), &buffer);
  SEXP pBuff = PROTECT(R_MakeExternalPtr(buffer, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  UNPROTECT(1);
  return pBuff;
}

SEXP bufferDistMatrix_d(SEXP Rptr){
  double *buffer;
  ElDistMatrixBuffer_d( toDistMatrix_d(Rptr), &buffer);
  SEXP pBuff = PROTECT(R_MakeExternalPtr(buffer, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  UNPROTECT(1);
  return pBuff;
}

SEXP lockedBufferDistMatrix_i(SEXP Rptr){
  const ElInt *buffer;
  ElDistMatrixLockedBuffer_i( toDistMatrix_i(Rptr), &buffer);
  SEXP pBuff = PROTECT( R_MakeExternalPtr((void *)buffer, R_NilValue, 
					  R_NilValue) );
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  UNPROTECT(1);
  return pBuff;
}

SEXP lockedBufferDistMatrix_d(SEXP Rptr){
  const double *buffer;
  ElDistMatrixLockedBuffer_d( toDistMatrix_d(Rptr), &buffer);
  SEXP pBuff = PROTECT( R_MakeExternalPtr((void *)buffer, R_NilValue, 
					  R_NilValue) );
  R_RegisterCFinalizerEx(pBuff, _clear, TRUE);
  UNPROTECT(1);
  return pBuff;
}

SEXP gridDistMatrix_i(SEXP RptrA, SEXP RptrGrid){
  ElDistMatrixGrid_i( toDistMatrix_i(RptrA),
                      (ElConstGrid *)toGrid_p(RptrGrid) );
  return R_NilValue;
}

SEXP gridDistMatrix_d(SEXP RptrA, SEXP RptrGrid){
  ElDistMatrixGrid_d( toDistMatrix_d(RptrA),
                      (ElConstGrid *)toGrid_p(RptrGrid) );
  return R_NilValue;
}

SEXP gridDistMatrix_z(SEXP RptrA, SEXP RptrGrid){
  ElDistMatrixGrid_z( toDistMatrix_z(RptrA),
                      (ElConstGrid *)toGrid_p(RptrGrid) );
  return R_NilValue;
}

SEXP colConstrainedDistMatrix_i(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixColConstrained_i( toDistMatrix_i(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colConstrainedDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixColConstrained_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colConstrainedDistMatrix_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixColConstrained_z( toDistMatrix_z(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowConstrainedDistMatrix_i(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixRowConstrained_i( toDistMatrix_i(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowConstrainedDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixRowConstrained_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowConstrainedDistMatrix_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixRowConstrained_z( toDistMatrix_z(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rootConstrainedDistMatrix_i(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixRootConstrained_i( toDistMatrix_i(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rootConstrainedDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixRootConstrained_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rootConstrainedDistMatrix_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixRootConstrained_z( toDistMatrix_z(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colAlignDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColAlign_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colAlignDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColAlign_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colAlignDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColAlign_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowAlignDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowAlign_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowAlignDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowAlign_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowAlignDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowAlign_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colShiftDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColShift_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colShiftDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColShift_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colShiftDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColShift_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowShiftDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowShift_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowShiftDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowShift_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowShiftDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowShift_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP colRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixColRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rowRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRowRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialColRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialColRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialColRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialColRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialColRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialColRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialRowRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialRowRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialRowRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialRowRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialRowRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialRowRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialUnionColRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialUnionColRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialUnionColRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialUnionColRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialUnionColRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialUnionColRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialUnionRowRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialUnionRowRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialUnionRowRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialUnionRowRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP partialUnionRowRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixPartialUnionRowRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP distRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixDistRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP distRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixDistRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP distRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixDistRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP crossRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixCrossRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP crossRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixCrossRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP crossRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixCrossRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP redundantRankDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRedundantRank_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP redundantRankDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRedundantRank_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP redundantRankDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRedundantRank_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rootDistMatrix_i(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRoot_i( toDistMatrix_i(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rootDistMatrix_d(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRoot_d( toDistMatrix_d(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP rootDistMatrix_z(SEXP Rptr){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixRoot_z( toDistMatrix_z(Rptr), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP participatingDistMatrix_i(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixParticipating_i( toDistMatrix_i(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP participatingDistMatrix_d(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixParticipating_d( toDistMatrix_d(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP participatingDistMatrix_z(SEXP RptrA){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1) );
  ElDistMatrixParticipating_z( toDistMatrix_z(RptrA), (bool *)LOGICAL(ans) );
  UNPROTECT(1);
  return ans;
}


/*

Maaaany funcs pending

*/

SEXP getDistMatrix_i(SEXP Rptr, SEXP i, SEXP j){
  SEXP ans = PROTECT( allocVector(INTSXP, 1) );
  ElDistMatrixGet_i( toDistMatrix_i(Rptr), toElInt(i), toElInt(j), INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP getDistMatrix_d(SEXP Rptr, SEXP i, SEXP j){
  SEXP ans = PROTECT( allocVector(REALSXP, 1) );
  ElDistMatrixGet_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j), REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP getDistMatrix_z(SEXP Rptr, SEXP i, SEXP j){
  complex_double result;
  ElDistMatrixGet_z( toDistMatrix_z(Rptr), toElInt(i), toElInt(j), &result );
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  COMPLEX(ans)[0].r = creal(result);
  COMPLEX(ans)[0].i = cimag(result);
  UNPROTECT(1);
  return ans;
}

SEXP setDistMatrix_i(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixSet_i( toDistMatrix_i(Rptr), toElInt(i), toElInt(j), 
                     toElInt(alpha) );
  return R_NilValue;
}

SEXP setDistMatrix_d(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixSet_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j), 
                     toDouble(alpha) );
  return R_NilValue;
}

SEXP setDistMatrix_z(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixSet_z( toDistMatrix_z(Rptr), toElInt(i), toElInt(j), 
                     toDouble(alpha) );
  return R_NilValue;
}

SEXP updateDistMatrix_i(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixUpdate_i( toDistMatrix_i(Rptr), toElInt(i), toElInt(j),
			toElInt(alpha) );
  return R_NilValue;
}

SEXP updateDistMatrix_d(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixUpdate_d( toDistMatrix_d(Rptr), toElInt(i), toElInt(j),
                    toDouble(alpha) );
  return R_NilValue;
}

SEXP updateDistMatrix_z(SEXP Rptr, SEXP i, SEXP j, SEXP alpha){
  ElDistMatrixUpdate_z( toDistMatrix_z(Rptr), toElInt(i), toElInt(j),
                    toDouble(alpha) );
  return R_NilValue;
}


/*

//Think if it is better to return a matrix instead.
SEXP getSubmatrixDistMatrix_d(SEXP Rptr, SEXP rowInds, SEXP colInds, SEXP Rsub){
  ElDistMatrixGetSubmatrix_d( toDistMatrix_d(Rptr), 
                              length(rowInds), toElInt_p(rowInds), 
                              length(colInds), toElInt_p(colInds), 
                              toDistMatrix_d(Rsub) );
  return R_NilValue;
}
*/

SEXP getLocalDistMatrix_i(SEXP RptrA, SEXP iLoc, SEXP jLoc){
  SEXP ans=PROTECT( allocVector(INTSXP,1) );
  ElDistMatrixGetLocal_i( toDistMatrix_i(RptrA), toElInt(iLoc), toElInt(jLoc),
                          INTEGER(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP getLocalDistMatrix_d(SEXP RptrA, SEXP iLoc, SEXP jLoc){
  SEXP ans=PROTECT( allocVector(REALSXP,1) );
  ElDistMatrixGetLocal_d( toDistMatrix_d(RptrA), toElInt(iLoc), toElInt(jLoc),
                          REAL(ans) );
  UNPROTECT(1);
  return ans;
}

SEXP getLocalDistMatrix_z(SEXP RptrA, SEXP iLoc, SEXP jLoc){
  complex_double result;
  ElDistMatrixGetLocal_z( toDistMatrix_z(RptrA), toElInt(iLoc), toElInt(jLoc), &result );
  SEXP ans = PROTECT( allocVector(CPLXSXP, 1) );
  COMPLEX(ans)[0].r = creal(result);
  COMPLEX(ans)[0].i = cimag(result);
  UNPROTECT(1);
  return ans;
}

SEXP setLocalDistMatrix_i(SEXP RptrA, SEXP iLoc, SEXP jLoc, SEXP val){
  ElDistMatrixSetLocal_i( toDistMatrix_i(RptrA), toElInt(iLoc), toElInt(jLoc),
                          toElInt(val) );
  return R_NilValue;
}

SEXP setLocalDistMatrix_d(SEXP RptrA, SEXP iLoc, SEXP jLoc, SEXP val){
  ElDistMatrixSetLocal_d( toDistMatrix_d(RptrA), toElInt(iLoc), toElInt(jLoc),
                          toDouble(val) );
  return R_NilValue;
}

SEXP setLocalDistMatrix_z(SEXP RptrA, SEXP iLoc, SEXP jLoc, SEXP val){
  ElDistMatrixSetLocal_z( toDistMatrix_z(RptrA), toElInt(iLoc), toElInt(jLoc),
                          toDouble(val) );
  return R_NilValue;
}
