#include "fizzy.h"
#include <cassert>
#include <iostream>

using std::forward_list;


//Vous pouvez ajouter des fonctions annexes si nécessaire

void fizzBuzz(std::forward_list<int>& L,
              std::forward_list<int>& F,
              std::forward_list<int>& B,
              std::forward_list<int>& FB) {
    assert(F.empty() and B.empty() and FB.empty());


    auto fend  = F.before_begin();
    auto bend  = B.before_begin();
    auto fbend = FB.before_begin();

    for (auto it = L.begin(), beforeIt = L.before_begin(); it != L.end(); ++it) {

        if ((*it % 3) == 0 && (*it % 5) == 0) {
            // move it into FB list
            FB.splice_after(fbend, L, beforeIt);

            fbend = std::next(fbend);

            // after the splice_after, the it iterator is still pointing
            //  on the element that was moved. We need to make it point back into
            //  the list we are fizzbuzzing
            it = beforeIt;

        } else if ((*it % 3) == 0) {
            F.splice_after(fend, L, beforeIt);

            fend = std::next(fend);

            it = beforeIt;
        } else if ((*it % 5) == 0) {
            B.splice_after(bend, L, beforeIt);

            bend = std::next(bend);

            it = beforeIt;
        } else {
            ++beforeIt;
        }
    }

}
