#include "R-El.h"

ElLDLPivotType parsePivotType(SEXP ptype){
  char *text=(char*) CHAR( STRING_ELT(ptype,0) );
  //  printf("The distro is: %s\n",text);
  if (strcmp("EL_BUNCH_KAUFMAN_A",text)==0) return EL_BUNCH_KAUFMAN_A;
  if (strcmp("EL_BUNCH_KAUFMAN_C",text)==0) return EL_BUNCH_KAUFMAN_C;
  if (strcmp("EL_BUNCH_KAUFMAN_D",text)==0) return EL_BUNCH_KAUFMAN_D;
  if (strcmp("EL_BUNCH_KAUFMAN_BOUNDED",text)==0) 
    return EL_BUNCH_KAUFMAN_BOUNDED;
  if (strcmp("EL_BUNCH_PARLETT",text)==0) return EL_BUNCH_PARLETT;
  return EL_BUNCH_KAUFMAN_A;
}

/* Cholesky
 */

SEXP cholesky_d( SEXP uplo, SEXP RptrA){
  ElCholesky_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP cholesky_z( SEXP uplo, SEXP RptrA){
  ElCholesky_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP choleskyDist_d( SEXP uplo, SEXP RptrA){
  ElCholeskyDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP choleskyDist_z( SEXP uplo, SEXP RptrA){
  ElCholeskyDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP solveAfterCholesky_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB){
  ElSolveAfterCholesky_d( parseUpLo(uplo), parseOrientation(orientation),
                          toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholesky_z
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB){
  ElSolveAfterCholesky_z( parseUpLo(uplo), parseOrientation(orientation),
                          toMatrix_z(RptrA), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyDist_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB){
  ElSolveAfterCholeskyDist_d( parseUpLo(uplo), parseOrientation(orientation),
                          toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyDist_z
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP RptrB){
  ElSolveAfterCholeskyDist_z( parseUpLo(uplo), parseOrientation(orientation),
                          toDistMatrix_z(RptrA), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP reverseCholesky_d( SEXP uplo, SEXP RptrA){
  ElReverseCholesky_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}


SEXP reverseCholesky_z( SEXP uplo, SEXP RptrA){
  ElReverseCholesky_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP reverseCholeskyDist_d( SEXP uplo, SEXP RptrA){
  ElReverseCholeskyDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP reverseCholeskyDist_z( SEXP uplo, SEXP RptrA){
  ElReverseCholeskyDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP choleskyPiv_d( SEXP uplo, SEXP RptrA, SEXP Rptrp){
  ElCholeskyPiv_d( parseUpLo(uplo), toMatrix_d(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP choleskyPiv_z( SEXP uplo, SEXP RptrA, SEXP Rptrp){
  ElCholeskyPiv_z( parseUpLo(uplo), toMatrix_z(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP choleskyPivDist_d( SEXP uplo, SEXP RptrA, SEXP Rptrp){
  ElCholeskyPivDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA),
                       toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP choleskyPivDist_z( SEXP uplo, SEXP RptrA, SEXP Rptrp){
  ElCholeskyPivDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA),
                       toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP solveAfterCholeskyPiv_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterCholeskyPiv_d( parseUpLo(uplo), parseOrientation(orientation),
			     toMatrix_d(RptrA), toMatrix_i(Rptrp),
			     toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyPiv_z
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterCholeskyPiv_z( parseUpLo(uplo), parseOrientation(orientation),
			     toMatrix_z(RptrA), toMatrix_i(Rptrp),
			     toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyPivDist_d
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterCholeskyPivDist_d( parseUpLo(uplo), 
				 parseOrientation(orientation),
				 toDistMatrix_d(RptrA), 
				 toDistMatrix_i(Rptrp),
				 toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterCholeskyPivDist_z
( SEXP uplo, SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterCholeskyPivDist_z( parseUpLo(uplo), 
				 parseOrientation(orientation),
				 toDistMatrix_z(RptrA), 
				 toDistMatrix_i(Rptrp),
				 toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP choleskyMod_d( SEXP uplo, SEXP RptrT, SEXP alpha, SEXP RptrV){
  ElCholeskyMod_d( parseUpLo(uplo), toMatrix_d(RptrT), toDouble(alpha),
                   toMatrix_d(RptrV) );
  return R_NilValue;
}

SEXP choleskyMod_z( SEXP uplo, SEXP RptrT, SEXP alpha, SEXP RptrV){
  ElCholeskyMod_z( parseUpLo(uplo), toMatrix_z(RptrT), toDouble(alpha),
                   toMatrix_z(RptrV) );
  return R_NilValue;
}

SEXP choleskyModDist_d( SEXP uplo, SEXP RptrT, SEXP alpha, SEXP RptrV){
  ElCholeskyModDist_d( parseUpLo(uplo), toDistMatrix_d(RptrT), toDouble(alpha),
		       toDistMatrix_d(RptrV) );
  return R_NilValue;
}


SEXP choleskyModDist_z( SEXP uplo, SEXP RptrT, SEXP alpha, SEXP RptrV){
  ElCholeskyModDist_z( parseUpLo(uplo), toDistMatrix_z(RptrT), toDouble(alpha),
		       toDistMatrix_z(RptrV) );
  return R_NilValue;
}

SEXP hPSDcholesky_d( SEXP uplo, SEXP RptrA){
  ElHPSDCholesky_d( parseUpLo(uplo), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPSDcholesky_z( SEXP uplo, SEXP RptrA){
  ElHPSDCholesky_z( parseUpLo(uplo), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP hPSDcholeskyDist_d( SEXP uplo, SEXP RptrA){
  ElHPSDCholeskyDist_d( parseUpLo(uplo), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP hPSDcholeskyDist_z( SEXP uplo, SEXP RptrA){
  ElHPSDCholeskyDist_z( parseUpLo(uplo), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

/* LDL
 */

SEXP lDL_d( SEXP RptrA ){
  ElLDL_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lDL_z( SEXP RptrA, SEXP conjugate ){
  ElLDL_z( toMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP lDLDist_d( SEXP RptrA ){
  ElLDLDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lDLDist_z( SEXP RptrA, SEXP conjugate ){
  ElLDLDist_z( toDistMatrix_z(RptrA), toBool(conjugate) );
  return R_NilValue;
}

SEXP lDLPiv_d( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp){
  ElLDLPiv_d( toMatrix_d(RptrA), toMatrix_d(RptrdSub), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP lDLPiv_z( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP conjugate){
  ElLDLPiv_z( toMatrix_z(RptrA), toMatrix_z(RptrdSub), toMatrix_i(Rptrp),
	      toBool(conjugate) );
  return R_NilValue;
}

SEXP lDLPivDist_d( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp){
  ElLDLPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrdSub), 
                  toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP lDLPivDist_z( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP conjugate){
  ElLDLPivDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrdSub), 
                  toDistMatrix_i(Rptrp), toBool(conjugate) );
  return R_NilValue;
}

//inertia is a int vector with 3 components, numPositive, numNegative, numZero

SEXP inertiaAfterLDL_d( SEXP Rptrd, SEXP RptrdSub){
  ElInertiaType inertia;
  ElInertiaAfterLDL_d( toMatrix_d(Rptrd), toMatrix_d(RptrdSub), &inertia );
  SEXP ans = PROTECT( allocVector(INTSXP,3) );
  INTEGER(ans)[0]=(int)inertia.numPositive;
  INTEGER(ans)[1]=(int)inertia.numNegative;
  INTEGER(ans)[2]=(int)inertia.numZero;
  UNPROTECT(1);
  return ans;
}

SEXP inertiaAfterLDL_z( SEXP Rptrd, SEXP RptrdSub){
  ElInertiaType inertia;
  ElInertiaAfterLDL_z( toMatrix_d(Rptrd), toMatrix_z(RptrdSub), &inertia );
  SEXP ans = PROTECT( allocVector(INTSXP,3) );
  INTEGER(ans)[0]=(int)inertia.numPositive;
  INTEGER(ans)[1]=(int)inertia.numNegative;
  INTEGER(ans)[2]=(int)inertia.numZero;
  UNPROTECT(1);
  return ans;
}

SEXP inertiaAfterLDLDist_d( SEXP Rptrd, SEXP RptrdSub){
  ElInertiaType inertia;
  ElInertiaAfterLDLDist_d( toDistMatrix_d(Rptrd), toDistMatrix_d(RptrdSub),
                           &inertia );
  SEXP ans = PROTECT( allocVector(INTSXP,3) );
  INTEGER(ans)[0]=(int)inertia.numPositive;
  INTEGER(ans)[1]=(int)inertia.numNegative;
  INTEGER(ans)[2]=(int)inertia.numZero;
  UNPROTECT(1);
  return ans;
}

SEXP inertiaAfterLDLDist_z( SEXP Rptrd, SEXP RptrdSub){
  ElInertiaType inertia;
  ElInertiaAfterLDLDist_z( toDistMatrix_d(Rptrd), toDistMatrix_z(RptrdSub),
                           &inertia );
  SEXP ans = PROTECT( allocVector(INTSXP,3) );
  INTEGER(ans)[0]=(int)inertia.numPositive;
  INTEGER(ans)[1]=(int)inertia.numNegative;
  INTEGER(ans)[2]=(int)inertia.numZero;
  UNPROTECT(1);
  return ans;
}

SEXP solveAfterLDL_d( SEXP RptrA, SEXP RptrB){
  ElSolveAfterLDL_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLDL_z( SEXP RptrA, SEXP RptrB, SEXP conjugate){
  ElSolveAfterLDL_z( toMatrix_z(RptrA), toMatrix_z(RptrB), toBool(conjugate) );
  return R_NilValue;
}

SEXP solveAfterLDLDist_d( SEXP RptrA, SEXP RptrB){
  ElSolveAfterLDLDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLDLDist_z( SEXP RptrA, SEXP RptrB, SEXP conjugate){
  ElSolveAfterLDLDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
			 toBool(conjugate) );
  return R_NilValue;
}

SEXP solveAfterLDLPiv_d( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB ){
  ElSolveAfterLDLPiv_d( toMatrix_d(RptrA), toMatrix_d(RptrdSub),
                        toMatrix_i(Rptrp), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLDLPiv_z
( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB, SEXP conjugate ){
  ElSolveAfterLDLPiv_z( toMatrix_z(RptrA), toMatrix_z(RptrdSub),
                        toMatrix_i(Rptrp), toMatrix_z(RptrB),
			toBool(conjugate) );
  return R_NilValue;
}

SEXP solveAfterLDLPivDist_d
( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB ){
  ElSolveAfterLDLPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrdSub),
                        toDistMatrix_i(Rptrp), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLDLPivDist_z
( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB, SEXP conjugate ){
  ElSolveAfterLDLPivDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrdSub),
			    toDistMatrix_i(Rptrp), toDistMatrix_z(RptrB),
			    toBool(conjugate) );
  return R_NilValue;
}

SEXP multiplyAfterLDL_d( SEXP RptrA, SEXP RptrB){
  ElMultiplyAfterLDL_d( toMatrix_d(RptrA), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiplyAfterLDL_z( SEXP RptrA, SEXP RptrB, SEXP conjugate){
  ElMultiplyAfterLDL_z( toMatrix_z(RptrA), toMatrix_z(RptrB),
			toBool(conjugate) );
  return R_NilValue;
}

SEXP multiplyAfterLDLDist_d( SEXP RptrA, SEXP RptrB){
  ElMultiplyAfterLDLDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiplyAfterLDLDist_z( SEXP RptrA, SEXP RptrB, SEXP conjugate){
  ElMultiplyAfterLDLDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrB),
			    toBool(conjugate) );
  return R_NilValue;
}

SEXP multiplyAfterLDLPiv_d( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB ){
  ElMultiplyAfterLDLPiv_d( toMatrix_d(RptrA), toMatrix_d(RptrdSub),
			   toMatrix_i(Rptrp), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiplyAfterLDLPiv_z
( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB, SEXP conjugate ){
  ElMultiplyAfterLDLPiv_z( toMatrix_z(RptrA), toMatrix_z(RptrdSub),
			   toMatrix_i(Rptrp), toMatrix_z(RptrB),
			   toBool(conjugate));
  return R_NilValue;
}

SEXP multiplyAfterLDLPivDist_d
( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB ){
  ElMultiplyAfterLDLPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrdSub),
                        toDistMatrix_i(Rptrp), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP multiplyAfterLDLPivDist_z
( SEXP RptrA, SEXP RptrdSub, SEXP Rptrp, SEXP RptrB, SEXP conjugate ){
  ElMultiplyAfterLDLPivDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrdSub),
			       toDistMatrix_i(Rptrp), toDistMatrix_z(RptrB),
			       toBool(conjugate) );
  return R_NilValue;
}

/*LU
 */

SEXP lU_d(SEXP RptrA){
  ElLU_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lU_z(SEXP RptrA){
  ElLU_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP lUDist_d(SEXP RptrA){
  ElLUDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lUDist_z(SEXP RptrA){
  ElLUDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP solveAfterLU_d( SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSolveAfterLU_d( parseOrientation(orientation), toMatrix_d(RptrA),
                    toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLU_z( SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSolveAfterLU_z( parseOrientation(orientation), toMatrix_z(RptrA),
                    toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUDist_d( SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSolveAfterLUDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
                    toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUDist_z( SEXP orientation, SEXP RptrA, SEXP RptrB ){
  ElSolveAfterLUDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA),
			toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP lUPartialPiv_d( SEXP RptrA, SEXP Rptrp){
  ElLUPartialPiv_d( toMatrix_d(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP lUPartialPiv_z( SEXP RptrA, SEXP Rptrp){
  ElLUPartialPiv_z( toMatrix_z(RptrA), toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP lUPartialPivDist_d( SEXP RptrA, SEXP Rptrp){
  ElLUPartialPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP lUPartialPivDist_z( SEXP RptrA, SEXP Rptrp){
  ElLUPartialPivDist_z( toDistMatrix_z(RptrA), toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP solveAfterLUPartialPiv_d
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterLUPartialPiv_d( parseOrientation(orientation), toMatrix_d(RptrA),
                              toMatrix_i(Rptrp), toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUPartialPiv_z
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterLUPartialPiv_z( parseOrientation(orientation), toMatrix_z(RptrA),
                              toMatrix_i(Rptrp), toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUPartialPivDist_d
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterLUPartialPivDist_d( parseOrientation(orientation), 
                                  toDistMatrix_d(RptrA),
                                  toDistMatrix_i(Rptrp), 
                                  toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUPartialPivDist_z
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP RptrB){
  ElSolveAfterLUPartialPivDist_z( parseOrientation(orientation), 
                                  toDistMatrix_z(RptrA),
                                  toDistMatrix_i(Rptrp), 
                                  toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP lUFullPiv_d( SEXP RptrA, SEXP Rptrp, SEXP Rptrq){
  ElLUFullPiv_d( toMatrix_d(RptrA), toMatrix_i(Rptrp), toMatrix_i(Rptrq) );
  return R_NilValue;
}

SEXP lUFullPiv_z( SEXP RptrA, SEXP Rptrp, SEXP Rptrq){
  ElLUFullPiv_z( toMatrix_z(RptrA), toMatrix_i(Rptrp), toMatrix_i(Rptrq) );
  return R_NilValue;
}

SEXP lUFullPivDist_d( SEXP RptrA, SEXP Rptrp, SEXP Rptrq ){
  ElLUFullPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_i(Rptrp),
                     toDistMatrix_i(Rptrq) );
  return R_NilValue;
}

SEXP lUFullPivDist_z( SEXP RptrA, SEXP Rptrp, SEXP Rptrq ){
  ElLUFullPivDist_z( toDistMatrix_z(RptrA), toDistMatrix_i(Rptrp),
                     toDistMatrix_i(Rptrq) );
  return R_NilValue;
}

SEXP solveAfterLUFullPiv_d
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP Rptrq, SEXP RptrB){
  ElSolveAfterLUFullPiv_d( parseOrientation(orientation), toMatrix_d(RptrA),
                           toMatrix_i(Rptrp), toMatrix_i(Rptrq), 
                           toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUFullPiv_z
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP Rptrq, SEXP RptrB){
  ElSolveAfterLUFullPiv_z( parseOrientation(orientation), toMatrix_z(RptrA),
                           toMatrix_i(Rptrp), toMatrix_i(Rptrq), 
                           toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUFullPivDist_d
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP Rptrq, SEXP RptrB){
  ElSolveAfterLUFullPivDist_d( parseOrientation(orientation), 
                               toDistMatrix_d(RptrA),
                               toDistMatrix_i(Rptrp),
                               toDistMatrix_i(Rptrq),
                               toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP solveAfterLUFullPivDist_z
( SEXP orientation, SEXP RptrA, SEXP Rptrp, SEXP Rptrq, SEXP RptrB){
  ElSolveAfterLUFullPivDist_z( parseOrientation(orientation), 
                               toDistMatrix_z(RptrA),
                               toDistMatrix_i(Rptrp),
                               toDistMatrix_i(Rptrq),
                               toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP lUMod_d( SEXP RptrA, SEXP Rptrp, SEXP Rptru, SEXP Rptrv, SEXP tau ){
  ElLUMod_d( toMatrix_d(RptrA), toMatrix_i(Rptrp), toMatrix_d(Rptru),
             toMatrix_d(Rptrv), toDouble(tau) );
  return R_NilValue;
}

SEXP lUMod_z
( SEXP RptrA, SEXP Rptrp, SEXP Rptru, SEXP Rptrv, SEXP conjugate, SEXP tau ){
  ElLUMod_z( toMatrix_z(RptrA), toMatrix_i(Rptrp), toMatrix_z(Rptru),
             toMatrix_z(Rptrv), toBool(conjugate), toDouble(tau) );
  return R_NilValue;
}

SEXP lUModDist_d( SEXP RptrA, SEXP Rptrp, SEXP Rptru, SEXP Rptrv, SEXP tau ){
  ElLUModDist_d( toDistMatrix_d(RptrA), toDistMatrix_i(Rptrp),
                 toDistMatrix_d(Rptru), toDistMatrix_d(Rptrv), toDouble(tau) );
  return R_NilValue;
}

SEXP lUModDist_z
( SEXP RptrA, SEXP Rptrp, SEXP Rptru, SEXP Rptrv, SEXP conjugate, SEXP tau ){
  ElLUModDist_z( toDistMatrix_z(RptrA), toDistMatrix_i(Rptrp),
                 toDistMatrix_z(Rptru), toDistMatrix_z(Rptrv),
		 toBool(conjugate), toDouble(tau) );
  return R_NilValue;
}

/* LQ
 */

SEXP lQ_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElLQ_d( toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP lQ_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElLQ_z( toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP lQDist_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElLQDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
              toDistMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP lQDist_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElLQDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
              toDistMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP lQExplicit_d( SEXP RptrL, SEXP RptrA){
  ElLQExplicit_d( toMatrix_d(RptrL), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lQExplicit_z( SEXP RptrL, SEXP RptrA){
  ElLQExplicit_z( toMatrix_z(RptrL), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitDist_d( SEXP RptrL, SEXP RptrA ){
  ElLQExplicitDist_d( toDistMatrix_d(RptrL), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitDist_z( SEXP RptrL, SEXP RptrA ){
  ElLQExplicitDist_z( toDistMatrix_z(RptrL), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitTriang_d( SEXP RptrA){
  ElLQExplicitTriang_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitTriang_z( SEXP RptrA){
  ElLQExplicitTriang_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitTriangDist_d( SEXP RptrA ){
  ElLQExplicitTriangDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitTriangDist_z( SEXP RptrA ){
  ElLQExplicitTriangDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitUnitary_d( SEXP RptrA){
  ElLQExplicitUnitary_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitUnitary_z( SEXP RptrA){
  ElLQExplicitUnitary_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP lQExplicitUnitaryDist_d( SEXP RptrA ){
  ElLQExplicitUnitaryDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}


SEXP lQExplicitUnitaryDist_z( SEXP RptrA ){
  ElLQExplicitUnitaryDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP applyQAfterLQ_d
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterLQ_d( parseSide(side), parseOrientation(orientation),
                     toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd),
                     toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterLQ_z
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterLQ_z( parseSide(side), parseOrientation(orientation),
                     toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd),
                     toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterLQDist_d
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterLQDist_d( parseSide(side), parseOrientation(orientation),
                         toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
                         toDistMatrix_d(Rptrd), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterLQDist_z
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterLQDist_z( parseSide(side), parseOrientation(orientation),
                         toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
                         toDistMatrix_d(Rptrd), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveQAfterLQ_d
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterLQ_d( parseOrientation(orientation), toMatrix_d(RptrA),
                     toMatrix_d(Rptrt), toMatrix_d(Rptrd), toMatrix_d(RptrB),
                     toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterLQ_z
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterLQ_z( parseOrientation(orientation), toMatrix_z(RptrA),
                     toMatrix_z(Rptrt), toMatrix_d(Rptrd), toMatrix_z(RptrB),
                     toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterLQDist_d
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterLQDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
                         toDistMatrix_d(Rptrt), toDistMatrix_d(Rptrd),
                         toDistMatrix_d(RptrB), toDistMatrix_d(RptrX) );
  return R_NilValue;
}


SEXP solveQAfterLQDist_z
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterLQDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA),
                         toDistMatrix_z(Rptrt), toDistMatrix_d(Rptrd),
                         toDistMatrix_z(RptrB), toDistMatrix_z(RptrX) );
  return R_NilValue;
}

/* QR
 */

SEXP qR_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElQR_d( toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP qR_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElQR_z( toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP qRDist_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElQRDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
              toDistMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP qRDist_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElQRDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
              toDistMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP qRColPiv_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP Rptrp){
  ElQRColPiv_d( toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd),
                toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP qRColPiv_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP Rptrp){
  ElQRColPiv_z( toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd),
                toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP qRColPivDist_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP Rptrp){
  ElQRColPivDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
                    toDistMatrix_d(Rptrd), toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP qRColPivDist_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP Rptrp){
  ElQRColPivDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
                    toDistMatrix_d(Rptrd), toDistMatrix_i(Rptrp) );
  return R_NilValue;
}

/*Pending expert QR*/

SEXP qRExplicitTriang_d( SEXP RptrA){
  ElQRExplicitTriang_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitTriang_z( SEXP RptrA){
  ElQRExplicitTriang_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitTriangDist_d( SEXP RptrA ){
  ElQRExplicitTriangDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitTriangDist_z( SEXP RptrA ){
  ElQRExplicitTriangDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitUnitary_d( SEXP RptrA){
  ElQRExplicitUnitary_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitUnitary_z( SEXP RptrA){
  ElQRExplicitUnitary_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitUnitaryDist_d( SEXP RptrA ){
  ElQRExplicitUnitaryDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP qRExplicitUnitaryDist_z( SEXP RptrA ){
  ElQRExplicitUnitaryDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP qRExplicit_d( SEXP RptrA, SEXP RptrR){
  ElQRExplicit_d( toMatrix_d(RptrA), toMatrix_d(RptrR) );
  return R_NilValue;
}

SEXP qRExplicit_z( SEXP RptrA, SEXP RptrR){
  ElQRExplicit_z( toMatrix_z(RptrA), toMatrix_z(RptrR) );
  return R_NilValue;
}

/*Not yet linked:
SEXP qRExplicitDist_d( SEXP RptrA, SEXP RptrR ){
  ElQRExplicitDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrR) );
  return R_NilValue;
}
*/

SEXP qRColPivExplicit_d( SEXP RptrA, SEXP RptrR, SEXP Rptrp){
  ElQRColPivExplicit_d( toMatrix_d(RptrA), toMatrix_d(RptrR), 
                        toMatrix_i(Rptrp) );
  return R_NilValue;
}

SEXP qRColPivExplicit_z( SEXP RptrA, SEXP RptrR, SEXP Rptrp){
  ElQRColPivExplicit_z( toMatrix_z(RptrA), toMatrix_z(RptrR), 
                        toMatrix_i(Rptrp) );
  return R_NilValue;
}

/* Not yet linked:
SEXP qRColPivExplicitDist_d( SEXP RptrA, SEXP RptrR, SEXP Rptrp){
  ElQRColPivExplicitDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrR),
                            toDistMatrix_i(Rptrp) );
  return R_NilValue;
}
*/

SEXP choleskyQR_d( SEXP RptrA, SEXP RptrR){
  ElCholeskyQR_d( toMatrix_d(RptrA), toMatrix_d(RptrR) );
  return R_NilValue;
}

SEXP choleskyQR_z( SEXP RptrA, SEXP RptrR){
  ElCholeskyQR_z( toMatrix_z(RptrA), toMatrix_z(RptrR) );
  return R_NilValue;
}

SEXP choleskyQRDist_d( SEXP RptrA, SEXP RptrR ){
  ElCholeskyQRDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrR) );
  return R_NilValue;
}

SEXP choleskyQRDist_z( SEXP RptrA, SEXP RptrR ){
  ElCholeskyQRDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrR) );
  return R_NilValue;
}

SEXP applyQAfterQR_d
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterQR_d( parseSide(side), parseOrientation(orientation),
                     toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd),
                     toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterQR_z
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterQR_z( parseSide(side), parseOrientation(orientation),
                     toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd),
                     toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterQRDist_d
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterQRDist_d( parseSide(side), parseOrientation(orientation),
                         toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
                         toDistMatrix_d(Rptrd), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterQRDist_z
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterQRDist_z( parseSide(side), parseOrientation(orientation),
                         toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
                         toDistMatrix_d(Rptrd), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveQAfterQR_d
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterQR_d( parseOrientation(orientation), toMatrix_d(RptrA),
                     toMatrix_d(Rptrt), toMatrix_d(Rptrd), toMatrix_d(RptrB),
                     toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterQR_z
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterQR_z( parseOrientation(orientation), toMatrix_z(RptrA),
                     toMatrix_z(Rptrt), toMatrix_d(Rptrd), toMatrix_z(RptrB),
                     toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterQRDist_d
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterQRDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
                         toDistMatrix_d(Rptrt), toDistMatrix_d(Rptrd),
                         toDistMatrix_d(RptrB), toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterQRDist_z
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterQRDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA),
                         toDistMatrix_z(Rptrt), toDistMatrix_d(Rptrd),
                         toDistMatrix_z(RptrB), toDistMatrix_z(RptrX) );
  return R_NilValue;
}

/* RQ
 */

SEXP rQ_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElRQ_d( toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP rQ_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElRQ_z( toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP rQDist_d( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElRQDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
              toDistMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP rQDist_z( SEXP RptrA, SEXP Rptrt, SEXP Rptrd){
  ElRQDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
              toDistMatrix_d(Rptrd) );
  return R_NilValue;
}

SEXP rQExplicitTriang_d( SEXP RptrA){
  ElRQExplicitTriang_d( toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP rQExplicitTriang_z( SEXP RptrA){
  ElRQExplicitTriang_z( toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP rQExplicitTriangDist_d( SEXP RptrA ){
  ElRQExplicitTriangDist_d( toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP rQExplicitTriangDist_z( SEXP RptrA ){
  ElRQExplicitTriangDist_z( toDistMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP applyQAfterRQ_d
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterRQ_d( parseSide(side), parseOrientation(orientation),
                     toMatrix_d(RptrA), toMatrix_d(Rptrt), toMatrix_d(Rptrd),
                     toMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterRQ_z
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterRQ_z( parseSide(side), parseOrientation(orientation),
                     toMatrix_z(RptrA), toMatrix_z(Rptrt), toMatrix_d(Rptrd),
                     toMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterRQDist_d
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterRQDist_d( parseSide(side), parseOrientation(orientation),
                         toDistMatrix_d(RptrA), toDistMatrix_d(Rptrt),
                         toDistMatrix_d(Rptrd), toDistMatrix_d(RptrB) );
  return R_NilValue;
}

SEXP applyQAfterRQDist_z
( SEXP side, SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB){
  ElApplyQAfterRQDist_z( parseSide(side), parseOrientation(orientation),
                         toDistMatrix_z(RptrA), toDistMatrix_z(Rptrt),
                         toDistMatrix_d(Rptrd), toDistMatrix_z(RptrB) );
  return R_NilValue;
}

SEXP solveQAfterRQ_d
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterRQ_d( parseOrientation(orientation), toMatrix_d(RptrA),
                     toMatrix_d(Rptrt), toMatrix_d(Rptrd), toMatrix_d(RptrB),
                     toMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterRQ_z
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterRQ_z( parseOrientation(orientation), toMatrix_z(RptrA),
                     toMatrix_z(Rptrt), toMatrix_d(Rptrd), toMatrix_z(RptrB),
                     toMatrix_z(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterRQDist_d
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterRQDist_d( parseOrientation(orientation), toDistMatrix_d(RptrA),
                         toDistMatrix_d(Rptrt), toDistMatrix_d(Rptrd),
                         toDistMatrix_d(RptrB), toDistMatrix_d(RptrX) );
  return R_NilValue;
}

SEXP solveQAfterRQDist_z
( SEXP orientation, SEXP RptrA, SEXP Rptrt, SEXP Rptrd, SEXP RptrB, SEXP RptrX){
  ElSolveAfterRQDist_z( parseOrientation(orientation), toDistMatrix_z(RptrA),
                         toDistMatrix_z(Rptrt), toDistMatrix_d(Rptrd),
                         toDistMatrix_z(RptrB), toDistMatrix_z(RptrX) );
  return R_NilValue;
}


/* Generalized QR
 */

SEXP gQR_d
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGQR_d( toMatrix_d(RptrA), toMatrix_d(RptrtA), toMatrix_d(RptrdA),
           toMatrix_d(RptrB), toMatrix_d(RptrtB), toMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gQR_z
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGQR_z( toMatrix_z(RptrA), toMatrix_z(RptrtA), toMatrix_d(RptrdA),
           toMatrix_z(RptrB), toMatrix_z(RptrtB), toMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gQRDist_d
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGQRDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrtA), 
               toDistMatrix_d(RptrdA), toDistMatrix_d(RptrB), 
               toDistMatrix_d(RptrtB), toDistMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gQRDist_z
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGQRDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrtA), 
               toDistMatrix_d(RptrdA), toDistMatrix_z(RptrB), 
               toDistMatrix_z(RptrtB), toDistMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gQRExplicitTriang_d( SEXP RptrA, SEXP RptrB){
  ElGQRExplicitTriang_d( toMatrix_d(RptrA), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP gQRExplicitTriang_z( SEXP RptrA, SEXP RptrB){
  ElGQRExplicitTriang_z( toMatrix_z(RptrA), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP gQRExplicitTriangDist_d( SEXP RptrA, SEXP RptrB){
  ElGQRExplicitTriangDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP gQRExplicitTriangDist_z( SEXP RptrA, SEXP RptrB){
  ElGQRExplicitTriangDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

/* Generalized RQ
 */

SEXP gRQ_d
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGRQ_d( toMatrix_d(RptrA), toMatrix_d(RptrtA), toMatrix_d(RptrdA),
           toMatrix_d(RptrB), toMatrix_d(RptrtB), toMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gRQ_z
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGRQ_z( toMatrix_z(RptrA), toMatrix_z(RptrtA), toMatrix_d(RptrdA),
           toMatrix_z(RptrB), toMatrix_z(RptrtB), toMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gRQDist_d
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGRQDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrtA), 
               toDistMatrix_d(RptrdA), toDistMatrix_d(RptrB), 
               toDistMatrix_d(RptrtB), toDistMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gRQDist_z
( SEXP RptrA, SEXP RptrtA, SEXP RptrdA, SEXP RptrB, SEXP RptrtB, SEXP RptrdB ){
  ElGRQDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrtA), 
               toDistMatrix_d(RptrdA), toDistMatrix_z(RptrB), 
               toDistMatrix_z(RptrtB), toDistMatrix_d(RptrdB) );
  return R_NilValue;
}

SEXP gRQExplicitTriang_d( SEXP RptrA, SEXP RptrB){
  ElGRQExplicitTriang_d( toMatrix_d(RptrA), toMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP gRQExplicitTriang_z( SEXP RptrA, SEXP RptrB){
  ElGRQExplicitTriang_z( toMatrix_z(RptrA), toMatrix_z(RptrA) );
  return R_NilValue;
}

SEXP gRQExplicitTriangDist_d( SEXP RptrA, SEXP RptrB){
  ElGRQExplicitTriangDist_d( toDistMatrix_d(RptrA), toDistMatrix_d(RptrA) );
  return R_NilValue;
}

SEXP gRQExplicitTriangDist_z( SEXP RptrA, SEXP RptrB){
  ElGRQExplicitTriangDist_z( toDistMatrix_z(RptrA), toDistMatrix_z(RptrA) );
  return R_NilValue;
}

/* Interpolative Decomposition
 */
/* ! Pending */

/* Skeleton factorization
 */
/* ! Pending */

