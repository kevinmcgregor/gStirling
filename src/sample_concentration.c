// Wrapper to use sampleb function (sample concentration parameter) from STB library

#include "stdio.h"
#include <R.h>
#include <Rinternals.h>
#include "stable.h"
#include "psample.h"
#include "srng.h"
#include "lgamma.h"

SEXP sampConc_(SEXP b_in, SEXP N, SEXP T, SEXP shape, SEXP scale, SEXP dsct, SEXP iter) {
  double b = REAL(b_in)[0];
  double sh = REAL(shape)[0];
  double sc = REAL(scale)[0];
  double d = REAL(dsct)[0];
  int itr = INTEGER(iter)[0];

  rngp_t rng = NULL;

  scnt_int tempN = (scnt_int) INTEGER(N)[0];
  scnt_int tempT = (scnt_int) INTEGER(T)[0];

  SEXP result = PROTECT(allocVector(REALSXP, 1));
  REAL(result)[0] = sampleb(b, 1, sh, sc, &tempN, &tempT, d, rng, itr, 1);
  UNPROTECT(1);
  return result;
}
