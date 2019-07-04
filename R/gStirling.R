# R functions to calculate generalized Stirling numbers


#' @param n
#' @param m
#' @param dsct
#'
#' @useDynLib gStirling gStirling_
#' @export
gStirling <- function(n, m, dsct) {
  if (floor(n)!=n | floor(m)!=m | n<=0 | m<=0)
    stop("n and m must be positive integers")
  if (dsct<0 | dsct>1)
    stop("dsct must be numeric and between 0 and 1")

  .Call("gStirling_", as.integer(n), as.integer(m), dsct)
}
