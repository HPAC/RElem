#include "R-El.h"

SEXP partitionDown_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDown_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                     toMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionDown_i( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDown_i( toMatrix_i(RptrA), toMatrix_i(RptrAT),
                     toMatrix_i(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionDown_z( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDown_z( toMatrix_z(RptrA), toMatrix_z(RptrAT),
                     toMatrix_z(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionDownDist_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDownDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                         toDistMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionDownDist_i( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDownDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAT),
                         toDistMatrix_i(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionDownDist_z( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElPartitionDownDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAT),
                         toDistMatrix_z(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}
 
SEXP lockedPartitionDown_d
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDown_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                           toMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}
 
SEXP lockedPartitionDown_i
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDown_i( toMatrix_i(RptrA), toMatrix_i(RptrAT),
                           toMatrix_i(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}
 
SEXP lockedPartitionDown_z
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDown_z( toMatrix_z(RptrA), toMatrix_z(RptrAT),
                           toMatrix_z(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP lockedPartitionDownDist_d
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDownDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                               toDistMatrix_d(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP lockedPartitionDownDist_i
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDownDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAT),
                               toDistMatrix_i(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP lockedPartitionDownDist_z
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAT){
  ElLockedPartitionDownDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAT),
                               toDistMatrix_z(RptrAB), toElInt(heightAT) );
  return R_NilValue;
}

SEXP partitionUp_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUp_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                     toMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionUp_i( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUp_i( toMatrix_i(RptrA), toMatrix_i(RptrAT),
                     toMatrix_i(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionUp_z( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUp_z( toMatrix_z(RptrA), toMatrix_z(RptrAT),
                     toMatrix_z(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionUpDist_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUpDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                         toDistMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionUpDist_i( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUpDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAT),
                         toDistMatrix_i(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionUpDist_z( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElPartitionUpDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAT),
                         toDistMatrix_z(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}
 
SEXP lockedPartitionUp_d( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUp_d( toMatrix_d(RptrA), toMatrix_d(RptrAT),
                           toMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}
 
SEXP lockedPartitionUp_i( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUp_i( toMatrix_i(RptrA), toMatrix_i(RptrAT),
                           toMatrix_i(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}
 
SEXP lockedPartitionUp_z( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUp_z( toMatrix_z(RptrA), toMatrix_z(RptrAT),
                           toMatrix_z(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP lockedPartitionUpDist_d
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUpDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAT),
                               toDistMatrix_d(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP lockedPartitionUpDist_i
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUpDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAT),
                               toDistMatrix_i(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP lockedPartitionUpDist_z
( SEXP RptrA, SEXP RptrAT, SEXP RptrAB, SEXP heightAB){
  ElLockedPartitionUpDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAT),
                               toDistMatrix_z(RptrAB), toElInt(heightAB) );
  return R_NilValue;
}

SEXP partitionLeft_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeft_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                     toMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionLeft_i( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeft_i( toMatrix_i(RptrA), toMatrix_i(RptrAL),
                     toMatrix_i(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionLeft_z( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeft_z( toMatrix_z(RptrA), toMatrix_z(RptrAL),
                     toMatrix_z(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionLeftDist_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeftDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                         toDistMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionLeftDist_i( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeftDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAL),
                         toDistMatrix_i(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionLeftDist_z( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElPartitionLeftDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAL),
                         toDistMatrix_z(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}
 
SEXP lockedPartitionLeft_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeft_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                           toMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}
 
SEXP lockedPartitionLeft_i( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeft_i( toMatrix_i(RptrA), toMatrix_i(RptrAL),
                           toMatrix_i(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}
 
SEXP lockedPartitionLeft_z( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeft_z( toMatrix_z(RptrA), toMatrix_z(RptrAL),
                           toMatrix_z(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP lockedPartitionLeftDist_d
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeftDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                               toDistMatrix_d(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP lockedPartitionLeftDist_i
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeftDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAL),
                               toDistMatrix_i(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP lockedPartitionLeftDist_z
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAR){
  ElLockedPartitionLeftDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAL),
                               toDistMatrix_z(RptrAR), toElInt(widthAR) );
  return R_NilValue;
}

SEXP partitionRight_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRight_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                     toMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionRight_i( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRight_i( toMatrix_i(RptrA), toMatrix_i(RptrAL),
                     toMatrix_i(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionRight_z( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRight_z( toMatrix_z(RptrA), toMatrix_z(RptrAL),
                     toMatrix_z(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionRightDist_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRightDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                         toDistMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionRightDist_i( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRightDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAL),
                         toDistMatrix_i(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP partitionRightDist_z( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElPartitionRightDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAL),
                         toDistMatrix_z(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}
  
SEXP lockedPartitionRight_d( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRight_d( toMatrix_d(RptrA), toMatrix_d(RptrAL),
                           toMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}
 
SEXP lockedPartitionRight_i( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRight_i( toMatrix_i(RptrA), toMatrix_i(RptrAL),
                           toMatrix_i(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}
 
SEXP lockedPartitionRight_z( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRight_z( toMatrix_z(RptrA), toMatrix_z(RptrAL),
                           toMatrix_z(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP lockedPartitionRightDist_d
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRightDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrAL),
                               toDistMatrix_d(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP lockedPartitionRightDist_i
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRightDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrAL),
                               toDistMatrix_i(RptrAR), toElInt(widthAL) );
  return R_NilValue;
}

SEXP lockedPartitionRightDist_z
( SEXP RptrA, SEXP RptrAL, SEXP RptrAR, SEXP widthAL){
  ElLockedPartitionRightDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrAL),
                               toDistMatrix_z(RptrAR), toElInt(widthAL) );
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

SEXP partitionDownDiagonal_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionDownDiagonal_i( toMatrix_i(RptrA), 
                             toMatrix_i(RptrATL), toMatrix_i(RptrATR),
                             toMatrix_i(RptrABL), toMatrix_i(RptrABR),
                             toElInt(diag) );
  return R_NilValue;
}

SEXP partitionDownDiagonal_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionDownDiagonal_z( toMatrix_z(RptrA), 
                             toMatrix_z(RptrATL), toMatrix_z(RptrATR),
                             toMatrix_z(RptrABL), toMatrix_z(RptrABR),
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

SEXP partitionDownDiagonalDist_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionDownDiagonalDist_i( toDistMatrix_i(RptrA),
                                 toDistMatrix_i(RptrATL),
                                 toDistMatrix_i(RptrATR),
                                 toDistMatrix_i(RptrABL),
                                 toDistMatrix_i(RptrABR),
                                 toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionDownDiagonalDist_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionDownDiagonalDist_z( toDistMatrix_z(RptrA),
                                 toDistMatrix_z(RptrATL),
                                 toDistMatrix_z(RptrATR),
                                 toDistMatrix_z(RptrABL),
                                 toDistMatrix_z(RptrABR),
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


SEXP lockedPartitionDownDiagonal_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionDownDiagonal_i( toMatrix_i(RptrA), 
                                   toMatrix_i(RptrATL), toMatrix_i(RptrATR),
                                   toMatrix_i(RptrABL), toMatrix_i(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}


SEXP lockedPartitionDownDiagonal_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionDownDiagonal_z( toMatrix_z(RptrA), 
                                   toMatrix_z(RptrATL), toMatrix_z(RptrATR),
                                   toMatrix_z(RptrABL), toMatrix_z(RptrABR),
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

SEXP lockedPartitionDownDiagonalDist_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionDownDiagonalDist_i( toDistMatrix_i(RptrA),
                                       toDistMatrix_i(RptrATL),
                                       toDistMatrix_i(RptrATR),
                                       toDistMatrix_i(RptrABL),
                                       toDistMatrix_i(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP lockedPartitionDownDiagonalDist_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionDownDiagonalDist_z( toDistMatrix_z(RptrA),
                                       toDistMatrix_z(RptrATL),
                                       toDistMatrix_z(RptrATR),
                                       toDistMatrix_z(RptrABL),
                                       toDistMatrix_z(RptrABR),
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

SEXP partitionDownOffSetDiagonal_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionDownOffsetDiagonal_i( toElInt(offset),
                                   toMatrix_i(RptrA),
                                   toMatrix_i(RptrATL),
                                   toMatrix_i(RptrATR),
                                   toMatrix_i(RptrABL),
                                   toMatrix_i(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}

SEXP partitionDownOffSetDiagonal_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionDownOffsetDiagonal_z( toElInt(offset),
                                   toMatrix_z(RptrA),
                                   toMatrix_z(RptrATL),
                                   toMatrix_z(RptrATR),
                                   toMatrix_z(RptrABL),
                                   toMatrix_z(RptrABR),
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

SEXP partitionDownOffSetDiagonalDist_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionDownOffsetDiagonalDist_i( toElInt(offset),
                                       toDistMatrix_i(RptrA),
                                       toDistMatrix_i(RptrATL),
                                       toDistMatrix_i(RptrATR),
                                       toDistMatrix_i(RptrABL),
                                       toDistMatrix_i(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionDownOffSetDiagonalDist_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionDownOffsetDiagonalDist_z( toElInt(offset),
                                       toDistMatrix_z(RptrA),
                                       toDistMatrix_z(RptrATL),
                                       toDistMatrix_z(RptrATR),
                                       toDistMatrix_z(RptrABL),
                                       toDistMatrix_z(RptrABR),
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

SEXP lockedPartitionDownOffSetDiagonal_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionDownOffsetDiagonal_i( toElInt(offset),
                                         toMatrix_i(RptrA),
                                         toMatrix_i(RptrATL),
                                         toMatrix_i(RptrATR),
                                         toMatrix_i(RptrABL),
                                         toMatrix_i(RptrABR),
                                         toElInt(diag) );
  return R_NilValue;
}

SEXP lockedPartitionDownOffSetDiagonal_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionDownOffsetDiagonal_z( toElInt(offset),
                                         toMatrix_z(RptrA),
                                         toMatrix_z(RptrATL),
                                         toMatrix_z(RptrATR),
                                         toMatrix_z(RptrABL),
                                         toMatrix_z(RptrABR),
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

SEXP lockedPartitionDownOffSetDiagonalDist_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionDownOffsetDiagonalDist_i( toElInt(offset),
                                             toDistMatrix_i(RptrA),
                                             toDistMatrix_i(RptrATL),
                                             toDistMatrix_i(RptrATR),
                                             toDistMatrix_i(RptrABL),
                                             toDistMatrix_i(RptrABR),
                                             toElInt(diagDist) );
  return R_NilValue;
}

SEXP lockedPartitionDownOffSetDiagonalDist_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionDownOffsetDiagonalDist_z( toElInt(offset),
                                             toDistMatrix_z(RptrA),
                                             toDistMatrix_z(RptrATL),
                                             toDistMatrix_z(RptrATR),
                                             toDistMatrix_z(RptrABL),
                                             toDistMatrix_z(RptrABR),
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

SEXP partitionUpDiagonal_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionUpDiagonal_i( toMatrix_i(RptrA), 
                             toMatrix_i(RptrATL), toMatrix_i(RptrATR),
                             toMatrix_i(RptrABL), toMatrix_i(RptrABR),
                             toElInt(diag) );
  return R_NilValue;
}

SEXP partitionUpDiagonal_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionUpDiagonal_z( toMatrix_z(RptrA), 
                             toMatrix_z(RptrATL), toMatrix_z(RptrATR),
                             toMatrix_z(RptrABL), toMatrix_z(RptrABR),
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

SEXP partitionUpDiagonalDist_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionUpDiagonalDist_i( toDistMatrix_i(RptrA),
                                 toDistMatrix_i(RptrATL),
                                 toDistMatrix_i(RptrATR),
                                 toDistMatrix_i(RptrABL),
                                 toDistMatrix_i(RptrABR),
                                 toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionUpDiagonalDist_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionUpDiagonalDist_z( toDistMatrix_z(RptrA),
                                 toDistMatrix_z(RptrATL),
                                 toDistMatrix_z(RptrATR),
                                 toDistMatrix_z(RptrABL),
                                 toDistMatrix_z(RptrABR),
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


SEXP lockedPartitionUpDiagonal_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionUpDiagonal_i( toMatrix_i(RptrA), 
                                   toMatrix_i(RptrATL), toMatrix_i(RptrATR),
                                   toMatrix_i(RptrABL), toMatrix_i(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}


SEXP lockedPartitionUpDiagonal_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionUpDiagonal_z( toMatrix_z(RptrA), 
                                   toMatrix_z(RptrATL), toMatrix_z(RptrATR),
                                   toMatrix_z(RptrABL), toMatrix_z(RptrABR),
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

SEXP lockedPartitionUpDiagonalDist_i
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionUpDiagonalDist_i( toDistMatrix_i(RptrA),
                                       toDistMatrix_i(RptrATL),
                                       toDistMatrix_i(RptrATR),
                                       toDistMatrix_i(RptrABL),
                                       toDistMatrix_i(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP lockedPartitionUpDiagonalDist_z
( SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionUpDiagonalDist_z( toDistMatrix_z(RptrA),
                                       toDistMatrix_z(RptrATL),
                                       toDistMatrix_z(RptrATR),
                                       toDistMatrix_z(RptrABL),
                                       toDistMatrix_z(RptrABR),
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

SEXP partitionUpOffSetDiagonal_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionUpOffsetDiagonal_i( toElInt(offset),
                                   toMatrix_i(RptrA),
                                   toMatrix_i(RptrATL),
                                   toMatrix_i(RptrATR),
                                   toMatrix_i(RptrABL),
                                   toMatrix_i(RptrABR),
                                   toElInt(diag) );
  return R_NilValue;
}

SEXP partitionUpOffSetDiagonal_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElPartitionUpOffsetDiagonal_z( toElInt(offset),
                                   toMatrix_z(RptrA),
                                   toMatrix_z(RptrATL),
                                   toMatrix_z(RptrATR),
                                   toMatrix_z(RptrABL),
                                   toMatrix_z(RptrABR),
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

SEXP partitionUpOffSetDiagonalDist_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionUpOffsetDiagonalDist_i( toElInt(offset),
                                       toDistMatrix_i(RptrA),
                                       toDistMatrix_i(RptrATL),
                                       toDistMatrix_i(RptrATR),
                                       toDistMatrix_i(RptrABL),
                                       toDistMatrix_i(RptrABR),
                                       toElInt(diagDist) );
  return R_NilValue;
}

SEXP partitionUpOffSetDiagonalDist_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElPartitionUpOffsetDiagonalDist_z( toElInt(offset),
                                       toDistMatrix_z(RptrA),
                                       toDistMatrix_z(RptrATL),
                                       toDistMatrix_z(RptrATR),
                                       toDistMatrix_z(RptrABL),
                                       toDistMatrix_z(RptrABR),
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

SEXP lockedPartitionUpOffSetDiagonal_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionUpOffsetDiagonal_i( toElInt(offset),
                                         toMatrix_i(RptrA),
                                         toMatrix_i(RptrATL),
                                         toMatrix_i(RptrATR),
                                         toMatrix_i(RptrABL),
                                         toMatrix_i(RptrABR),
                                         toElInt(diag) );
  return R_NilValue;
}

SEXP lockedPartitionUpOffSetDiagonal_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diag ){
  ElLockedPartitionUpOffsetDiagonal_z( toElInt(offset),
                                         toMatrix_z(RptrA),
                                         toMatrix_z(RptrATL),
                                         toMatrix_z(RptrATR),
                                         toMatrix_z(RptrABL),
                                         toMatrix_z(RptrABR),
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

SEXP lockedPartitionUpOffSetDiagonalDist_i
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionUpOffsetDiagonalDist_i( toElInt(offset),
                                             toDistMatrix_i(RptrA),
                                             toDistMatrix_i(RptrATL),
                                             toDistMatrix_i(RptrATR),
                                             toDistMatrix_i(RptrABL),
                                             toDistMatrix_i(RptrABR),
                                             toElInt(diagDist) );
  return R_NilValue;
}

SEXP lockedPartitionUpOffSetDiagonalDist_z
( SEXP offset, SEXP RptrA,
  SEXP RptrATL, SEXP RptrATR,
  SEXP RptrABL, SEXP RptrABR, SEXP diagDist ){
  ElLockedPartitionUpOffsetDiagonalDist_z( toElInt(offset),
                                             toDistMatrix_z(RptrA),
                                             toDistMatrix_z(RptrATL),
                                             toDistMatrix_z(RptrATR),
                                             toDistMatrix_z(RptrABL),
                                             toDistMatrix_z(RptrABR),
                                             toElInt(diagDist) );
  return R_NilValue;
}
