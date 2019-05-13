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

    
    for (auto it = L.begin(), beforeIt = L.before_begin(); it != L.end(); ++it, ++beforeIt) {
        if ((*it % 3) == 0 && (*it % 5) == 0) {
            FB.splice_after(FB.before_begin(), L, beforeIt);
        } else if ((*it % 3) == 0) {
            F.splice_after(F.before_begin(), L, beforeIt);
        } else if ((*it % 5) == 0) {
            B.splice_after(B.before_begin(), L, beforeIt);
        }
    }


}
