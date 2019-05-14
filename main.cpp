#include "listUtils.h"
#include "selectionSort.h"

using std::cout; using std::endl;

int main() {
    auto L = readList<int>();
    cout << L << endl;
    selectionSort(L);
    cout << endl;
}