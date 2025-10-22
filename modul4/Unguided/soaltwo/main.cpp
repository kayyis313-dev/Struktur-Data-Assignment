#include "SinglyList.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi(9));
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(2));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(0));

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, 2);

    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}