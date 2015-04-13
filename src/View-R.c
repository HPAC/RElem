#include "R-El.h"

SEXP view_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElView_d( toMatrix_d(RptrA), toMatrix_d(RptrB), parseRange_i(fromi, toi),
            parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP view_i
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElView_i( toMatrix_i(RptrA), toMatrix_i(RptrB), parseRange_i(fromi, toi),
            parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP view_z
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElView_z( toMatrix_z(RptrA), toMatrix_z(RptrB), parseRange_i(fromi, toi),
            parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP viewDist_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElViewDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP viewDist_i
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElViewDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrB), 
                parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP viewDist_z
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElViewDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), 
                parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedView_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedView_d( toMatrix_d(RptrA), toMatrix_d(RptrB), 
                  parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedView_i
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedView_i( toMatrix_i(RptrA), toMatrix_i(RptrB), 
                  parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedView_z
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedView_z( toMatrix_z(RptrA), toMatrix_z(RptrB), 
                  parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedViewDist_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedViewDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                      parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedViewDist_i
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedViewDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrB), 
                      parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedViewDist_z
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedViewDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), 
                      parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP viewOffset_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffset_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toElInt(i), toElInt(j),
                  toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP viewOffset_i
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffset_i( toMatrix_i(RptrA), toMatrix_i(RptrB), toElInt(i), toElInt(j),
                  toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP viewOffset_z
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffset_z( toMatrix_z(RptrA), toMatrix_z(RptrB), toElInt(i), toElInt(j),
                  toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP viewOffsetDist_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffsetDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toElInt(i),
                      toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP viewOffsetDist_i
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffsetDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrB), toElInt(i),
                      toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP viewOffsetDist_z
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffsetDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB), toElInt(i),
                      toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffset_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffset_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toElInt(i), 
                        toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffset_i
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffset_i( toMatrix_i(RptrA), toMatrix_i(RptrB), toElInt(i), 
                        toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffset_z
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffset_z( toMatrix_z(RptrA), toMatrix_z(RptrB), toElInt(i), 
                        toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffsetDist_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffsetDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB),
                            toElInt(i), toElInt(j), toElInt(height),
                            toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffsetDist_i
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffsetDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrB),
                            toElInt(i), toElInt(j), toElInt(height),
                            toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffsetDist_z
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffsetDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
                            toElInt(i), toElInt(j), toElInt(height),
                            toElInt(width) );
  return R_NilValue;
}

SEXP viewFull_d( SEXP RptrA, SEXP RptrB){
  ElViewFull_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP viewFull_i( SEXP RptrA, SEXP RptrB){
  ElViewFull_i( toMatrix_i(RptrA), toMatrix_i(RptrB) );
  return R_NilValue;
}

SEXP viewFull_z( SEXP RptrA, SEXP RptrB){
  ElViewFull_z( toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP viewFullDist_d( SEXP RptrA, SEXP RptrB){
  ElViewFullDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP viewFullDist_i( SEXP RptrA, SEXP RptrB){
  ElViewFullDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrB) );
  return R_NilValue;
}

SEXP viewFullDist_z( SEXP RptrA, SEXP RptrB){
  ElViewFullDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFull_d( SEXP RptrA, SEXP RptrB){
  ElLockedViewFull_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFull_i( SEXP RptrA, SEXP RptrB){
  ElLockedViewFull_i( toMatrix_i(RptrA), toMatrix_i(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFull_z( SEXP RptrA, SEXP RptrB){
  ElLockedViewFull_z( toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFullDist_d( SEXP RptrA, SEXP RptrB){
  ElLockedViewFullDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFullDist_i( SEXP RptrA, SEXP RptrB){
  ElLockedViewFullDist_i( toDistMatrix_i(RptrA), toDistMatrix_i(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFullDist_z( SEXP RptrA, SEXP RptrB){
  ElLockedViewFullDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}
