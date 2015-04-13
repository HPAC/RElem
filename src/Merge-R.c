#include "R-El.h"

SEXP merge1x2_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2_d( toMatrix_d(RptrA), toMatrix_d(RptrBL),
                toMatrix_d(RptrBR) );
  return R_NilValue;
}


SEXP merge1x2_i( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2_i( toMatrix_i(RptrA), toMatrix_i(RptrBL),
                toMatrix_i(RptrBR) );
  return R_NilValue;
}

SEXP merge1x2_z( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2_z( toMatrix_z(RptrA), toMatrix_z(RptrBL),
                toMatrix_z(RptrBR) );
  return R_NilValue;
}

SEXP merge1x2Dist_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBL),
                    toDistMatrix_d(RptrBR) );
  return R_NilValue;
}

SEXP merge1x2Dist_i( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2Dist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrBL),
                    toDistMatrix_i(RptrBR) );
  return R_NilValue;
}

SEXP merge1x2Dist_z( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElMerge1x2Dist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrBL),
                    toDistMatrix_z(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2_d( toMatrix_d(RptrA), toMatrix_d(RptrBL),
		      toMatrix_d(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2_i( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2_i( toMatrix_i(RptrA), toMatrix_i(RptrBL),
		      toMatrix_i(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2_z( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2_z( toMatrix_z(RptrA), toMatrix_z(RptrBL),
		      toMatrix_z(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2Dist_d( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBL),
			  toDistMatrix_d(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2Dist_i( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2Dist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrBL),
			  toDistMatrix_i(RptrBR) );
  return R_NilValue;
}

SEXP lockedMerge1x2Dist_z( SEXP RptrA, SEXP RptrBL, SEXP RptrBR ){
  ElLockedMerge1x2Dist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrBL),
			  toDistMatrix_z(RptrBR) );
  return R_NilValue;
}

SEXP merge2x1_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1_d( toMatrix_d(RptrA), toMatrix_d(RptrBT),
                    toMatrix_d(RptrBB) );
  return R_NilValue;
}

SEXP merge2x1_i( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1_i( toMatrix_i(RptrA), toMatrix_i(RptrBT),
                    toMatrix_i(RptrBB) );
  return R_NilValue;
}

SEXP merge2x1_z( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1_z( toMatrix_z(RptrA), toMatrix_z(RptrBT),
                    toMatrix_z(RptrBB) );
  return R_NilValue;
}

SEXP merge2x1Dist_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBT),
                    toDistMatrix_d(RptrBB) );
  return R_NilValue;
}

SEXP merge2x1Dist_i( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1Dist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrBT),
                    toDistMatrix_i(RptrBB) );
  return R_NilValue;
}

SEXP merge2x1Dist_z( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElMerge2x1Dist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrBT),
                    toDistMatrix_z(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1_d( toMatrix_d(RptrA), toMatrix_d(RptrBT),
                    toMatrix_d(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1_i( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1_i( toMatrix_i(RptrA), toMatrix_i(RptrBT),
                    toMatrix_i(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1_z( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1_z( toMatrix_z(RptrA), toMatrix_z(RptrBT),
		      toMatrix_z(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1Dist_d( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1Dist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrBT),
			  toDistMatrix_d(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1Dist_i( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1Dist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrBT),
			  toDistMatrix_i(RptrBB) );
  return R_NilValue;
}

SEXP lockedMerge2x1Dist_z( SEXP RptrA, SEXP RptrBT, SEXP RptrBB ){
  ElLockedMerge2x1Dist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrBT),
			  toDistMatrix_z(RptrBB) );
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

SEXP merge2x2_i( SEXP RptrA,
                 SEXP RptrBTL, SEXP RptrBTR,
                 SEXP RptrBBL, SEXP RptrBBR ){
  ElMerge2x2_i( toMatrix_i(RptrA), toMatrix_i(RptrBTL),
                toMatrix_i(RptrBTR), toMatrix_i(RptrBBL),
                toMatrix_i(RptrBBR) );
  return R_NilValue;
}

SEXP merge2x2_z( SEXP RptrA,
                 SEXP RptrBTL, SEXP RptrBTR,
                 SEXP RptrBBL, SEXP RptrBBR ){
  ElMerge2x2_z( toMatrix_z(RptrA), toMatrix_z(RptrBTL),
                toMatrix_z(RptrBTR), toMatrix_z(RptrBBL),
                toMatrix_z(RptrBBR) );
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

SEXP merge2x2Dist_i( SEXP RptrA,
                     SEXP RptrBTL, SEXP RptrBTR,
                     SEXP RptrBBL, SEXP RptrBBR ){
  ElMerge2x2Dist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrBTL),
                    toDistMatrix_i(RptrBTR), toDistMatrix_i(RptrBBL),
                    toDistMatrix_i(RptrBBR) );
  return R_NilValue;
}

SEXP merge2x2Dist_z( SEXP RptrA,
                     SEXP RptrBTL, SEXP RptrBTR,
                     SEXP RptrBBL, SEXP RptrBBR ){
  ElMerge2x2Dist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrBTL),
                    toDistMatrix_z(RptrBTR), toDistMatrix_z(RptrBBL),
                    toDistMatrix_z(RptrBBR) );
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

SEXP lockedMerge2x2_i( SEXP RptrA,
                 SEXP RptrBTL, SEXP RptrBTR,
                 SEXP RptrBBL, SEXP RptrBBR ){
  ElLockedMerge2x2_i( toMatrix_i(RptrA), toMatrix_i(RptrBTL),
		      toMatrix_i(RptrBTR), toMatrix_i(RptrBBL),
		      toMatrix_i(RptrBBR) );
  return R_NilValue;
}

SEXP lockedMerge2x2_z( SEXP RptrA,
                 SEXP RptrBTL, SEXP RptrBTR,
                 SEXP RptrBBL, SEXP RptrBBR ){
  ElLockedMerge2x2_z( toMatrix_z(RptrA), toMatrix_z(RptrBTL),
		      toMatrix_z(RptrBTR), toMatrix_z(RptrBBL),
		      toMatrix_z(RptrBBR) );
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

SEXP lockedMerge2x2Dist_i( SEXP RptrA,
                     SEXP RptrBTL, SEXP RptrBTR,
                     SEXP RptrBBL, SEXP RptrBBR ){
  ElLockedMerge2x2Dist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrBTL),
			  toDistMatrix_i(RptrBTR), toDistMatrix_i(RptrBBL),
			  toDistMatrix_i(RptrBBR) );
  return R_NilValue;
}

SEXP lockedMerge2x2Dist_z( SEXP RptrA,
                     SEXP RptrBTL, SEXP RptrBTR,
                     SEXP RptrBBL, SEXP RptrBBR ){
  ElLockedMerge2x2Dist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrBTL),
			  toDistMatrix_z(RptrBTR), toDistMatrix_z(RptrBBL),
			  toDistMatrix_z(RptrBBR) );
  return R_NilValue;
}
