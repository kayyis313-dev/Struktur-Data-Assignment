#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
using std::string;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen; // misal 10.5 untuk 10.5%
};

struct Node {
    Product info;
    Node* next;
};

struct List {
    Node* head;
};

// deklarasi fungsi / prosedur
bool isEmpty(const List& L);
void createList(List& L);
Node* allocate(const Product& P);
void deallocate(Node* addr);

void insertFirst(List& L, const Product& P);
void insertLast(List& L, const Product& P);
void insertAfter(List& L, Node* Q, const Product& P);

void deleteFirst(List& L, Product& P);
void deleteLast(List& L, Product& P);
void deleteAfter(List& L, Node* Q, Product& P);

void updateAtPosition(List& L, int posisi, const Product& newData);
void viewList(const List& L);
void searchByFinalPriceRange(const List& L, float minPrice, float maxPrice);

float hargaAkhir(const Product& P);
void MaxHargaAkhir(const List& L);

#endif // SLLINVENTORY_H
