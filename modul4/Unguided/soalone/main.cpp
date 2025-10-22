#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address a1, a2, a3, a4, a5;

    CreateList(L);

    a1 = alokasi(2);
    insertFirst(L, a1);

    a2 = alokasi(0);
    insertFirst(L, a2);

    a3 = alokasi(8);
    insertFirst(L, a3);

    a4 = alokasi(12);
    insertFirst(L, a4);

    a5 = alokasi(9);
    insertFirst(L, a5);

    printInfo(L);  
    return 0;
}
