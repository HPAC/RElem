#include "R-El.h"

ElHermitianEigSubset_d subsetParamsIdx_d(ElInt idxa, ElInt idxb){
  ElHermitianEigSubset_d subset;
  ElHermitianEigSubsetDefault_d(&subset);
  subset.indexSubset = true;
  subset.lowerIndex = idxa;
  subset.upperIndex = idxb;
  return subset;
}

/* Hermitian
 */

SEXP hermitianEig_d(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort){
  ElHermitianEig_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_d(Rptrw), 
                    parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigDist_d(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort){
  ElHermitianEigDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                        toDistMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPair_d
(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianEigPair_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_d(Rptrw), 
                        toMatrix_d(RptrZ), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigDistPair_d
(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianEigPairDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                            toDistMatrix_d(Rptrw), toDistMatrix_d(RptrZ),
                            parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPartial_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset;
  subsetParamsIdx_d( (ElInt)INTEGER(idx1)[0], (ElInt)INTEGER(idx2)[0] );
  ElHermitianEigPartial_d( parseUpLo(uplo), toMatrix_d(RptrA), 
                           toMatrix_d(Rptrw), parseSort(sort), subset );
  return R_NilValue;
}


SEXP hermitianEigPartialDist_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset;
  subsetParamsIdx_d( (ElInt)INTEGER(idx1)[0], (ElInt)INTEGER(idx2)[0] );
  ElHermitianEigPartialDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                               toDistMatrix_d(Rptrw), parseSort(sort), subset );
  return R_NilValue;
}



SEXP hermitianEigPairPartial_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1, 
  SEXP idx2){
  ElHermitianEigSubset_d subset;
  subsetParamsIdx_d( (ElInt)INTEGER(idx1)[0], (ElInt)INTEGER(idx2)[0] );
  ElHermitianEigPairPartial_d( parseUpLo(uplo), toMatrix_d(RptrA), 
                                   toMatrix_d(Rptrw), toMatrix_d(RptrZ),
                                   parseSort(sort), subset );
  return R_NilValue;
}


SEXP hermitianEigPairPartialDist_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1, 
  SEXP idx2){
  ElHermitianEigSubset_d subset;
  subsetParamsIdx_d( (ElInt)INTEGER(idx1)[0], (ElInt)INTEGER(idx2)[0] );
  ElHermitianEigPairPartialDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                                   toDistMatrix_d(Rptrw), toDistMatrix_d(RptrZ),
                                   parseSort(sort), subset );
  return R_NilValue;
}
/*Not complete...
 */

/* Polar
 */

SEXP polar_d( SEXP RptrA ){
  ElPolar_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP polarDist_d( SEXP RptrA ){
  ElPolarDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianPolar_d( SEXP uplo, SEXP RptrA ){
  ElHermitianPolar_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianPolarDist_d( SEXP uplo, SEXP RptrA ){
  ElHermitianPolarDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP polarDecomp_d( SEXP RptrA, SEXP RptrP){
  ElPolarDecomp_d( toMatrix_d(RptrA), toMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP polarDecompDist_d( SEXP RptrA, SEXP RptrP){
  ElPolarDecompDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP hermitianPolarDecomp_d( SEXP uplo, SEXP RptrA , SEXP RptrP){
  ElHermitianPolarDecomp_d( parseUpLo(uplo), toMatrix_d(RptrA),
                            toMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP hermitianPolarDecompDist_d( SEXP uplo, SEXP RptrA, SEXP RptrP ){
  ElHermitianPolarDecompDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                                toDistMatrix_d(RptrP) );
  return R_NilValue;
}

/* Schur decomposition
 */

SEXP schur_d( SEXP RptrA, SEXP Rptrw, SEXP fullTriangle){
  ElSchur_d( toMatrix_d(RptrA), toMatrix_z(RptrA), toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDist_d( SEXP RptrA, SEXP Rptrw, SEXP fullTriangle){
  ElSchurDist_d( toDistMatrix_d(RptrA), toDistMatrix_z(RptrA),
                 toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDecomp_d( SEXP RptrA, SEXP Rptrw, SEXP RptrQ, SEXP fullTriangle){
  ElSchurDecomp_d( toMatrix_d(RptrA), toMatrix_z(RptrA), toMatrix_d(RptrQ),
             toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDecompDist_d
( SEXP RptrA, SEXP Rptrw, SEXP RptrQ, SEXP fullTriangle){
  ElSchurDecompDist_d( toDistMatrix_d(RptrA), toDistMatrix_z(RptrA),
                 toDistMatrix_d(RptrQ), toBool(fullTriangle) );
  return R_NilValue;
}

/* SVD
 */

SEXP singuarValues_d( SEXP RptrA, SEXP Rptrs){
  ElSingularValues_d( toMatrix_d(RptrA), toMatrix_d(Rptrs) );
  return R_NilValue;
}

SEXP singuarValuesDist_d( SEXP RptrA, SEXP Rptrs){
  ElSingularValuesDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrs) );
  return R_NilValue;
}

SEXP sVD_d( SEXP RptrA, SEXP Rptrs, SEXP RptrV){
  ElSVD_d( toMatrix_d(RptrA), toMatrix_d(Rptrs), toMatrix_d(RptrV) );
  return R_NilValue;
}

SEXP sVDDist_d( SEXP RptrA, SEXP Rptrs, SEXP RptrV){
  ElSVDDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrs), 
               toDistMatrix_d(RptrV) );
  return R_NilValue;
}
