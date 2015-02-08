#include "R-El.h"

/* Linear Programs
 */

SEXP lPDirect_d
( SEXP MatrixA, SEXP Matrixb, SEXP Matrixc, SEXP Matrixx, SEXP Matrixy,
  SEXP Matrixz){
  ElLPDirect_d(toMatrix_d(MatrixA), toMatrix_d(Matrixb),
	       toMatrix_d(Matrixc), toMatrix_d(Matrixx),
	       toMatrix_d(Matrixy), toMatrix_d(Matrixz));
  return R_NilValue;
} 

SEXP lPDirectDist_d
( SEXP MatrixA, SEXP Matrixb, SEXP Matrixc, SEXP Matrixx, SEXP Matrixy,
  SEXP Matrixz){
  ElLPDirectDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(Matrixb),
		   toDistMatrix_d(Matrixc), toDistMatrix_d(Matrixx),
		   toDistMatrix_d(Matrixy), toDistMatrix_d(Matrixz));
  return R_NilValue;
}

/* Expert versions pending */

/* Affine conic form
 */

SEXP lPAffine_d
( SEXP MatrixA, SEXP MatrixG, SEXP Matrixb, SEXP Matrixc, SEXP Matrixh,
  SEXP Matrixx, SEXP Matrixy, SEXP Matrixz, SEXP Matrixs){
  ElLPAffine_d(toMatrix_d(MatrixA), toMatrix_d(MatrixG),
	       toMatrix_d(Matrixb), toMatrix_d(Matrixc),
	       toMatrix_d(Matrixh), toMatrix_d(Matrixx),
	       toMatrix_d(Matrixy), toMatrix_d(Matrixz),
	       toMatrix_d(Matrixs) );
  return R_NilValue;
}

SEXP lPAffineDist_d
( SEXP MatrixA, SEXP MatrixG, SEXP Matrixb, SEXP Matrixc, SEXP Matrixh,
  SEXP Matrixx, SEXP Matrixy, SEXP Matrixz, SEXP Matrixs){
  ElLPAffineDist_d(toDistMatrix_d(MatrixA), toDistMatrix_d(MatrixG),
		   toDistMatrix_d(Matrixb), toDistMatrix_d(Matrixc),
		   toDistMatrix_d(Matrixh), toDistMatrix_d(Matrixx),
		   toDistMatrix_d(Matrixy), toDistMatrix_d(Matrixz),
		   toDistMatrix_d(Matrixs) );
  return R_NilValue;
}

/* Expert versions pending */

/* Direct conic form
 */


SEXP qPDirect_d
( SEXP MatrixQ, SEXP MatrixA, SEXP Matrixb, SEXP Matrixc, SEXP Matrixx,
  SEXP Matrixy, SEXP Matrixz){
  ElQPDirect_d(toMatrix_d(MatrixQ), toMatrix_d(MatrixA),
	       toMatrix_d(Matrixb), toMatrix_d(Matrixc),
	       toMatrix_d(Matrixx), toMatrix_d(Matrixy),
	       toMatrix_d(Matrixz));
  return R_NilValue;
}

SEXP qPDirectDist_d
( SEXP MatrixQ, SEXP MatrixA, SEXP Matrixb, SEXP Matrixc, SEXP Matrixx,
  SEXP Matrixy, SEXP Matrixz){
  ElQPDirectDist_d(toDistMatrix_d(MatrixQ), toDistMatrix_d(MatrixA),
		   toDistMatrix_d(Matrixb), toDistMatrix_d(Matrixc),
		   toDistMatrix_d(Matrixx), toDistMatrix_d(Matrixy),
		   toDistMatrix_d(Matrixz));
  return R_NilValue;
}

/* pending expert versions */

/* Affine conic form */


SEXP qPAffine_d
( SEXP MatrixQ, SEXP MatrixA, SEXP MatrixG, SEXP Matrixb,
  SEXP Matrixc, SEXP Matrixh, SEXP Matrixx, SEXP Matrixy,
  SEXP Matrixz, SEXP Matrixs){
  ElQPAffine_d(toMatrix_d(MatrixQ), toMatrix_d(MatrixA),
	       toMatrix_d(MatrixG), toMatrix_d(Matrixb),
	       toMatrix_d(Matrixc), toMatrix_d(Matrixh),
	       toMatrix_d(Matrixx), toMatrix_d(Matrixy),
	       toMatrix_d(Matrixz), toMatrix_d(Matrixs));
  return R_NilValue;
}

SEXP qPAffineDist_d
( SEXP MatrixQ, SEXP MatrixA, SEXP MatrixG, SEXP Matrixb,
  SEXP Matrixc, SEXP Matrixh, SEXP Matrixx, SEXP Matrixy,
  SEXP Matrixz, SEXP Matrixs){
  ElQPAffineDist_d(toDistMatrix_d(MatrixQ), toDistMatrix_d(MatrixA),
		   toDistMatrix_d(MatrixG), toDistMatrix_d(Matrixb),
		   toDistMatrix_d(Matrixc), toDistMatrix_d(Matrixh),
		   toDistMatrix_d(Matrixx), toDistMatrix_d(Matrixy),
		   toDistMatrix_d(Matrixz), toDistMatrix_d(Matrixs));
  return R_NilValue;
}

/* expert versions pending */
