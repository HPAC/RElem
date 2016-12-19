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
  char buffer[256];
  FILE *tmp;
  tmp = tmpfile();
  ElPrintVersion(tmp);
  rewind(tmp);
  while (!feof(tmp)) {
    if (fgets (buffer,256,tmp) == NULL)
      break;
    Rprintf("%s",buffer);
  }
  fclose(tmp);
  return R_NilValue;
}

SEXP printConfig(){
  char buffer[256];
  FILE *tmp;
  tmp = tmpfile();
  ElPrintConfig(tmp);
  rewind(tmp);
  while (!feof(tmp)) {
    if (fgets (buffer,256,tmp) == NULL)
      break;
    Rprintf("%s",buffer);
  }
  fclose(tmp);
  return R_NilValue;
}

SEXP printCCompilerInfo(){
  char buffer[256];
  FILE *tmp;
  tmp = tmpfile();
  ElPrintCCompilerInfo(tmp);
  rewind(tmp);
  while (!feof(tmp)) {
    if (fgets (buffer,256,tmp) == NULL)
      break;
    Rprintf("%s",buffer);
  }
  fclose(tmp);
  return R_NilValue;
}

SEXP printCxxCompilerInfo(){
  char buffer[256];
  FILE *tmp;
  tmp = tmpfile();
  ElPrintCxxCompilerInfo(tmp);
  rewind(tmp);
  while (!feof(tmp)) {
    if (fgets (buffer,256,tmp) == NULL)
      break;
    Rprintf("%s",buffer);
  }
  fclose(tmp);
  return R_NilValue;
}
