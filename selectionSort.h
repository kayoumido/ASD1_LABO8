#ifndef selectionsort_h
#define selectionsort_h

#include "listUtils.h"

template <class T>
void selectionSort(std::list<T>& L) {
    if(!L.empty()){
        auto j = L.begin();
        auto pos = j;

        // next(j) to stop before the last element, don't need to check the last if all except the last are already sort
        while(next(j) != L.end()){
            pos = j;
            auto iMin = j++;
            auto i = j;

            // Search iMin
            while(i != L.end()){
                if(*i < *iMin){
                    iMin = i;
                }
                ++i;
            }

            // Use splice inplace of swap, to change iMin and pos
            L.splice(pos, L, iMin);
            std::cout << L << std::endl;
            j = ++iMin;
        }
    }

}

#endif