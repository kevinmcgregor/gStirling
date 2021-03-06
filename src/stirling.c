// Wrapper to get Stirling numbers from STB library

#include "stdio.h"
#include <R.h>
#include <Rinternals.h>
#include "stable.h"

SEXP gStirling_(SEXP n, SEXP m, SEXP dsct) {
  int nn = INTEGER(n)[0];
  int mm = INTEGER(m)[0];
  double d = REAL(dsct)[0];

  SEXP result = PROTECT(allocMatrix(REALSXP, nn, mm));

  stable_t *tab = S_make(nn,mm,nn,mm,d,S_STABLE);

  for (int i=0; i<nn; i++) {
    for (int j=0; j<mm; j++) {
      REAL(result)[i+nn*j] = S_S(tab, i+1, j+1);
    }
  }

  UNPROTECT(1);

  S_free(tab);

  return result;
}
