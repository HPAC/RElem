#include "R-El.h"

SEXP partitionDown_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDown_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                     toMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionDownDist_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDownDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                         toDistMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}
 
SEXP lockedPartitionDown_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDown_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                           toMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP lockedPartitionDownDist_d
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDownDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                               toDistMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}


SEXP partitionUp_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUp_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                     toMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionUpDist_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUpDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                         toDistMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}
 
SEXP lockedPartitionUp_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUp_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                           toMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP lockedPartitionUpDist_d
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUpDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                               toDistMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}



SEXP partitionLeft_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeft_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                     toMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionLeftDist_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeftDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                         toDistMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}
 
SEXP lockedPartitionLeft_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeft_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                           toMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP lockedPartitionLeftDist_d
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeftDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                               toDistMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}


SEXP partitionRight_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRight_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                     toMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionRightDist_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRightDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                         toDistMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}
 
SEXP lockedPartitionRight_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRight_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                           toMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP lockedPartitionRightDist_d
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRightDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                               toDistMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionDownDiagonal_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionDownDiagonal_d( toMatrix_d(RptrA), 
                             toMatrix_d(RptrATL), toMatrix_d(RptrATR),
                             toMatrix_d(RptrABL), toMatrix_d(RptrABR),
                             toElInt(diag) );
  return R_NilValue;
}

SEXP partitionDownDiagonalDist_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionDownDiagonalDist_d( toDistMatrix_d(RptrA),
                                 toDistMatrix_d(RptrATL),
                                 toDistMatrix_d(RptrATR),
                                 toDistMatrix_d(RptrABL),
                                 toDistMatrix_d(RptrABR),
                                 toElInt(diagDist) );
  return R_NilValue;
}


SEXP lockedPartitionDownDiagonal_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionDownDiagonal_d( toMatrix_d(RptrA), 
                                   toMatrix_d(RptrATL), toMatrix_d(RptrATR),
                                   toMatrix_d(RptrABL), toMatrix_d(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}

SEXP lockedPartitionDownDiagonalDist_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionDownDiagonalDist_d( toDistMatrix_d(RptrA),
                                       toDistMatrix_d(RptrATL),
                                       toDistMatrix_d(RptrATR),
                                       toDistMatrix_d(RptrABL),
                                       toDistMatrix_d(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionDownOffSetDiagonal_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionDownOffsetDiagonal_d( toElInt(offset),
                                   toMatrix_d(RptrA),
                                   toMatrix_d(RptrATL),
                                   toMatrix_d(RptrATR),
                                   toMatrix_d(RptrABL),
                                   toMatrix_d(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}

SEXP partitionDownOffSetDiagonalDist_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionDownOffsetDiagonalDist_d( toElInt(offset),
                                       toDistMatrix_d(RptrA),
                                       toDistMatrix_d(RptrATL),
                                       toDistMatrix_d(RptrATR),
                                       toDistMatrix_d(RptrABL),
                                       toDistMatrix_d(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP lockedPartitionDownOffSetDiagonal_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionDownOffsetDiagonal_d( toElInt(offset),
                                         toMatrix_d(RptrA),
                                         toMatrix_d(RptrATL),
                                         toMatrix_d(RptrATR),
                                         toMatrix_d(RptrABL),
                                         toMatrix_d(RptrABR),
                                         toElInt(diag) );
  return R_NilValue;
}

SEXP lockedPartitionDownOffSetDiagonalDist_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionDownOffsetDiagonalDist_d( toElInt(offset),
                                             toDistMatrix_d(RptrA),
                                             toDistMatrix_d(RptrATL),
                                             toDistMatrix_d(RptrATR),
                                             toDistMatrix_d(RptrABL),
                                             toDistMatrix_d(RptrABR),
                                             toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionUpDiagonal_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionUpDiagonal_d( toMatrix_d(RptrA), 
                             toMatrix_d(RptrATL), toMatrix_d(RptrATR),
                             toMatrix_d(RptrABL), toMatrix_d(RptrABR),
                             toElInt(diag) );
  return R_NilValue;
}

SEXP partitionUpDiagonalDist_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionUpDiagonalDist_d( toDistMatrix_d(RptrA),
                                 toDistMatrix_d(RptrATL),
                                 toDistMatrix_d(RptrATR),
                                 toDistMatrix_d(RptrABL),
                                 toDistMatrix_d(RptrABR),
                                 toElInt(diagDist) );
  return R_NilValue;
}


SEXP lockedPartitionUpDiagonal_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionUpDiagonal_d( toMatrix_d(RptrA), 
                                   toMatrix_d(RptrATL), toMatrix_d(RptrATR),
                                   toMatrix_d(RptrABL), toMatrix_d(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}

SEXP lockedPartitionUpDiagonalDist_d
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionUpDiagonalDist_d( toDistMatrix_d(RptrA),
                                       toDistMatrix_d(RptrATL),
                                       toDistMatrix_d(RptrATR),
                                       toDistMatrix_d(RptrABL),
                                       toDistMatrix_d(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionUpOffSetDiagonal_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionUpOffsetDiagonal_d( toElInt(offset),
                                   toMatrix_d(RptrA),
                                   toMatrix_d(RptrATL),
                                   toMatrix_d(RptrATR),
                                   toMatrix_d(RptrABL),
                                   toMatrix_d(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}

SEXP partitionUpOffSetDiagonalDist_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionUpOffsetDiagonalDist_d( toElInt(offset),
                                       toDistMatrix_d(RptrA),
                                       toDistMatrix_d(RptrATL),
                                       toDistMatrix_d(RptrATR),
                                       toDistMatrix_d(RptrABL),
                                       toDistMatrix_d(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP lockedPartitionUpOffSetDiagonal_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionUpOffsetDiagonal_d( toElInt(offset),
                                         toMatrix_d(RptrA),
                                         toMatrix_d(RptrATL),
                                         toMatrix_d(RptrATR),
                                         toMatrix_d(RptrABL),
                                         toMatrix_d(RptrABR),
                                         toElInt(diag) );
  return R_NilValue;
}

SEXP lockedPartitionUpOffSetDiagonalDist_d
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionUpOffsetDiagonalDist_d( toElInt(offset),
                                             toDistMatrix_d(RptrA),
                                             toDistMatrix_d(RptrATL),
                                             toDistMatrix_d(RptrATR),
                                             toDistMatrix_d(RptrABL),
                                             toDistMatrix_d(RptrABR),
                                             toElInt(diagDist) );
  return R_NilValue;
}
