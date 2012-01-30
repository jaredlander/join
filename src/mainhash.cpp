#include <stdio.h>
#include <iostream>
#include <vector>
#include "khash.h"

using namespace std;

// declare type of hash, int keys, value is character
KHASH_MAP_INIT_INT(32, char)


int main()
{
    // record keeping vars
    int ret, isThere;
 
    // iterator var
    khiter_t k;
    
    // make an int32 hash table named h
	khash_t(32) *h = kh_init(32);
    cout << "Hash before resize: " << kh_size(h) << endl;
    
    int desiredSize;
    
    cout << "Please enter the size of the vector: ";
    cin >> desiredSize;
    
    // create vector to hold numbers with 5 unique values
    cout << "Creating vector." << endl;
    
    vector <int> fake(desiredSize);
    for(int i=0; i<fake.size(); i++)
    {
        fake[i] = i % 5;
    }
    
    int fakeSize = fake.size();
    
    // now go through each and test if they exist
    cout << "Creating holder." << endl;
    // store unique values
    vector <int> uniques(fakeSize);
    
    // counter for uniques
    int j = 0;
    int theFake;
    
    // resize the hash so it's at least as big as fake
    //kh_resize(32, h, fakeSize);
    kh_resize(32, h, 17);
    //   kh_clear(32, h);
    
    cout << "Hash after resize: " << kh_size(h) << endl;
    
    k = kh_put(32, h, fake[0], &ret);
    uniques[0] <- fake[0];
    j++;
    for(int i=1; i<fakeSize; i++)
    {
        // hold this value of the vector
        theFake = fake[i];
        
        // check if this value is in the hash
        cout << "Checking if " << theFake << " is in the hash." << endl;
        k = kh_get(32, h, theFake);
        //cout << "Did get for " << theBill << endl;
        
        cout << "k: " << k << endl;
        
        //isThere = kh_exist(h, k);
        //cout << "isThere: " << isThere << endl;
        //if(isThere)//
        if(kh_exist(h, k))
        {
            cout << theFake << " is in!" << endl;
        }
        else
        {
            cout << theFake << " is not there so let's add it" << endl;
            k = kh_put(32, h, theFake, &ret);
            
            uniques[j] = theFake;  // put it into the unique list
            j++;     // iterate j
        }
        cout << "Hash size after adding: " << kh_size(h) << endl;
    }
    
    // display j, if it is 0 then every value was already found to be in the hash
    cout << "j: " << j << endl;
    
    // now display the uniques
    cout << "Displaying uniques." << endl;// << "Should be 1, 2, 3, 4, 11." << endl;
    for(int i=0; i<j; i++)
    {
        cout << uniques[i] << endl;
    }
    // delete map
    kh_destroy(32, h);
    
    return 0;
}