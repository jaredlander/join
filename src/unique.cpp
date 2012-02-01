#include "khash.h"
#include "unique.h"

using namespace std;
using namespace Rcpp;

// Functions to take a vector of values (integer or character) and return the unique values
// Will build a function that reads in from and returns to R and a function that does the work

/*! @function
  @abstract     Creates vector of unique values from incoming vector
  @param  incoming  Vector of values that are being checked for uniqueness
  @return       A vector of unique values
*/
#define MakeHashFunction(hashType, hashName, outType, inType)             \
/* begin function definition*/                                     \
/* Instantiate the apropriate hash functions */                     \
/* declare type of hash, int keys, value is character */            \
KHASH_MAP_INIT_##hashType(hashName, char)  \
vector <outType> unique_##hashName##_compute(inType incoming)                  \
{                                                                   \
    /* Get the size the vector */                                   \
    int theSize = incoming.size();                                  \
                                                                    \
    /* record keeping vars */                                       \
    int ret;                                                        \
                                                                    \
    /* unique counter, start at 0 */                                \
    int j = 0;                                                      \
                                                                    \
    /* allocate vector for storing unique values, make it at least as big as incoming */   \
    vector <outType> uniques(theSize);                              \
                                                                    \
    /* iterator var */                                              \
    khiter_t k;                                                     \
                                                                    \
    /* make an int32 hash table named h */                          \
	khash_t(hashName) *h = kh_init(hashName);                       \
                                                                    \
    /* resize the hash so it's at least as big as incoming */       \
    kh_resize(hashName, h, theSize);                                \
                                                                    \
    for(int i=0; i<theSize; i++)                                    \
    {                                                               \
        /* put the key into the hash */                             \
        /* ret will indicate if the key was already there, 0 if it is there already */  \
        k = kh_put(hashName, h, incoming[i], &ret);                 \
                                                                    \
        if(ret == 0)                                                \
        {                                                           \
            /* do nothing */                                        \
        }                                                           \
        else                                                        \
        {                                                           \
            /* put it into the unique list */                       \
            uniques[j] = incoming[i];                               \
            /* iterate j */                                         \
            j++;                                                    \
        }                                                           \
    }                                                               \
                                                                    \
    /* destroy the hash */                                          \
    kh_destroy(hashName, h);                                        \
                                                                    \
    /* resize the unique vector to get rid of the empty cells */    \
    uniques.resize(j);                                              \
                                                                    \
    /* return the vector of unique values */                        \
    return(uniques);                                                \
}                                                                   \


// Build integer uniqueing using 32 bit keys
MakeHashFunction(INT, 32, int, IntegerVector)
// Build integer uniqueing using 64 bit keys
MakeHashFunction(INT64, 64, int, IntegerVector)
// Build string uniqueing using string keys
MakeHashFunction(STR, str, string, CharacterVector)




/*! @function                                               
  @abstract     Creates vector of unique values from incoming vector by calling the apropriate helper function
  @param  x  Vector of integer or character values that are being checked for uniqueness
  @return       A vector of unique integer or character values
*/
#define MakeRFunction(hashName, outType)                           \
/* Code to generate functions that are called from R */     \
SEXP unique_##hashName(SEXP x)                                 \
{                                                           \
    vector <outType> uniques = unique_##hashName##_compute(x);   \
                                                            \
    return(wrap(uniques));                                  \
}


// Build R function for integers with 32 bit key
MakeRFunction(32, int)
// Build R function for integers with 64 bit key
MakeRFunction(64, int)
// Build R function for strings with string key
MakeRFunction(str, string)