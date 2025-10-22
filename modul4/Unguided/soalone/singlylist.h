#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL
typedef int infotype;

struct Elmlist;           
typedef Elmlist* address;  

struct Elmlist {
    infotype data;
    address next;
};

struct List {
    address first;
};

// Deklarasi fungsi dan prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
