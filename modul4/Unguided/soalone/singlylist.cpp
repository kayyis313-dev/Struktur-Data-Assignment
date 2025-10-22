#include "singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    if (P != Nil) {
        P->data = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        cout << "Isi List: ";
        while (P != Nil) {
            cout << P->data << " ";
            P = P->next;
        }
        cout << endl;
    }
}
