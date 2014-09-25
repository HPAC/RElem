#include "El-C.h"
#include "R.h"
#include "Rdefines.h"

inline ElMatrix_i toMatrix_i(SEXP Rptr);
inline ElMatrix_i* toMatrix_i_p(SEXP Rptr);
inline ElMatrix_s toMatrix_s(SEXP Rptr);
inline ElMatrix_s* toMatrix_s_p(SEXP Rptr);
inline ElMatrix_d toMatrix_d(SEXP Rptr);
inline ElMatrix_d* toMatrix_d_p(SEXP Rptr);
inline ElMatrix_c toMatrix_c(SEXP Rptr);
inline ElMatrix_c* toMatrix_c_p(SEXP Rptr);
inline ElMatrix_z toMatrix_z(SEXP Rptr);
inline ElMatrix_z* toMatrix_z_p(SEXP Rptr);

/*
inline ElConstMatrix_d toConstMatrix_d(SEXP Rptr);
*/

inline ElDistMatrix_i toDistMatrix_i(SEXP Rptr);
inline ElDistMatrix_i* toDistMatrix_i_p(SEXP Rptr);
inline ElDistMatrix_s toDistMatrix_s(SEXP Rptr);
inline ElDistMatrix_s* toDistMatrix_s_p(SEXP Rptr);
inline ElDistMatrix_d toDistMatrix_d(SEXP Rptr);
inline ElDistMatrix_d* toDistMatrix_d_p(SEXP Rptr);
inline ElDistMatrix_c toDistMatrix_c(SEXP Rptr);
inline ElDistMatrix_c* toDistMatrix_c_p(SEXP Rptr);
inline ElDistMatrix_z toDistMatrix_z(SEXP Rptr);
inline ElDistMatrix_z* toDistMatrix_z_p(SEXP Rptr);



/*
inline ElConstDistMatrix_d toConstDistMatrix_d(SEXP Rptr);
*/
inline ElGrid toGrid(SEXP Rgrid);
inline ElGrid* toGrid_p(SEXP Rgrid);
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
ElSortType parseSort(SEXP sort);
ElRidgeAlg parseRidgeAlg(SEXP alg);
ElTikhonovAlg parseTikhonovAlg(SEXP alg);
