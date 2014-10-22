/*
#include "R-El.h"

SEXP repartitionDown_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElRepartitionDown_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                       toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP repartitionDownDist_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElRepartitionDownDist_d( toDistMatrix_d(RptrAT), toDistMatrix_d(RptrA0),
                           toDistMatrix_d(RptrA1), toDistMatrix_d(RptrAB),
                           toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP lockedRepartitionDown_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionDown_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                       toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP lockedRepartitionDownDist_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionDownDist_d( toDistMatrix_d(RptrAT), toDistMatrix_d(RptrA0),
                           toDistMatrix_d(RptrA1), toDistMatrix_d(RptrAB),
                           toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP repartitionUp_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElRepartitionUp_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                       toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP repartitionUpDist_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElRepartitionUpDist_d( toDistMatrix_d(RptrAT), toDistMatrix_d(RptrA0),
                           toDistMatrix_d(RptrA1), toDistMatrix_d(RptrAB),
                           toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP lockedRepartitionUp_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionUp_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                       toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP lockedRepartitionUpDist_d
( SEXP RptrAT, SEXP RptrA0, 
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionUpDist_d( toDistMatrix_d(RptrAT), toDistMatrix_d(RptrA0),
                           toDistMatrix_d(RptrA1), toDistMatrix_d(RptrAB),
                           toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP repartitionRight_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElRepartitionDown_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                       toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP repartitionRightDist_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElRepartitionRightDist_d( toDistMatrix_d(RptrAL), toDistMatrix_d(RptrAR),
                            toDistMatrix_d(RptrA0), toDistMatrix_d(RptrA1),
                            toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP lockedRepartitionRight_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionDown_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                       toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP lockedRepartitionRightDist_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionRightDist_d( toDistMatrix_d(RptrAL), toDistMatrix_d(RptrAR),
                            toDistMatrix_d(RptrA0), toDistMatrix_d(RptrA1),
                            toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP repartitionLeft_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElRepartitionDown_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                       toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP repartitionLeftDist_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElRepartitionLeftDist_d( toDistMatrix_d(RptrAL), toDistMatrix_d(RptrAR),
                            toDistMatrix_d(RptrA0), toDistMatrix_d(RptrA1),
                            toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP lockedRepartitionLeft_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionDown_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                       toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                       toMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}
                           
SEXP lockedRepartitionLeftDist_d
( SEXP RptrAL, SEXP RptrAR, 
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2, SEXP bsize ){
  ElLockedRepartitionLeftDist_d( toDistMatrix_d(RptrAL), toDistMatrix_d(RptrAR),
                            toDistMatrix_d(RptrA0), toDistMatrix_d(RptrA1),
                            toDistMatrix_d(RptrA2), toElInt(bsize) );
  return R_NilValue;
}

SEXP repartitionDownDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElRepartitionDownDiagonal_d( toMatrix_d(RptrATL),
                               toMatrix_d(RptrATR),
                               toMatrix_d(RptrA00),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA10),
                               toMatrix_d(RptrA11),
                               toMatrix_d(RptrA12),
                               toMatrix_d(RptrABL),
                               toMatrix_d(RptrABR),
                               toMatrix_d(RptrA20),
                               toMatrix_d(RptrA21),
                               toMatrix_d(RptrA22),
                               toElInt(bsize) );
  return R_NilValue;
}

SEXP repartitionDownDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElRepartitionDownDiagonalDist_d( toDistMatrix_d(RptrATL),
                                   toDistMatrix_d(RptrATR),
                                   toDistMatrix_d(RptrA00),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA10),
                                   toDistMatrix_d(RptrA11),
                                   toDistMatrix_d(RptrA12),
                                   toDistMatrix_d(RptrABL),
                                   toDistMatrix_d(RptrABR),
                                   toDistMatrix_d(RptrA20),
                                   toDistMatrix_d(RptrA21),
                                   toDistMatrix_d(RptrA22),
                                   toElInt(bsize) );
  return R_NilValue;
}


SEXP lockedRepartitionDownDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElLockedRepartitionDownDiagonal_d( toMatrix_d(RptrATL),
                               toMatrix_d(RptrATR),
                               toMatrix_d(RptrA00),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA10),
                               toMatrix_d(RptrA11),
                               toMatrix_d(RptrA12),
                               toMatrix_d(RptrABL),
                               toMatrix_d(RptrABR),
                               toMatrix_d(RptrA20),
                               toMatrix_d(RptrA21),
                               toMatrix_d(RptrA22),
                               toElInt(bsize) );
  return R_NilValue;
}

SEXP lockedRepartitionDownDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElLockedRepartitionDownDiagonalDist_d( toDistMatrix_d(RptrATL),
                                   toDistMatrix_d(RptrATR),
                                   toDistMatrix_d(RptrA00),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA10),
                                   toDistMatrix_d(RptrA11),
                                   toDistMatrix_d(RptrA12),
                                   toDistMatrix_d(RptrABL),
                                   toDistMatrix_d(RptrABR),
                                   toDistMatrix_d(RptrA20),
                                   toDistMatrix_d(RptrA21),
                                   toDistMatrix_d(RptrA22),
                                   toElInt(bsize) );
  return R_NilValue;
}


SEXP repartitionUpDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElRepartitionUpDiagonal_d( toMatrix_d(RptrATL),
                               toMatrix_d(RptrATR),
                               toMatrix_d(RptrA00),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA10),
                               toMatrix_d(RptrA11),
                               toMatrix_d(RptrA12),
                               toMatrix_d(RptrABL),
                               toMatrix_d(RptrABR),
                               toMatrix_d(RptrA20),
                               toMatrix_d(RptrA21),
                               toMatrix_d(RptrA22),
                               toElInt(bsize) );
  return R_NilValue;
}

SEXP repartitionUpDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElRepartitionUpDiagonalDist_d( toDistMatrix_d(RptrATL),
                                   toDistMatrix_d(RptrATR),
                                   toDistMatrix_d(RptrA00),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA10),
                                   toDistMatrix_d(RptrA11),
                                   toDistMatrix_d(RptrA12),
                                   toDistMatrix_d(RptrABL),
                                   toDistMatrix_d(RptrABR),
                                   toDistMatrix_d(RptrA20),
                                   toDistMatrix_d(RptrA21),
                                   toDistMatrix_d(RptrA22),
                                   toElInt(bsize) );
  return R_NilValue;
}


SEXP lockedRepartitionUpDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElLockedRepartitionUpDiagonal_d( toMatrix_d(RptrATL),
                               toMatrix_d(RptrATR),
                               toMatrix_d(RptrA00),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA01),
                               toMatrix_d(RptrA10),
                               toMatrix_d(RptrA11),
                               toMatrix_d(RptrA12),
                               toMatrix_d(RptrABL),
                               toMatrix_d(RptrABR),
                               toMatrix_d(RptrA20),
                               toMatrix_d(RptrA21),
                               toMatrix_d(RptrA22),
                               toElInt(bsize) );
  return R_NilValue;
}

SEXP lockedRepartitionUpDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22,
  SEXP bsize ){
  ElLockedRepartitionUpDiagonalDist_d( toDistMatrix_d(RptrATL),
                                   toDistMatrix_d(RptrATR),
                                   toDistMatrix_d(RptrA00),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA01),
                                   toDistMatrix_d(RptrA10),
                                   toDistMatrix_d(RptrA11),
                                   toDistMatrix_d(RptrA12),
                                   toDistMatrix_d(RptrABL),
                                   toDistMatrix_d(RptrABR),
                                   toDistMatrix_d(RptrA20),
                                   toDistMatrix_d(RptrA21),
                                   toDistMatrix_d(RptrA22),
                                   toElInt(bsize) );
  return R_NilValue;
}
*/
