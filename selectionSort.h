#ifndef selectionsort_h
#define selectionsort_h

#include "forwardListUtils.h"

template <class T>
void selectionSort(std::forward_list<T>& L) {
    using namespace std;

    if (L.empty()) return;

    auto j = L.before_begin();

    while (next(j, 2) != L.end()) {

        auto imin   = j;
        auto i      = next(j);

        // search for the min
        while (next(i) != L.end()) {
            // since we're sorting a forward_list using splice_after,
            // we need to check if the NEXT element is the min.
            // this is because splice_after moves the element after the iterator it's given
            if (*next(i) < *next(imin))
                imin = i;

            i = next(i);
        }

        L.splice_after(j, L, imin);
        std::cout << L << std::endl;
        j = next(j);
    }
}

#endif