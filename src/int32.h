#ifndef int32_H
#define int32_H

#include <vector>
#include <Rcpp.h>

/*
 * note : RcppExport is an alias to `extern "C"` defined by Rcpp.
 *
 */
RcppExport SEXP unique32(SEXP x);
std::vector <int> unique32_compute(Rcpp::IntegerVector incoming);


#endif