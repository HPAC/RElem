#include "R-El.h"

static void _clear(SEXP Rptr){
  if (R_ExternalPtrAddr(Rptr) != NULL){
    void *Cptr = (void *) R_ExternalPtrAddr(Rptr);
    free(Cptr);
    R_ClearExternalPtr(Rptr);
  }
}

SEXP newGrid(){
  ElConstGrid *pGrid = malloc(sizeof(ElConstGrid));
  ElDefaultGrid(pGrid);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pGrid, install("Grid"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElGrid") );
  return Rptr;
}

//  *Check if it really necessary
SEXP newGridC(){
  ElGrid *pGrid = malloc(sizeof(ElGrid));
  ElGridCreate(MPI_COMM_WORLD, EL_COLUMN_MAJOR, pGrid);
  SEXP Rptr = PROTECT(R_MakeExternalPtr(pGrid, install("Grid"),R_NilValue));
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  setAttrib(Rptr, R_ClassSymbol, mkString("ElGrid") );
  return Rptr;
}

SEXP gridRow( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridRow( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridCol( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridCol( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridHeight( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridHeight( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridWidth( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridWidth( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridSize( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridSize( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

/* Pending
Grid order type
Colcomm
RowComm
GridComm
 */

SEXP gridMCRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridMCRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridMRRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridMRRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridVCRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridVCRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridVRRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridVRRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridMCSize( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridMCSize( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridMRSize( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridMRSize( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridVCSize( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridVCSize( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridVRSize( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridVRSize( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

/*pending
mcComm
mrComm
vcComm
vrComm
mdComm
mdperpcomm
*/

SEXP gridGCD( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridGCD( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridLCM( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridLCM( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridInGrid(SEXP Rptr){
  SEXP ans=PROTECT( allocVector(LGLSXP,1) );
  UNPROTECT(1);
  ElGridInGrid( toGrid(Rptr), (bool *)LOGICAL(ans) );
  return ans;
}

SEXP gridHaveViewers(SEXP Rptr){
  SEXP ans=PROTECT( allocVector(LGLSXP,1) );
  UNPROTECT(1);
  ElGridHaveViewers( toGrid(Rptr), (bool *)LOGICAL(ans) );
  return ans;
}

SEXP gridOwningRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridOwningRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}

SEXP gridViewingRank( SEXP Rptr){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridViewingRank( toGrid(Rptr), INTEGER(ans) );
  return ans;
}


SEXP gridVCToViewingMap( SEXP Rptr, SEXP VCRank){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridVCToViewingMap( toGrid(Rptr), (int)toElInt(VCRank), INTEGER(ans) );
  return ans;
}

/* pending
SEXP gridOwningGroup( SEXP Rptr)
SEXP gridOwningComm( SEXP Rptr)
SEXP gridViewingComm( SEXP Rptr)

*/

SEXP gridDiagPath( SEXP Rptr, SEXP VCRank){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridDiagPath( toGrid(Rptr), (int)toElInt(VCRank), INTEGER(ans) );
  return ans;
}

SEXP gridDiagPathRank( SEXP Rptr, SEXP VCRank){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridDiagPathRank( toGrid(Rptr), (int)toElInt(VCRank), INTEGER(ans) );
  return ans;
}

SEXP gridFirstVCRank( SEXP Rptr, SEXP diagPath){
  SEXP ans= PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridFirstVCRank( toGrid(Rptr), (int)toElInt(diagPath), INTEGER(ans) );
  return ans;
}

SEXP gridFindFactor( SEXP p){
  SEXP ans=PROTECT( allocVector(INTSXP,1) );
  UNPROTECT(1);
  ElGridFindFactor( (int)toElInt(p), INTEGER(ans) );
  return ans;
} 


