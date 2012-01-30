#include <vector>
#include "khash.h"
#include "int32.h"
#include <Rcpp.h>

using namespace std;
using namespace Rcpp;

// Functions to take a vector of integers and return the unique values
// Will build a function that reads in from and returns to R and a function that does the work

// declare type of hash, int keys, value is character
KHASH_MAP_INIT_INT(32, char)


/*! @function
  @abstract     Creates vector of unique values from incoming vector
  @param  incoming  Vector of values that are being checked for uniqueness
  @return       A vector of unique values
 */
vector <int> unique32_compute(IntegerVector incoming)
//IntegerVector unique32_compute(IntegerVector incoming)
{
    // Get the size the vector
    int theSize = incoming.size();

    // record keeping vars
    int ret;
    
    // unique counter, start at 0
    int j = 0;
    
    // allocate vector for storing unique values, make it at least as big as incoming
    //IntegerVector uniques(theSize);
    vector <int> uniques(theSize);
 
    // iterator var
    khiter_t k;
    
    // make an int32 hash table named h
	khash_t(32) *h = kh_init(32);
    
    // resize the hash so it's at least as big as incoming
    kh_resize(32, h, theSize);
    
    for(int i=0; i<theSize; i++)
    {        
        // put the key into the hash
        // ret will indicate if the key was already there, 0 if it is there already
        k = kh_put(32, h, incoming[i], &ret);
        
        if(ret == 0)
        {
            // do nothing
        }
        else
        {
            uniques[j] = incoming[i];  // put it into the unique list
            j++;     // iterate j
        }
    }

    // destroy the hash
    kh_destroy(32, h);
    
    // resize the unique vector to get rid of the empty cells
    uniques.resize(j);
    
    // return the vector of unique values
    return(uniques);
}


/*! @function
  @abstract     Creates vector of unique values from incoming vector by calling the helper function
  @param  x  Vector of integer values that are being checked for uniqueness
  @return       A vector of unique integer values
 */
//RcppExport 
SEXP unique32(SEXP x)
{
    vector <int> uniques = unique32_compute(x);
 //   
    return(wrap(uniques));
}