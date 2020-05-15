# Function to sample concentration parameter in Pitman-Yor process

#' Title
#'
#' @param conc
#' @param n
#' @param tab
#' @param p.shape
#' @param p.scale
#' @param dsct
#'
#' @return
#' @export
#'
#' @examples
sampConc <- function(conc, n, tab, p.shape, p.scale, dsct, iter=1) {
  .Call("sampConc_", as.double(conc), as.integer(n), as.integer(tab),
        as.double(p.shape), as.double(p.scale), dsct, as.integer(iter))
}
