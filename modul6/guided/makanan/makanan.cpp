#include "SLLinventory.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

// Helper: hitung harga akhir
float hargaAkhir(const Product& P) {
    return P.HargaSatuan * (1.0f - P.DiskonPersen / 100.0f);
}

// Basic list functions
bool isEmpty(const List& L) {
    return L.head == nullptr;
}

void createList(List& L) {
    L.head = nullptr;
}

Node* allocate(const Product& P) {
    Node* n = new (std::nothrow) Node;
    if (n != nullptr) {
        n->info = P;
        n->next = nullptr;
    }
    return n;
}

void deallocate(Node* addr) {
    delete addr;
}

// Insert operations
void insertFirst(List& L, const Product& P) {
    Node* n = allocate(P);
    if (n == nullptr) return;
    n->next = L.head;
    L.head = n;
}

void insertLast(List& L, const Product& P) {
    Node* n = allocate(P);
    if (n == nullptr) return;
    if (isEmpty(L)) {
        L.head = n;
    } else {
        Node* cur = L.head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = n;
    }
}

void insertAfter(List& L, Node* Q, const Product& P) {
    if (Q == nullptr) return;
    Node* n = allocate(P);
    if (n == nullptr) return;
    n->next = Q->next;
    Q->next = n;
}

// Delete operations (output product via reference)
void deleteFirst(List& L, Product& P) {
    if (isEmpty(L)) return;
    Node* del = L.head;
    P = del->info;
    L.head = del->next;
    deallocate(del);
}

void deleteLast(List& L, Product& P) {
    if (isEmpty(L)) return;
    if (L.head->next == nullptr) {
        // only one node
        P = L.head->info;
        deallocate(L.head);
        L.head = nullptr;
        return;
    }
    Node* prev = nullptr;
    Node* cur = L.head;
    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }
    // cur is last, prev not null
    P = cur->info;
    prev->next = nullptr;
    deallocate(cur);
}

void deleteAfter(List& L, Node* Q, Product& P) {
    if (Q == nullptr) return;
    Node* target = Q->next;
    if (target == nullptr) return;
    P = target->info;
    Q->next = target->next;
    deallocate(target);
}

// Update at position (1-based). If posisi invalid, do nothing.
void updateAtPosition(List& L, int posisi, const Product& newData) {
    if (posisi <= 0) return;
    Node* cur = L.head;
    int idx = 1;
    while (cur != nullptr && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur == nullptr) return; // posisi tidak ada
    cur->info = newData;
}

// View list: tampilkan Nama, SKU, Jumlah, HargaSatuan, DiskonPersen, HargaAkhir dan indeks
void viewList(const List& L) {
    cout << "Daftar Produk:\n";
    if (isEmpty(L)) {
        cout << "(kosong)\n";
        return;
    }
    Node* cur = L.head;
    int idx = 1;
    cout << std::left;
    while (cur != nullptr) {
        float akhir = hargaAkhir(cur->info);
        cout << idx << ". "
             << "Nama: " << cur->info.Nama << " | "
             << "SKU: " << cur->info.SKU << " | "
             << "Jumlah: " << cur->info.Jumlah << " | "
             << "HargaSatuan: " << fixed << setprecision(2) << cur->info.HargaSatuan << " | "
             << "Diskon(%): " << fixed << setprecision(2) << cur->info.DiskonPersen << " | "
             << "HargaAkhir: " << fixed << setprecision(2) << akhir
             << "\n";
        cur = cur->next;
        idx++;
    }
}

// Search by final price inclusive
void searchByFinalPriceRange(const List& L, float minPrice, float maxPrice) {
    cout << "Hasil pencarian HargaAkhir dalam rentang [" << minPrice << ", " << maxPrice << "]\n";
    if (isEmpty(L)) {
        cout << "(kosong)\n";
        return;
    }
    Node* cur = L.head;
    int idx = 1;
    bool found = false;
    while (cur != nullptr) {
        float akhir = hargaAkhir(cur->info);
        if (akhir >= minPrice && akhir <= maxPrice) {
            found = true;
            cout << idx << ". "
                 << "Nama: " << cur->info.Nama << " | SKU: " << cur->info.SKU
                 << " | HargaAkhir: " << fixed << setprecision(2) << akhir << "\n";
        }
        cur = cur->next;
        idx++;
    }
    if (!found) cout << "Tidak ada produk yang ditemukan pada rentang tersebut.\n";
}

// MaxHargaAkhir: tampilkan semua produk yang memiliki hargaAkhir maksimum
void MaxHargaAkhir(const List& L) {
    cout << "MaxHargaAkhir():\n";
    if (isEmpty(L)) {
        cout << "(kosong)\n";
        return;
    }
    // cari nilai max
    Node* cur = L.head;
    float maxVal = hargaAkhir(cur->info);
    Node* it = cur->next;
    while (it != nullptr) {
        float val = hargaAkhir(it->info);
        if (val > maxVal) maxVal = val;
        it = it->next;
    }
    // tampilkan semua yang sama dengan maxVal
    cur = L.head;
    int idx = 1;
    bool found = false;
    while (cur != nullptr) {
        float val = hargaAkhir(cur->info);
        if ((val - maxVal) < 1e-4f) {
            found = true;
            cout << idx << ". "
                 << "Nama: " << cur->info.Nama << " | SKU: " << cur->info.SKU
                 << " | HargaAkhir: " << fixed << setprecision(2) << val << "\n";
        }
        cur = cur->next;
        idx++;
    }
    if (!found) {
        cout << "(tidak ditemukan)\n";
    }
}
