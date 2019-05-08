#include "fizzy.h"
#include <cassert>
#include <iostream>

using std::forward_list;


//Vous pouvez ajouter des fonctions annexes si nécessaire

void fizzBuzz(std::forward_list<int>& L,
              std::forward_list<int>& F,
              std::forward_list<int>& B,
              std::forward_list<int>& FB)
{
  assert(F.empty() and B.empty() and FB.empty());
  for (auto it = L.begin(); it != L.end(); ++it) {
    if ((*it % 3) == 0 && (*it % 5) == 0) {
      FB.splice_after(FB.end(), L, it);
    } else if ((*it % 3) == 0 && (*it % 5) != 0) {
      F.splice_after(F.end(), L, it);
      std::cout << *it << '\n';
    }
    // else if ((*it % 3) != 0 && (*it % 5) == 0) {
    //   F.splice_after(F.before_begin(), B, B.before_begin());
    // }
    // else if ((*it % 3) == 0 && (*it % 5) == 0) {
    //   F.splice_after(F.before_begin(), FB, FB.before_begin());
    // }
  }
// à compléter
}
