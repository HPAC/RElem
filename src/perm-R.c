#include "R-El.h"

static void _clear(SEXP Rptr){
  if (R_ExternalPtrAddr(Rptr) != NULL){
    void *Cptr = (void *) R_ExternalPtrAddr(Rptr);
    free(Cptr);
    R_ClearExternalPtr(Rptr);
  }
}

SEXP newDistPermutation(SEXP RptrGrid){
  ElError e;
  ElDistPermutation *pDPerm = malloc(sizeof(ElDistPermutation));
  e=ElDistPermutationCreate( pDPerm, toGrid(RptrGrid));
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr( pDPerm, install("DistPermutation"),
                                          R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  return Rptr;
}

SEXP newPermutation(){
  ElError e;
  ElPermutation *pPerm = malloc(sizeof(ElPermutation));
  e=ElPermutationCreate(pPerm);
  EL_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr( pPerm, install("Permutation"),
                                          R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  return Rptr;
}
