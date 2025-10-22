#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* alokasi(infotype x);
void dealokasi(Node* P);
void insertLast(List &L, Node* P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, infotype key);
int nbList(List L);
void deleteList(List &L);
void printList(List L);

#endif