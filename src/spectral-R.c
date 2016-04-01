#include "R-El.h"

ElHermitianEigSubset_d subsetParamsHermitian_d(SEXP from, SEXP to){
  ElHermitianEigSubset_d subset;
  ElHermitianEigSubsetDefault_d(&subset);
  if ( TYPEOF(from) == TYPEOF(to) && TYPEOF(from) == INTSXP ){ 
    subset.indexSubset = true;
    subset.lowerIndex = toElInt(from);
    subset.upperIndex = toElInt(to);
  }
  else{
    subset.rangeSubset = true;
    subset.lowerBound = toDouble(from);
    subset.upperBound = toDouble(to);
  }
  return subset;
}

/* Hermitian Tridiagonal
 */

SEXP hermitianTridiagEig_d(SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort){
  ElHermitianTridiagEig_d( toMatrix_d(Rptrd), toMatrix_d(RptrdSub),
                           toMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEig_z(SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort){
  ElHermitianTridiagEig_z( toMatrix_d(Rptrd), toMatrix_z(RptrdSub),
                           toMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigDist_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort){
  ElHermitianTridiagEigDist_d( toDistMatrix_d(Rptrd), toDistMatrix_d(RptrdSub),
                               toDistMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigDist_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort){
  ElHermitianTridiagEigDist_z( toDistMatrix_d(Rptrd), toDistMatrix_z(RptrdSub),
                               toDistMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigPair_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianTridiagEigPair_d( toMatrix_d(Rptrd), toMatrix_d(RptrdSub),
                               toMatrix_d(Rptrw), toMatrix_d(RptrZ), 
                               parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigPair_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianTridiagEigPair_z( toMatrix_d(Rptrd), toMatrix_z(RptrdSub),
                               toMatrix_d(Rptrw), toMatrix_z(RptrZ), 
                               parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigPairDist_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianTridiagEigPairDist_d( toDistMatrix_d(Rptrd), 
                                   toDistMatrix_d(RptrdSub),
                                   toDistMatrix_d(Rptrw), toDistMatrix_d(RptrZ),
                                   parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigPairDist_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianTridiagEigPairDist_z( toDistMatrix_d(Rptrd), 
                                   toDistMatrix_z(RptrdSub),
                                   toDistMatrix_d(Rptrw), toDistMatrix_z(RptrZ),
                                   parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianTridiagEigPartial_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPartial_d( toMatrix_d(Rptrd), toMatrix_d(RptrdSub),
                                  toMatrix_d(Rptrw), parseSort(sort),
                                  subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPartial_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPartial_z( toMatrix_d(Rptrd), toMatrix_z(RptrdSub),
                                  toMatrix_d(Rptrw), parseSort(sort),
                                  subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPartialDist_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPartialDist_d( toDistMatrix_d(Rptrd), 
                                  toDistMatrix_d(RptrdSub),
                                  toDistMatrix_d(Rptrw), parseSort(sort),
                                  subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPartialDist_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPartialDist_z( toDistMatrix_d(Rptrd), 
				      toDistMatrix_z(RptrdSub),
				      toDistMatrix_d(Rptrw), parseSort(sort),
				      subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPairPartial_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1,
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPairPartial_d( toMatrix_d(Rptrd), toMatrix_d(RptrdSub),
                                      toMatrix_d(Rptrw), toMatrix_d(RptrZ),
                                      parseSort(sort),
                                      subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPairPartial_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1,
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPairPartial_z( toMatrix_d(Rptrd), toMatrix_z(RptrdSub),
                                      toMatrix_d(Rptrw), toMatrix_z(RptrZ),
                                      parseSort(sort),
                                      subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPairPartialDist_d
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1,
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPairPartialDist_d( toDistMatrix_d(Rptrd), 
                                          toDistMatrix_d(RptrdSub),
                                          toDistMatrix_d(Rptrw),
                                          toDistMatrix_d(RptrZ),
                                          parseSort(sort),
                                          subset );
  return R_NilValue;
}

SEXP hermitianTridiagEigPairPartialDist_z
( SEXP Rptrd, SEXP RptrdSub, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1,
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianTridiagEigPairPartialDist_z( toDistMatrix_d(Rptrd), 
                                          toDistMatrix_z(RptrdSub),
                                          toDistMatrix_d(Rptrw),
                                          toDistMatrix_z(RptrZ),
                                          parseSort(sort),
                                          subset );
  return R_NilValue;
}

/* Hermitian
 */

SEXP hermitianEig_d(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort){
  ElHermitianEig_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_d(Rptrw), 
                    parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEig_z(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort){
  ElHermitianEig_z( parseUpLo(uplo), toMatrix_z(RptrA), toMatrix_d(Rptrw), 
                    parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigDist_d(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort){
  ElHermitianEigDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                        toDistMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigDist_z(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort){
  ElHermitianEigDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), 
                        toDistMatrix_d(Rptrw), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPair_d
(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianEigPair_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_d(Rptrw), 
                        toMatrix_d(RptrZ), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPair_z
(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianEigPair_z( parseUpLo(uplo), toMatrix_z(RptrA), toMatrix_d(Rptrw), 
                        toMatrix_z(RptrZ), parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPairDist_d
(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianEigPairDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                            toDistMatrix_d(Rptrw), toDistMatrix_d(RptrZ),
                            parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPairDist_z
(SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort){
  ElHermitianEigPairDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA),
                            toDistMatrix_d(Rptrw), toDistMatrix_z(RptrZ),
                            parseSort(sort) );
  return R_NilValue;
}

SEXP hermitianEigPartial_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPartial_d( parseUpLo(uplo), toMatrix_d(RptrA), 
                           toMatrix_d(Rptrw), parseSort(sort), subset );
  return R_NilValue;
}

SEXP hermitianEigPartial_z
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPartial_z( parseUpLo(uplo), toMatrix_z(RptrA), 
                           toMatrix_d(Rptrw), parseSort(sort), subset );
  return R_NilValue;
}

SEXP hermitianEigPartialDist_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPartialDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                               toDistMatrix_d(Rptrw), parseSort(sort), subset );
  return R_NilValue;
}

SEXP hermitianEigPartialDist_z
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP sort, SEXP idx1, SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPartialDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), 
                               toDistMatrix_d(Rptrw), parseSort(sort), subset );
  return R_NilValue;
}



SEXP hermitianEigPairPartial_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1, 
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPairPartial_d( parseUpLo(uplo), toMatrix_d(RptrA), 
			       toMatrix_d(Rptrw), toMatrix_d(RptrZ),
			       parseSort(sort), subset );
  return R_NilValue;
}


SEXP hermitianEigPairPartial_z
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1, 
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPairPartial_z( parseUpLo(uplo), toMatrix_z(RptrA), 
			       toMatrix_d(Rptrw), toMatrix_z(RptrZ),
			       parseSort(sort), subset );
  return R_NilValue;
}

SEXP hermitianEigPairPartialDist_d
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1, 
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPairPartialDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA), 
                                   toDistMatrix_d(Rptrw), toDistMatrix_d(RptrZ),
                                   parseSort(sort), subset );
  return R_NilValue;
}

SEXP hermitianEigPairPartialDist_z
( SEXP uplo, SEXP RptrA, SEXP Rptrw, SEXP RptrZ, SEXP sort, SEXP idx1, 
  SEXP idx2){
  ElHermitianEigSubset_d subset =  subsetParamsHermitian_d(idx1, idx2);
  ElHermitianEigPairPartialDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA), 
                                   toDistMatrix_d(Rptrw), toDistMatrix_z(RptrZ),
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

SEXP polar_z( SEXP RptrA ){
  ElPolar_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP polarDist_d( SEXP RptrA ){
  ElPolarDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP polarDist_z( SEXP RptrA ){
  ElPolarDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianPolar_d( SEXP uplo, SEXP RptrA ){
  ElHermitianPolar_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianPolar_z( SEXP uplo, SEXP RptrA ){
  ElHermitianPolar_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hermitianPolarDist_d( SEXP uplo, SEXP RptrA ){
  ElHermitianPolarDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hermitianPolarDist_z( SEXP uplo, SEXP RptrA ){
  ElHermitianPolarDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP polarDecomp_d( SEXP RptrA, SEXP RptrP){
  ElPolarDecomp_d( toMatrix_d(RptrA), toMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP polarDecomp_z( SEXP RptrA, SEXP RptrP){
  ElPolarDecomp_z( toMatrix_z(RptrA), toMatrix_z(RptrP) );
  return R_NilValue;
}

SEXP polarDecompDist_d( SEXP RptrA, SEXP RptrP){
  ElPolarDecompDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP polarDecompDist_z( SEXP RptrA, SEXP RptrP){
  ElPolarDecompDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrP) );
  return R_NilValue;
}

SEXP hermitianPolarDecomp_d( SEXP uplo, SEXP RptrA , SEXP RptrP){
  ElHermitianPolarDecomp_d( parseUpLo(uplo), toMatrix_d(RptrA),
                            toMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP hermitianPolarDecomp_z( SEXP uplo, SEXP RptrA , SEXP RptrP){
  ElHermitianPolarDecomp_z( parseUpLo(uplo), toMatrix_z(RptrA),
                            toMatrix_z(RptrP) );
  return R_NilValue;
}

SEXP hermitianPolarDecompDist_d( SEXP uplo, SEXP RptrA, SEXP RptrP ){
  ElHermitianPolarDecompDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                                toDistMatrix_d(RptrP) );
  return R_NilValue;
}

SEXP hermitianPolarDecompDist_z( SEXP uplo, SEXP RptrA, SEXP RptrP ){
  ElHermitianPolarDecompDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA),
                                toDistMatrix_z(RptrP) );
  return R_NilValue;
}

/* Schur decomposition
 */

SEXP schur_d( SEXP RptrA, SEXP Rptrw, SEXP fullTriangle){
  ElSchur_d( toMatrix_d(RptrA), toMatrix_z(RptrA), toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schur_z( SEXP RptrA, SEXP Rptrw, SEXP fullTriangle){
  ElSchur_z( toMatrix_z(RptrA), toMatrix_z(RptrA), toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDist_d( SEXP RptrA, SEXP Rptrw, SEXP fullTriangle){
  ElSchurDist_d( toDistMatrix_d(RptrA), toDistMatrix_z(RptrA),
                 toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDist_z( SEXP RptrA, SEXP Rptrw, SEXP fullTriangle){
  ElSchurDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrA),
                 toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDecomp_d( SEXP RptrA, SEXP Rptrw, SEXP RptrQ, SEXP fullTriangle){
  ElSchurDecomp_d( toMatrix_d(RptrA), toMatrix_z(RptrA), toMatrix_d(RptrQ),
		   toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDecomp_z( SEXP RptrA, SEXP Rptrw, SEXP RptrQ, SEXP fullTriangle){
  ElSchurDecomp_z( toMatrix_z(RptrA), toMatrix_z(RptrA), toMatrix_z(RptrQ),
		   toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDecompDist_d
( SEXP RptrA, SEXP Rptrw, SEXP RptrQ, SEXP fullTriangle){
  ElSchurDecompDist_d( toDistMatrix_d(RptrA), toDistMatrix_z(RptrA),
		       toDistMatrix_d(RptrQ), toBool(fullTriangle) );
  return R_NilValue;
}

SEXP schurDecompDist_z
( SEXP RptrA, SEXP Rptrw, SEXP RptrQ, SEXP fullTriangle){
  ElSchurDecompDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrA),
		       toDistMatrix_z(RptrQ), toBool(fullTriangle) );
  return R_NilValue;
}

/* SVD
 */

SEXP singuarValues_d( SEXP RptrA, SEXP Rptrs){
  ElSingularValues_d( toMatrix_d(RptrA), toMatrix_d(Rptrs) );
  return R_NilValue;
}

SEXP singuarValues_z( SEXP RptrA, SEXP Rptrs){
  ElSingularValues_z( toMatrix_z(RptrA), toMatrix_d(Rptrs) );
  return R_NilValue;
}

SEXP singuarValuesDist_d( SEXP RptrA, SEXP Rptrs){
  ElSingularValuesDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrs) );
  return R_NilValue;
}

SEXP singuarValuesDist_z( SEXP RptrA, SEXP Rptrs){
  ElSingularValuesDist_z( toDistMatrix_z(RptrA), toDistMatrix_d(Rptrs) );
  return R_NilValue;
}

SEXP sVD_d( SEXP RptrA, SEXP RptrU, SEXP Rptrs, SEXP RptrV){
  ElSVD_d( toMatrix_d(RptrA), toMatrix_d(RptrU), toMatrix_d(Rptrs),
	   toMatrix_d(RptrV) );
  return R_NilValue;
}

SEXP sVD_z( SEXP RptrA, SEXP RptrU, SEXP Rptrs, SEXP RptrV){
  ElSVD_z( toMatrix_z(RptrA), toMatrix_z(RptrU), toMatrix_d(Rptrs),
	   toMatrix_z(RptrV) );
  return R_NilValue;
}

SEXP sVDDist_d( SEXP RptrA, SEXP RptrU, SEXP Rptrs, SEXP RptrV){
  ElSVDDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrU), 
               toDistMatrix_d(Rptrs), toDistMatrix_d(RptrV) );
  return R_NilValue;
}

SEXP sVDDist_z( SEXP RptrA, SEXP RptrU, SEXP Rptrs, SEXP RptrV){
  ElSVDDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrU), 
               toDistMatrix_d(Rptrs), toDistMatrix_z(RptrV) );
  return R_NilValue;
}
