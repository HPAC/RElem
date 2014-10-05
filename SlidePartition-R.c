/*
#include "R-El.h"

SEXP slidePartitionDown_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlidePartitionDown_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                          toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                          toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slidePartitionDownDist_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlidePartitionDownDist_d( toDistMatrix_d(RptrAT), toDistMatrix_d(RptrA0),
                              toDistMatrix_d(RptrA1), toDistMatrix_d(RptrAB),
                              toDistMatrix_d(RptrA2) );
  return R_NilValue;
}
*/
/*
SEXP slideLockedPartitionDown_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlideLockedPartitionDown_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                                toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                                toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionDownDist_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlideLockedPartitionDownDist_d( toDistMatrix_d(RptrAT),
                                    toDistMatrix_d(RptrA0),
                                    toDistMatrix_d(RptrA1),
                                    toDistMatrix_d(RptrAB),
                                    toDistMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slidePartitionUp_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlidePartitionUp_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                        toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                        toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slidePartitionUpDist_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlidePartitionUpDist_d( toDistMatrix_d(RptrAT), toDistMatrix_d(RptrA0),
                            toDistMatrix_d(RptrA1), toDistMatrix_d(RptrAB),
                            toDistMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionUp_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlideLockedPartitionUp_d( toMatrix_d(RptrAT), toMatrix_d(RptrA0),
                              toMatrix_d(RptrA1), toMatrix_d(RptrAB),
                              toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionUpDist_d
( SEXP RptrAT, SEXP RptrA0,
               SEXP RptrA1,
  SEXP RptrAB, SEXP RptrA2 ){
  ElSlideLockedPartitionUpDist_d( toDistMatrix_d(RptrAT),
                                    toDistMatrix_d(RptrA0),
                                    toDistMatrix_d(RptrA1),
                                    toDistMatrix_d(RptrAB),
                                    toDistMatrix_d(RptrA2) );
  return R_NilValue;
}


SEXP slidePartitionRight_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlidePartitionRight_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                           toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                           toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slidePartitionRightDist_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlidePartitionRightDist_d( toDistMatrix_d(RptrAL), toDistMatrix_d(RptrAR),
                               toDistMatrix_d(RptrA0), toDistMatrix_d(RptrA1),
                               toDistMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionRight_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlideLockedPartitionRight_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                                 toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                                 toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionRightDist_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlideLockedPartitionRightDist_d( toDistMatrix_d(RptrAL),
                                     toDistMatrix_d(RptrAR),
                                     toDistMatrix_d(RptrA0),
                                     toDistMatrix_d(RptrA1),
                                     toDistMatrix_d(RptrA2) );
  return R_NilValue;
}



SEXP slidePartitionLeft_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlidePartitionLeft_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                          toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                          toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slidePartitionLeftDist_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlidePartitionLeftDist_d( toDistMatrix_d(RptrAL), toDistMatrix_d(RptrAR),
                               toDistMatrix_d(RptrA0), toDistMatrix_d(RptrA1),
                               toDistMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionLeft_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlideLockedPartitionLeft_d( toMatrix_d(RptrAL), toMatrix_d(RptrAR),
                                 toMatrix_d(RptrA0), toMatrix_d(RptrA1),
                                 toMatrix_d(RptrA2) );
  return R_NilValue;
}

SEXP slideLockedPartitionLeftDist_d
( SEXP RptrAL, SEXP RptrAR,
  SEXP RptrA0, SEXP RptrA1, SEXP RptrA2 ){
  ElSlideLockedPartitionLeftDist_d( toDistMatrix_d(RptrAL),
                                    toDistMatrix_d(RptrAR),
                                    toDistMatrix_d(RptrA0),
                                    toDistMatrix_d(RptrA1),
                                    toDistMatrix_d(RptrA2) );
  return R_NilValue;
}


SEXP slidePartitionDownDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlidePartitionDownDiagonal_d( toMatrix_d(RptrATL), toMatrix_d(RptrATR),
                                  toMatrix_d(RptrA00), toMatrix_d(RptrA01),
                                  toMatrix_d(RptrA01), toMatrix_d(RptrA10),
                                  toMatrix_d(RptrA11), toMatrix_d(RptrA12),
                                  toMatrix_d(RptrABL), toMatrix_d(RptrABR),
                                  toMatrix_d(RptrA20), toMatrix_d(RptrA21),
                                  toMatrix_d(RptrA22) );
  return R_NilValue;
}

SEXP slidePartitionDownDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlidePartitionDownDiagonalDist_d( toDistMatrix_d(RptrATL),
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
                                      toDistMatrix_d(RptrA22) );
  return R_NilValue;
}


SEXP slideLockedPartitionDownDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlideLockedPartitionDownDiagonal_d( toMatrix_d(RptrATL),
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
                                        toMatrix_d(RptrA22) );
  return R_NilValue;
}

SEXP slideLockedPartitionDownDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlideLockedPartitionDownDiagonalDist_d( toDistMatrix_d(RptrATL),
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
                                            toDistMatrix_d(RptrA22) );
  return R_NilValue;
}


SEXP slidePartitionUpDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlidePartitionUpDiagonal_d( toMatrix_d(RptrATL), toMatrix_d(RptrATR),
                                toMatrix_d(RptrA00), toMatrix_d(RptrA01),
                                toMatrix_d(RptrA01), toMatrix_d(RptrA10),
                                toMatrix_d(RptrA11), toMatrix_d(RptrA12),
                                toMatrix_d(RptrABL), toMatrix_d(RptrABR),
                                toMatrix_d(RptrA20), toMatrix_d(RptrA21),
                                toMatrix_d(RptrA22) );
  return R_NilValue;
}

SEXP slidePartitionUpDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlidePartitionUpDiagonalDist_d( toDistMatrix_d(RptrATL),
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
                                    toDistMatrix_d(RptrA22) );
  return R_NilValue;
}


SEXP slideLockedPartitionUpDiagonal_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlideLockedPartitionUpDiagonal_d( toMatrix_d(RptrATL),
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
                                        toMatrix_d(RptrA22) );
  return R_NilValue;
}

SEXP slideLockedPartitionUpDiagonalDist_d
( SEXP RptrATL, SEXP RptrATR, SEXP RptrA00, SEXP RptrA01, SEXP RptrA02,
                              SEXP RptrA10, SEXP RptrA11, SEXP RptrA12,
  SEXP RptrABL, SEXP RptrABR, SEXP RptrA20, SEXP RptrA21, SEXP RptrA22 ){
  ElSlideLockedPartitionUpDiagonalDist_d( toDistMatrix_d(RptrATL),
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
                                          toDistMatrix_d(RptrA22) );
  return R_NilValue;
}
*/
