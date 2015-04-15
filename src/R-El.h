#include "El.h"
#include "R.h"
#include "Rdefines.h"

inline ElMatrix_i toMatrix_i(SEXP Rptr){
  return *(ElMatrix_i *)R_ExternalPtrAddr(Rptr);
}
inline ElMatrix_i* toMatrix_i_p(SEXP Rptr){
  return (ElMatrix_i *)R_ExternalPtrAddr(Rptr);
}

inline ElMatrix_s toMatrix_s(SEXP Rptr){
  return *(ElMatrix_s *)R_ExternalPtrAddr(Rptr);
}
inline ElMatrix_s* toMatrix_s_p(SEXP Rptr){
  return (ElMatrix_s *)R_ExternalPtrAddr(Rptr);
}

inline ElMatrix_d toMatrix_d(SEXP Rptr){
  return *(ElMatrix_d *)R_ExternalPtrAddr(Rptr);
}
inline ElMatrix_d* toMatrix_d_p(SEXP Rptr){
  return (ElMatrix_d *)R_ExternalPtrAddr(Rptr);
}

inline ElMatrix_c toMatrix_c(SEXP Rptr){
  return *(ElMatrix_c *)R_ExternalPtrAddr(Rptr);
}
inline ElMatrix_c* toMatrix_c_p(SEXP Rptr){
  return (ElMatrix_c *)R_ExternalPtrAddr(Rptr);
}

inline ElMatrix_z toMatrix_z(SEXP Rptr){
  return *(ElMatrix_z *)R_ExternalPtrAddr(Rptr);
}
inline ElMatrix_z* toMatrix_z_p(SEXP Rptr){
  return (ElMatrix_z *)R_ExternalPtrAddr(Rptr);
}

/*
inline ElConstMatrix_d toConstMatrix_d(SEXP Rptr){
  return *(ElConstMatrix_d*)R_ExternalPtrAddr(Rptr);
}
*/

inline ElDistMatrix_i toDistMatrix_i(SEXP Rptr){
  return *(ElDistMatrix_i *)R_ExternalPtrAddr(Rptr);
}
inline ElDistMatrix_i* toDistMatrix_i_p(SEXP Rptr){
  return (ElDistMatrix_i *)R_ExternalPtrAddr(Rptr);
}

inline ElDistMatrix_s toDistMatrix_s(SEXP Rptr){
  return *(ElDistMatrix_s *)R_ExternalPtrAddr(Rptr);
}
inline ElDistMatrix_s* toDistMatrix_s_p(SEXP Rptr){
  return (ElDistMatrix_s *)R_ExternalPtrAddr(Rptr);
}

inline ElDistMatrix_d toDistMatrix_d(SEXP Rptr){
  return *(ElDistMatrix_d *)R_ExternalPtrAddr(Rptr);
}
inline ElDistMatrix_d* toDistMatrix_d_p(SEXP Rptr){
  return (ElDistMatrix_d *)R_ExternalPtrAddr(Rptr);
}

inline ElDistMatrix_c toDistMatrix_c(SEXP Rptr){
  return *(ElDistMatrix_c *)R_ExternalPtrAddr(Rptr);
}
inline ElDistMatrix_c* toDistMatrix_c_p(SEXP Rptr){
  return (ElDistMatrix_c *)R_ExternalPtrAddr(Rptr);
}

inline ElDistMatrix_z toDistMatrix_z(SEXP Rptr){
  return *(ElDistMatrix_z *)R_ExternalPtrAddr(Rptr);
}
inline ElDistMatrix_z* toDistMatrix_z_p(SEXP Rptr){
  return (ElDistMatrix_z *)R_ExternalPtrAddr(Rptr);
}

/*
inline ElConstDistMatrix_d toConstDistMatrix_d(SEXP Rptr){
  return *(ElConstDistMatrix_d *)R_ExternalPtrAddr(Rptr);
}
*/

inline ElGrid toGrid(SEXP Rgrid){
  return *(ElGrid *)R_ExternalPtrAddr(Rgrid);
}

inline ElGrid* toGrid_p(SEXP Rgrid){
  return (ElGrid *)R_ExternalPtrAddr(Rgrid);
}

/*
inline ElConstGrid toConstGrid(SEXP Rgrid){
  return *(ElConstGrid *)R_ExternalPtrAddr(Rgrid);
}
*/

inline ElInt toElInt(SEXP Rint){
  return (ElInt)INTEGER(Rint)[0];
}

inline ElInt* toElInt_p(SEXP Rint){
  return (ElInt *)INTEGER(Rint);
}

inline double toDouble(SEXP Rdouble){
  return REAL(Rdouble)[0];
}

inline double* toDouble_p(SEXP Rdouble){
  return REAL(Rdouble);
}

inline const char* toChar_p(SEXP Rtext){
  return (const char*) CHAR(STRING_ELT(Rtext,0));
}

inline bool toBool(SEXP Rlog){
  return (bool)LOGICAL(Rlog)[0];
}

inline complex_double toDComplex(SEXP Rcplex){
  return (complex_double)(COMPLEX(Rcplex)[0].r + \
			  COMPLEX(Rcplex)[0].i * _Complex_I);
}


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
ElRange_i parseRange_i(SEXP beg, SEXP end);
ElRegularization parseRegularization(SEXP pen);
ElNormType parseNorm(SEXP norm);

bool isDestroyed(SEXP Rptr);

MPI_Datatype parseMPIDatatype(SEXP type);
MPI_Op parseMPIOp(SEXP Op);

inline MPI_Comm toComm(SEXP Rcomm){
  return *(MPI_Comm *)R_ExternalPtrAddr(Rcomm);
}

inline MPI_Comm *toComm_p(SEXP Rcomm){
  return (MPI_Comm *)R_ExternalPtrAddr(Rcomm);
}

/*
  Matrix Constructors
*/

SEXP newMatrix_d();
SEXP newMatrix_z();
SEXP newMatrix_i();

SEXP newDistMatrix_d(SEXP RptrGrid);
SEXP newDistMatrix_z(SEXP RptrGrid);
SEXP newDistMatrix_i(SEXP RptrGrid);

SEXP newDistMatrixSpecific_d(SEXP U, SEXP V, SEXP RptrGrid);
SEXP newDistMatrixSpecific_z(SEXP U, SEXP V, SEXP RptrGrid);
SEXP newDistMatrixSpecific_i(SEXP U, SEXP V, SEXP RptrGrid);
