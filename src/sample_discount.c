// Wrapper to use samplea function (sample discount parameter) from STB library

#include "stdio.h"
#include <R.h>
#include <Rinternals.h>
#include "stable.h"
#include "psample.h"
#include "srng.h"
#include "lgamma.h"

SEXP sampDsct_(SEXP a_in, SEXP n_sp, SEXP T, SEXP sp_c, SEXP n_s_tab, SEXP conc, SEXP iter) {
  double a = REAL(a_in)[0];
  int n_s = INTEGER(n_sp)[0];
  double c = REAL(conc)[0];
  int itr = INTEGER(iter)[0];

  rngp_t rng = NULL;

  //scnt_int s_c[n_s][1];
  //stcnt_int n_st[n_s][1];
  scnt_int* atn = (scnt_int*) malloc(n_s*sizeof(scnt_int));
  stcnt_int* att = (stcnt_int*) malloc(n_s*sizeof(stcnt_int));

  for (int i=0; i<n_s; i++) {
    //s_c[i][0] = (scnt_int) INTEGER(sp_c)[i];
    //n_st[i][0] = (scnt_int) INTEGER(n_s_tab)[i];
    atn[i] = (scnt_int) INTEGER(sp_c)[i];
    att[i] = (scnt_int) INTEGER(n_s_tab)[i];
  }

  scnt_int tempT = (scnt_int) INTEGER(T)[0];

  SEXP result = PROTECT(allocVector(REALSXP, 1));
  REAL(result)[0] = samplea(a, 1, &n_s, &tempT, &atn, &att, NULL, &c, rng, itr, 1);
  UNPROTECT(1);
  return result;
}
