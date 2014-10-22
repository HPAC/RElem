#include "R-El.h"

SEXP merge1x2_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2_d( toMatrix_d(RptrA), toMatrix_d(RptrBL),
                toMatrix_d(RptrBR) );
  return R_NilValue;
}

SEXP merge1x2Dist_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBL),
                    toDistMatrix_d(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2_d( toMatrix_d(RptrA), toMatrix_d(RptrBL),
                toMatrix_d(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2Dist_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBL),
                    toDistMatrix_d(RptrBR) );
  return R_NilValue;
}


SEXP merge2x1_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1_d( toMatrix_d(RptrA), toMatrix_d(RptrBT),
                    toMatrix_d(RptrBB) );
  return R_NilValue;
}

SEXP merge2x1Dist_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBT),
                    toDistMatrix_d(RptrBB) );
  return R_NilValue;
}


SEXP lockedMerge2x1_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1_d( toMatrix_d(RptrA), toMatrix_d(RptrBT),
                    toMatrix_d(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1Dist_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBT),
                    toDistMatrix_d(RptrBB) );
  return R_NilValue;
}


SEXP merge2x2_d( SEXP RptrA,
                 SEXP RptrBTL, SEXP RptrBTR,
                 SEXP RptrBBL, SEXP RptrBBR ){
  ElMerge2x2_d( toMatrix_d(RptrA), toMatrix_d(RptrBTL),
                toMatrix_d(RptrBTR), toMatrix_d(RptrBBL),
                toMatrix_d(RptrBBR) );
  return R_NilValue;
}

SEXP merge2x2Dist_d( SEXP RptrA,
                     SEXP RptrBTL, SEXP RptrBTR,
                     SEXP RptrBBL, SEXP RptrBBR ){
  ElMerge2x2Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBTL),
                    toDistMatrix_d(RptrBTR), toDistMatrix_d(RptrBBL),
                    toDistMatrix_d(RptrBBR) );
  return R_NilValue;
}

SEXP lockedMerge2x2_d( SEXP RptrA,
                 SEXP RptrBTL, SEXP RptrBTR,
                 SEXP RptrBBL, SEXP RptrBBR ){
  ElLockedMerge2x2_d( toMatrix_d(RptrA), toMatrix_d(RptrBTL),
                toMatrix_d(RptrBTR), toMatrix_d(RptrBBL),
                toMatrix_d(RptrBBR) );
  return R_NilValue;
}

SEXP lockedMerge2x2Dist_d( SEXP RptrA,
                     SEXP RptrBTL, SEXP RptrBTR,
                     SEXP RptrBBL, SEXP RptrBBR ){
  ElLockedMerge2x2Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBTL),
                    toDistMatrix_d(RptrBTR), toDistMatrix_d(RptrBBL),
                    toDistMatrix_d(RptrBBR) );
  return R_NilValue;
}
