#ifndef insertionsort_h
#define insertionsort_h

#include "listUtils.h"

using namespace std;

template <class T>
void insertionSort(std::list<T>& L) {
    // Sort only if the list is not empty
    if(!L.empty()){
        // k is the main iterator, iterate through the List
        auto k = next(L.begin());
        while(k != L.end()){
            // Search which pos we'll replace with k (i will be the pos as an iterator)
            auto i = k;
            while(i != L.begin() && *k < *(prev(i))){
                i = prev(i);
            }
            auto t = next(k); // Save next(k) before the splice, to be able to continue here
            L.splice(i, L, k);
            cout << L << endl;
            k = t; // set new k position, this way we can progress on the list
        }
    }

}

#endif // insertionsort_h