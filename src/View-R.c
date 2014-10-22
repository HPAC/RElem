#include "R-El.h"

SEXP view_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElView_d( toMatrix_d(RptrA), toMatrix_d(RptrB), parseRange_i(fromi, toi),
            parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP viewDist_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElViewDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedView_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedView_d( toMatrix_d(RptrA), toMatrix_d(RptrB), 
                  parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP lockedViewDist_d
( SEXP RptrA, SEXP RptrB, SEXP fromi, SEXP toi, SEXP fromj, SEXP toj ){
  ElLockedViewDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), 
                      parseRange_i(fromi, toi), parseRange_i(fromj, toj) );
  return R_NilValue;
}

SEXP viewOffset_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffset_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toElInt(i), toElInt(j),
                  toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP viewOffsetDist_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElViewOffsetDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB), toElInt(i),
                      toElInt(j), toElInt(height), toElInt(width) );
  return R_NilValue;
}

SEXP lockedViewOffset_d
( SEXP RptrA, SEXP RptrB, SEXP i, SEXP j, SEXP height, SEXP width){
  ElLockedViewOffset_d( toMatrix_d(RptrA), toMatrix_d(RptrB), toElInt(i), 
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

SEXP viewFull_d( SEXP RptrA, SEXP RptrB){
  ElViewFull_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP viewFullDist_d( SEXP RptrA, SEXP RptrB){
  ElViewFullDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFull_d( SEXP RptrA, SEXP RptrB){
  ElLockedViewFull_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP lockedViewFullDist_d( SEXP RptrA, SEXP RptrB){
  ElLockedViewFullDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}
