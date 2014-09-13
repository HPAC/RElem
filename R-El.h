#include "El-C.h"
#include "R.h"
#include "Rdefines.h"

inline ElMatrix_d toMatrix_d(SEXP Rptr);
inline ElMatrix_d* toMatrix_d_p(SEXP Rptr);
/*
inline ElConstMatrix_d toConstMatrix_d(SEXP Rptr);
*/


inline ElDistMatrix_d toDistMatrix_d(SEXP Rptr);
inline ElDistMatrix_d* toDistMatrix_d_p(SEXP Rptr);
/*
inline ElConstDistMatrix_d toConstDistMatrix_d(SEXP Rptr);
*/
inline ElGrid toGrid(SEXP Rgrid);
//inline ElConstGrid toConstGrid(SEXP Rgrid);

inline ElInt toElInt(SEXP Rint);
inline ElInt* toElInt_p(SEXP Rint);
inline double toDouble(SEXP Rdouble);
inline double* toDouble_p(SEXP Rdouble);
inline const char* toChar_p(SEXP Rtext);
inline bool toBool(SEXP Rlog);

ElDist parseDistText(SEXP dist);
ElFileFormat parseFormatText(SEXP format);
const char * parseDistEnum(ElDist dist);
ElUpperOrLower parseUpLo(SEXP uplo);
ElOrientation parseOrientation(SEXP orientation);
ElLeftOrRight parseSide(SEXP side);
ElUnitOrNonUnit parseUnit(SEXP unit);
