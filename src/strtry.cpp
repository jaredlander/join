#include "khash.h"
#include <Rcpp.h>
#include <string>
#include <iostream>

using namespace std;
using namespace Rcpp;

// Functions to take a vector of values (integer or character) and return the unique values
// Will build a function that reads in from and returns to R and a function that does the work

/*! @function
  @abstract     Creates vector of unique values from incoming vector
  @param  incoming  Vector of values that are being checked for uniqueness
  @return       A vector of unique values
*/
/* begin function definition*/                                     
/* Instantiate the apropriate hash functions */                     
//KHASH_MAP_INIT_INT(32, int)
KHASH_SET_INIT_STR(str)
//vector <string> unique_str_compute(vector <string> incoming)
vector <const char *> unique_str_compute(vector <const char *> incoming)
{                                                                   
    /* Get the size the vector */                                   
    int theSize = incoming.size();                                  
                                                                    
    /* record keeping vars */                                       
    int ret;                                                        
                                                                    
    /* unique counter, start at 0 */                                
    int j = 0;                                                      
                                                                    
    /* allocate vector for storing unique values, make it at least as big as incoming */   
    vector <const char *> uniques(theSize);                              
                                                                    
    /* iterator var */                                              
    khiter_t k;                                                     
                                                                    
    /* make an int32 hash table named h */                          
	khash_t(str) *h = kh_init(str);                       
                                                                    
    /* resize the hash so it's at least as big as incoming */       
    kh_resize(str, h, theSize);                                
    
    // variable to hold keys to insert
    //const char *inserter;
    
    for(int i=0; i<theSize; i++)                                    
    {                                                               
        //string mine = (string) incoming[i];
        /* put the key into the hash */                             
        /* ret will indicate if the key was already there, 0 if it is there already */
        //inserter = new char [incoming[i].size()];
        //inserter = incoming[i].c_str();
        
        //k = kh_put(str, h, inserter, &ret);
        k = kh_put(str, h, incoming[i], &ret);
                                                                    
        if(ret == 0)                                                
        {                                                           
            /* do nothing */                                        
        }                                                           
        else                                                        
        {                                                           
            /* put it into the unique list */                       
            uniques[j++] = incoming[i];
            //cout << "pushing" << endl;
            //uniques.push_back(incoming[i]);
            //cout << "pushed" << endl;
            //j++;
            //kh_val(h, k) = 1;
            /* iterate j */                                         
            //j++;                                                    
        }                                                           
        
        //cout << "ret for " << incoming[i] << ": " << ret << endl;
        // give a chance for interuption
        //R_CheckUserInterrupt();
    }                                                               
    //cout << "done" << endl;
    /* destroy the hash */                                          
    kh_destroy(str, h);                                        
                                                                    
    /* resize the unique vector to get rid of the empty cells */    
    uniques.resize(j);                                              
                                                                    
    cout << "returning" << endl;
    /* return the vector of unique values */                        
    return(uniques);                                                
}                                                                   


// Build integer uniqueing using 32 bit keys
//MakeHashFunction(INT, 32, int, IntegerVector)
// Build integer uniqueing using 64 bit keys
//MakeHashFunction(INT64, 64, int, IntegerVector)
// Build string uniqueing using string keys
//MakeHashFunction(STR, str, string, CharacterVector)




/*! @function                                               
  @abstract     Creates vector of unique values from incoming vector by calling the apropriate helper function
  @param  x  Vector of integer or character values that are being checked for uniqueness
  @return       A vector of unique integer or character values
*/

/* Code to generate functions that are called from R */     
RcppExport SEXP unique_str(SEXP x)                                 
{                                                           
    vector <const char *> x_ = as<vector <const char *> >(x);
    //CharacterVector x_(x);
    vector <const char *> uniques = unique_str_compute(x_);
                                                            
    return(wrap(uniques));                                  
}


// Build R function for integers with 32 bit key
//MakeRFunction(32, int)
// Build R function for integers with 64 bit key
//MakeRFunction(64, int)
// Build R function for strings with string key
//MakeRFunction(str, string)