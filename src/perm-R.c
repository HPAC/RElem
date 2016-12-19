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
  RELEM_ABORT_ON_ERROR(e);
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
  RELEM_ABORT_ON_ERROR(e);
  SEXP Rptr = PROTECT( R_MakeExternalPtr( pPerm, install("Permutation"),
                                          R_NilValue) );
  R_RegisterCFinalizerEx(Rptr, _clear, TRUE);
  UNPROTECT(1);
  return Rptr;
}

SEXP permutationMakeIdentityDist(SEXP RptrP, SEXP size){
  ElDistPermutationMakeIdentity( toDistPermutation(RptrP), toElInt(size));
  return R_NilValue;
}

SEXP permutationMakeIdentity(SEXP RptrP, SEXP size){
  ElPermutationMakeIdentity( toPermutation(RptrP), toElInt(size));
  return R_NilValue;
}

SEXP permutationReserveSwapsDist(SEXP RptrP, SEXP size){
  ElDistPermutationReserveSwaps( toDistPermutation(RptrP), toElInt(size));
  return R_NilValue;
}

SEXP permutationReserveSwaps(SEXP RptrP, SEXP size){
  ElPermutationReserveSwaps( toPermutation(RptrP), toElInt(size));
  return R_NilValue;
}

SEXP permutationMakeArbitraryDist(SEXP RptrP){
  ElDistPermutationMakeArbitrary( toDistPermutation(RptrP));
  return R_NilValue;
}

SEXP permutationMakeArbitrary(SEXP RptrP){
  ElPermutationMakeArbitrary( toPermutation(RptrP));
  return R_NilValue;
}


SEXP permutationSwapDist(SEXP RptrP, SEXP origin, SEXP dest){
  ElDistPermutationSwap( toDistPermutation(RptrP), toElInt(origin),
                         toElInt(dest));
  return R_NilValue;
}

SEXP permutationSwap(SEXP RptrP, SEXP origin, SEXP dest){
  ElPermutationSwap( toPermutation(RptrP), toElInt(origin),
                     toElInt(dest));
  return R_NilValue;
}

SEXP permutationSwapSequenceDist(SEXP RptrP, SEXP PAppend, SEXP dest){
  ElDistPermutationSwapSequence( toDistPermutation(RptrP), toDistPermutation(PAppend),
                                 toElInt(dest));
  return R_NilValue;
}

SEXP permutationSwapSequence(SEXP RptrP, SEXP PAppend, SEXP dest){
  ElPermutationSwapSequence( toPermutation(RptrP), toPermutation(PAppend),
                             toElInt(dest));
  return R_NilValue;
}


SEXP permutationSetImageDist(SEXP RptrP, SEXP origin, SEXP dest){
  ElDistPermutationSetImage( toDistPermutation(RptrP), toElInt(origin),
                             toElInt(dest));
  return R_NilValue;
}

SEXP permutationSetImage(SEXP RptrP, SEXP origin, SEXP dest){
  ElPermutationSetImage( toPermutation(RptrP), toElInt(origin),
                         toElInt(dest));
  return R_NilValue;
}

SEXP permutationHeightDist(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(INTSXP, 1));
  ElDistPermutationHeight( toDistPermutation(RptrP), INTEGER(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationHeight(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(INTSXP, 1));
  ElPermutationHeight( toPermutation(RptrP), INTEGER(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationWidthDist(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(INTSXP, 1));
  ElDistPermutationWidth( toDistPermutation(RptrP), INTEGER(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationWidth(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(INTSXP, 1));
  ElPermutationWidth( toPermutation(RptrP), INTEGER(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationParityDist(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1));
  ElDistPermutationParity( toDistPermutation(RptrP), (bool *)LOGICAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationParity(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1));
  ElPermutationParity( toPermutation(RptrP), (bool *)LOGICAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationIsSwapSequenceDist(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1));
  ElDistPermutationIsSwapSequence( toDistPermutation(RptrP), (bool *)LOGICAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationIsSwapSequence(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1));
  ElPermutationIsSwapSequence( toPermutation(RptrP), (bool *)LOGICAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationIsImplicitSwapSequenceDist(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1));
  ElDistPermutationIsImplicitSwapSequence( toDistPermutation(RptrP), (bool *)LOGICAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationIsImplicitSwapSequence(SEXP RptrP){
  SEXP ans = PROTECT( allocVector(LGLSXP, 1));
  ElPermutationIsImplicitSwapSequence( toPermutation(RptrP), (bool *)LOGICAL(ans));
  UNPROTECT(1);
  return ans;
}

SEXP permutationPermuteColsDist_d(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteCols_d( toDistPermutation(RptrP), toDistMatrix_d(RptrA),
                                  toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteCols_d(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElPermutationPermuteCols_d( toPermutation(RptrP), toMatrix_d(RptrA),
                              toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteColsDist_z(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteCols_z( toDistPermutation(RptrP), toDistMatrix_z(RptrA),
                                  toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteCols_z(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElPermutationPermuteCols_z( toPermutation(RptrP), toMatrix_z(RptrA),
                              toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteColsDist_i(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteCols_i( toDistPermutation(RptrP), toDistMatrix_i(RptrA),
                                 toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteCols_i(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElPermutationPermuteCols_i( toPermutation(RptrP), toMatrix_i(RptrA),
                              toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteRowsDist_d(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteCols_d( toDistPermutation(RptrP), toDistMatrix_d(RptrA),
                                  toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteRows_d(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElPermutationPermuteCols_d( toPermutation(RptrP), toMatrix_d(RptrA),
                              toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteRowsDist_z(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteCols_z( toDistPermutation(RptrP), toDistMatrix_z(RptrA),
                                  toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteRows_z(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElPermutationPermuteCols_z( toPermutation(RptrP), toMatrix_z(RptrA),
                              toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteRowsDist_i(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteCols_i( toDistPermutation(RptrP), toDistMatrix_i(RptrA),
                                  toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteRows_i(SEXP RptrP, SEXP RptrA, SEXP offset){
  ElPermutationPermuteCols_i( toPermutation(RptrP), toMatrix_i(RptrA),
                              toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteSymmetricallyDist_d(SEXP RptrP, SEXP uplo, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteSymmetrically_d( toDistPermutation(RptrP), parseUpLo(uplo),
                                           toDistMatrix_d(RptrA), toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteSymmetrically_d(SEXP RptrP, SEXP uplo, SEXP RptrA, SEXP offset){
  ElPermutationPermuteSymmetrically_d( toPermutation(RptrP), parseUpLo(uplo),
                                       toMatrix_d(RptrA), toElInt(offset));
  return R_NilValue;
}


SEXP permutationPermuteSymmetricallyDist_z
(SEXP RptrP, SEXP uplo, SEXP RptrA, SEXP offset, SEXP conjugate){
  ElDistPermutationPermuteSymmetrically_z( toDistPermutation(RptrP), parseUpLo(uplo),
                                           toDistMatrix_z(RptrA), toBool(conjugate),
                                           toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteSymmetrically_z
(SEXP RptrP, SEXP uplo, SEXP RptrA, SEXP offset, SEXP conjugate){
  ElPermutationPermuteSymmetrically_z( toPermutation(RptrP), parseUpLo(uplo),
                                       toMatrix_z(RptrA), toBool(conjugate),
                                       toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteSymmetricallyDist_i(SEXP RptrP, SEXP uplo, SEXP RptrA, SEXP offset){
  ElDistPermutationPermuteSymmetrically_i( toDistPermutation(RptrP), parseUpLo(uplo),
                                           toDistMatrix_i(RptrA), toElInt(offset));
  return R_NilValue;
}

SEXP permutationPermuteSymmetrically_i(SEXP RptrP, SEXP uplo, SEXP RptrA, SEXP offset){
  ElPermutationPermuteSymmetrically_i( toPermutation(RptrP), parseUpLo(uplo),
                                       toMatrix_i(RptrA), toElInt(offset));
  return R_NilValue;
}

SEXP permutationExplicitVectorDist(SEXP RptrP, SEXP RptrVec){
  ElDistPermutationExplicitVector(toDistPermutation(RptrP), toDistMatrix_i(RptrVec));
  return R_NilValue;
}

SEXP permutationExplicitVector(SEXP RptrP, SEXP RptrVec){
  ElPermutationExplicitVector(toPermutation(RptrP), toMatrix_i(RptrVec));
  return R_NilValue;
}


SEXP permutationExplicitMatrixDist(SEXP RptrP, SEXP RptrMat){
  ElDistPermutationExplicitMatrix(toDistPermutation(RptrP), toDistMatrix_i(RptrMat));
  return R_NilValue;
}

SEXP permutationExplicitMatrix(SEXP RptrP, SEXP RptrMat){
  ElPermutationExplicitMatrix(toPermutation(RptrP), toMatrix_i(RptrMat));
  return R_NilValue;
}
