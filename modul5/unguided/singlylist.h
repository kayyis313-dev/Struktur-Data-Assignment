#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

// Struktur untuk elemen (node)
struct Node {
    int info;
    Node *next;
};

// Struktur untuk list
struct List {
    Node *first;
};

// Deklarasi fungsi dasar
void createList(List &L);
Node* alokasi(int x);
void dealokasi(Node *P);
void insertFirst(List &L, Node *P);
void printInfo(List L);

// Tambahan fungsi dari latihan 5.2
Node* findElm(List L, int x);
int totalInfo(List L);

#endif