#include "R-El.h"

/*
Pending some
*/

/* Diagonal
 */

SEXP diagonal_d(SEXP RptrA, SEXP dSize, SEXP dBuf){
  ElDiagonal_d( toMatrix_d(RptrA), toElInt(dSize), toDouble_p(dBuf) );
  return R_NilValue;
}

SEXP diagonalDist_d(SEXP RptrA, SEXP dSize, SEXP dBuf){
  ElDiagonalDist_d( toDistMatrix_d(RptrA), toElInt(dSize), toDouble_p(dBuf) );
  return R_NilValue;
}


/*
Pending some
*/


/* Identity
 */
SEXP identity_d(SEXP RptrA, SEXP m, SEXP n){
  ElIdentity_d( toMatrix_d(RptrA), toElInt(m), toElInt(n) );
  return R_NilValue;
}

SEXP identityDist_d(SEXP RptrA, SEXP m, SEXP n){
  ElIdentityDist_d( toDistMatrix_d(RptrA), toElInt(m), toElInt(n) );
  return R_NilValue;
}

/*
Pending some
*/


/* Uniform
*/


SEXP uniform_d
( SEXP Rptr, SEXP height, SEXP width, SEXP center, SEXP radius){
  ElUniform_d( toMatrix_d(Rptr), toElInt(height), toElInt(width),
               toDouble(center), toDouble(radius) );
  return R_NilValue;
}

SEXP uniformDist_d
( SEXP Rptr, SEXP height, SEXP width, SEXP center, SEXP radius){
  ElUniformDist_d( toDistMatrix_d(Rptr), toElInt(height), toElInt(width),
                   toDouble(center), toDouble(radius) );
  return R_NilValue;
}

/*
Pending some
*/

/* Zeros
 */
SEXP zeros_d(SEXP RptrA, SEXP m, SEXP n){
  ElZeros_d( toMatrix_d(RptrA), toElInt(m), toElInt(n) );
  return R_NilValue;
}

SEXP zerosDist_d(SEXP RptrA, SEXP m, SEXP n){
  ElZerosDist_d( toDistMatrix_d(RptrA), toElInt(m), toElInt(n) );
  return R_NilValue;
}
