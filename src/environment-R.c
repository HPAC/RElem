#include "R-El.h"

//Section: Environment
SEXP initialize(){
  //Thinking about passing the R arguments
  int argc = 0;
  char **argv = NULL;
  ElInitialize(&argc,&argv);
  return R_NilValue;
}

SEXP finalize(){
  ElFinalize();
  return R_NilValue;
}

SEXP initialized(){
  SEXP ans=PROTECT(allocVector(LGLSXP,1));
  bool status;
  ElInitialized( &status);
  LOGICAL(ans)[0]=status;
  UNPROTECT(1);
  return ans;
}

SEXP printVersion(){
  ElPrintVersion(stdout);
  return R_NilValue;
}

SEXP printConfig(){
  ElPrintConfig(stdout);
  return R_NilValue;
}

SEXP printCCompilerInfo(){
  ElPrintCCompilerInfo(stdout);
  return R_NilValue;
}

SEXP printCxxCompilerInfo(){
  ElPrintCxxCompilerInfo(stdout);
  return R_NilValue;
}
