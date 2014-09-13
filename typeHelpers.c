#include "R-El.h"

inline ElMatrix_d toMatrix_d(SEXP Rptr){
  return *(ElMatrix_d *)R_ExternalPtrAddr(Rptr);
}
inline ElMatrix_d* toMatrix_d_p(SEXP Rptr){
  return (ElMatrix_d *)R_ExternalPtrAddr(Rptr);
}

/*
inline ElConstMatrix_d toConstMatrix_d(SEXP Rptr){
  return *(ElConstMatrix_d*)R_ExternalPtrAddr(Rptr);
}
*/


inline ElDistMatrix_d toDistMatrix_d(SEXP Rptr){
  return *(ElDistMatrix_d *)R_ExternalPtrAddr(Rptr);
}

inline ElDistMatrix_d* toDistMatrix_d_p(SEXP Rptr){
  return (ElDistMatrix_d *)R_ExternalPtrAddr(Rptr);
}

/*
inline ElConstDistMatrix_d toConstDistMatrix_d(SEXP Rptr){
  return *(ElConstDistMatrix_d *)R_ExternalPtrAddr(Rptr);
}
*/

inline ElGrid toGrid(SEXP Rgrid){
  return *(ElGrid *)R_ExternalPtrAddr(Rgrid);
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
  return (bool)LOGICAL(Rlog);
}



ElDist parseDistText(SEXP dist){
  char *text=(char*) CHAR( STRING_ELT(dist,0) );
  //  printf("The distro is: %s\n",text);
  if (strcmp("MC",text)==0) return EL_MC;
  if (strcmp("MD",text)==0) return EL_MD;
  if (strcmp("MR",text)==0) return EL_MR;
  if (strcmp("VC",text)==0) return EL_VC;
  if (strcmp("VR",text)==0) return EL_VR;
  if (strcmp("STAR",text)==0) return EL_STAR;
  if (strcmp("CIRC",text)==0) return EL_CIRC;
  printf("wrong value: \"%s\", using MC as default\n",text);
  return EL_MC;
}

ElFileFormat parseFormatText(SEXP format){
  char *text=(char*) CHAR( STRING_ELT(format,0) );
  //  printf("The distro is: %s\n",text);
  if (strcmp("AUTO",text)==0) return EL_AUTO;
  if (strcmp("ASCII_MATLAB",text)==0) return EL_ASCII_MATLAB;
  if (strcmp("BINARY",text)==0) return EL_BINARY;
  if (strcmp("BINARY_FLAT",text)==0) return EL_BINARY_FLAT;
  if (strcmp("EL_BMP",text)==0) return EL_BMP;
  if (strcmp("JPG",text)==0) return EL_JPG;
  if (strcmp("JPEG",text)==0) return EL_JPEG;
  if (strcmp("MATRIX_MARKET",text)==0) return EL_MATRIX_MARKET;
  if (strcmp("PNG",text)==0) return EL_PNG;
  if (strcmp("PPM",text)==0) return EL_PPM;
  if (strcmp("XBM",text)==0) return EL_XBM;
  if (strcmp("XPM",text)==0) return EL_XPM;
  printf("wrong value: \"%s\", using AUTO as default\n",text);
  return EL_AUTO;
}

const char * parseDistEnum(ElDist dist){
  switch(dist){
  case EL_MC: return "MC";
  case EL_MD: return "MD";
  case EL_MR: return "MR";
  case EL_VC: return "VC";
  case EL_VR: return "VR";
  case EL_STAR: return "STAR";
  case EL_CIRC: return "CIRC";
  default: return "N/A";
  }
}

ElUpperOrLower parseUpLo(SEXP uplo){
  char *text = (char*)toChar_p(uplo);
  if (strcmp("LOWER", text) == 0) return EL_LOWER;
  if (strcmp("UPPER", text) == 0) return EL_UPPER;
  printf("wrong value: using LOWER as default");
  return EL_LOWER;
}

ElOrientation parseOrientation(SEXP orientation){
  char *text = (char*)toChar_p(orientation);
  if (strcmp("NORMAL", text) == 0) return EL_NORMAL;
  if (strcmp("TRANSPOSE", text) == 0) return EL_TRANSPOSE;
  if (strcmp("ADJOINT", text) == 0) return EL_ADJOINT;
  return EL_NORMAL;
}

ElLeftOrRight parseSide(SEXP side){
  char *text = (char*)toChar_p(side);
  if (strcmp("LEFT", text) == 0) return EL_LEFT;
  if (strcmp("RIGHT", text) == 0) return EL_RIGHT;
  return EL_LEFT;
}

ElUnitOrNonUnit parseUnit(SEXP unit){
  char *text = (char*)toChar_p(unit);
  if (strcmp("NON_UNIT", text) == 0) return EL_NON_UNIT;
  if (strcmp("UNIT", text) == 0) return EL_UNIT;
  return EL_NON_UNIT;
}
