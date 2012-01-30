#ifndef unique_jared_H
#define unique_jared_H

#include <vector>
#include <string>
#include <Rcpp.h>

/*
 * note : RcppExport is an alias to `extern "C"` defined by Rcpp.
 *
*/

// The R facing functions
RcppExport SEXP unique_32(SEXP x);
RcppExport SEXP unique_64(SEXP x);
RcppExport SEXP unique_str(SEXP x);

// the working functions
std::vector <int> unique_32_compute(Rcpp::IntegerVector incoming);
std::vector <int> unique_64_compute(Rcpp::IntegerVector incoming);
std::vector <std::string> unique_str_compute(Rcpp::CharacterVector incoming);


#endif