# Function to sample discount parameter in Pitman-Yor process

#' Title
#'
#' @param dsct
#' @param n.sp
#' @param t.tab
#' @param sp.c
#' @param n.s.tab
#' @param conc
#'
#' @return
#' @export
#'
#' @examples
sampDsct <- function(dsct, n.sp, t.tab, sp.c, n.s.tab, conc) {
  .Call("sampDsct_", as.double(dsct), as.integer(n.sp), as.integer(t.tab),
        as.integer(sp.c), as.integer(n.s.tab), as.double(conc))
}
