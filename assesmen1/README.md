# Stuktur-Data-Assignment [assisment1] <Thoriq Al Kayyis>

### soal1
```C++
//SLLInventory.h
#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen; // percent, e.g., 10.5
};

struct Node;
typedef Node* address;

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

// ADT functions / procedures
bool isEmpty(const List &L);
void createList(List &L);
address allocate(const Product &P);
void deallocate(address addr);

void insertFirst(List &L, const Product &P);
void insertLast(List &L, const Product &P);
void insertAfter(List &L, address Q, const Product &P); // insert after node Q

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);

// Update by replacing the whole Product at position
bool updateAtPosition(List &L, int posisi, const Product &P); // returns true if updated
bool updateAtPositionInteractive(List &L, int posisi); // prompts user for product

void viewList(const List &L);
void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice);

// Additional
void MaxHargaAkhir(const List &L);

#endif

//SLLInventory.cpp
#include <iostream>
#include <iomanip>
#include "SLLInventory.h"

bool isEmpty(const List &L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
}

address allocate(const Product &P) {
    address p = new Node;
    p->info = P;
    p->next = nullptr;
    return p;
}

void deallocate(address addr) {
    delete addr;
}

void insertFirst(List &L, const Product &P) {
    address p = allocate(P);
    p->next = L.head;
    L.head = p;
}

void insertLast(List &L, const Product &P) {
    address p = allocate(P);
    if (isEmpty(L)) {
        L.head = p;
        return;
    }
    address cur = L.head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = p;
}

void insertAfter(List &L, address Q, const Product &P) {
    if (Q == nullptr) return;
    address p = allocate(P);
    p->next = Q->next;
    Q->next = p;
}

void deleteFirst(List &L, Product &P) {
    if (isEmpty(L)) return;
    address p = L.head;
    P = p->info;
    L.head = p->next;
    deallocate(p);
}

void deleteLast(List &L, Product &P) {
    if (isEmpty(L)) return;
    if (L.head->next == nullptr) {
        P = L.head->info;
        deallocate(L.head);
        L.head = nullptr;
        return;
    }
    address prev = nullptr, cur = L.head;
    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }
    P = cur->info;
    prev->next = nullptr;
    deallocate(cur);
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q == nullptr || Q->next == nullptr) return;
    address p = Q->next;
    P = p->info;
    Q->next = p->next;
    deallocate(p);
}

static float HargaAkhir(const Product &P) {
    return P.HargaSatuan * (1.0f - P.DiskonPersen / 100.0f);
}

bool updateAtPosition(List &L, int posisi, const Product &P) {
    if (posisi <= 0) return false;
    address cur = L.head;
    int idx = 1;
    while (cur != nullptr && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur == nullptr) return false;
    cur->info = P;
    return true;
}

bool updateAtPositionInteractive(List &L, int posisi) {
    if (posisi <= 0) return false;
    address cur = L.head;
    int idx = 1;
    while (cur != nullptr && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur == nullptr) return false;
    Product P;
    cout << "Masukkan data baru untuk posisi " << posisi << "\n";
    cout << "Nama: ";
    getline(cin >> ws, P.Nama);
    cout << "SKU: ";
    getline(cin, P.SKU);
    cout << "Jumlah: ";
    cin >> P.Jumlah;
    cout << "HargaSatuan: ";
    cin >> P.HargaSatuan;
    cout << "DiskonPersen: ";
    cin >> P.DiskonPersen;
    cur->info = P;
    return true;
}

void viewList(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    address cur = L.head;
    int idx = 1;
    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(8) << "SKU" << setw(8) << "Jumlah" << setw(14) << "HargaSatuan" << setw(14) << "Diskon(%)" << setw(14) << "HargaAkhir" << endl;
    cout << string(85, '-') << endl;
    while (cur != nullptr) {
        cout << setw(5) << idx
             << setw(20) << cur->info.Nama
             << setw(8) << cur->info.SKU
             << setw(8) << cur->info.Jumlah
             << setw(14) << fixed << setprecision(2) << cur->info.HargaSatuan
             << setw(14) << cur->info.DiskonPersen
             << setw(14) << fixed << setprecision(2) << HargaAkhir(cur->info)
             << endl;
        cur = cur->next;
        idx++;
    }
}

void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    address cur = L.head;
    int idx = 1;
    bool found = false;
    cout << "Hasil pencarian HargaAkhir dalam rentang [" << minPrice << ", " << maxPrice << "]:" << endl;
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        if (ha >= minPrice && ha <= maxPrice) {
            cout << "Posisi " << idx << ": " << cur->info.Nama << " (SKU: " << cur->info.SKU << ") - HargaAkhir = " << fixed << setprecision(2) << ha << endl;
            found = true;
        }
        cur = cur->next;
        idx++;
    }
    if (!found) cout << "Tidak ditemukan produk dalam rentang tersebut." << endl;
}

void MaxHargaAkhir(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    // first pass: find max
    address cur = L.head;
    float maxHA = HargaAkhir(cur->info);
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        if (ha > maxHA) maxHA = ha;
        cur = cur->next;
    }
    // second pass: print all with maxHA
    cur = L.head;
    int idx = 1;
    cout << "Produk dengan HargaAkhir maksimum (" << fixed << setprecision(2) << maxHA << "):" << endl;
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        if (abs(ha - maxHA) < 1e-3) {
            cout << "Posisi " << idx << ": " << cur->info.Nama << " (SKU: " << cur->info.SKU << ") - Jumlah: " << cur->info.Jumlah << " - HargaSatuan: " << cur->info.HargaSatuan << " - Diskon(%): " << cur->info.DiskonPersen << "\n";
        }
        cur = cur->next;
        idx++;
    }
}


//main.cpp
#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {
    List L;
    createList(L);

    // 2. gunakan insertLast untuk 3 produk
    Product p1 {"Pulpen", "A001", 20, 2500.0f, 0.0f};
    Product p2 {"Buku Tulis", "A002", 15, 5000.0f, 10.0f};
    Product p3 {"Penghapus", "A003", 30, 1500.0f, 0.0f};

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    // 3. tampilkan list
    cout << "-- List awal --" << endl;
    viewList(L);
    cout << endl;

    // 4. deleteFirst 1x
    Product temp;
    deleteFirst(L, temp);
    cout << "Setelah deleteFirst() -> produk yang dihapus: " << temp.Nama << " (" << temp.SKU << ")" << endl;

    // 5. tampilkan list kembali
    cout << "-- List setelah deleteFirst --" << endl;
    viewList(L);
    cout << endl;

    // 6. Update data pada posisi ke-2 -> gunakan data baru
    Product newP {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    bool ok = updateAtPosition(L, 2, newP);
    if (!ok) cout << "Update gagal: posisi tidak ada." << endl;

    // 7. tampilkan list setelah update
    cout << "-- List setelah update posisi 2 --" << endl;
    viewList(L);
    cout << endl;

    // 8. searching berdasarkan HargaAkhir dalam rentang [2000, 7000]
    cout << "-- Searching HargaAkhir [2000,7000] --" << endl;
    searchByFinalPriceRange(L, 2000.0f, 7000.0f);
    cout << endl;

    // Bagian B: panggil MaxHargaAkhir
    MaxHargaAkhir(L);

    return 0;
}

```
### output soal1
<img width="940" height="752" alt="image" src="https://github.com/user-attachments/assets/2990b2d3-dee6-4d6e-a826-f6dd3d62e9b2" />


### soal 2
```C++
// DLLplaylist.h
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>

struct Song {
    std::string Title;
    std::string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; // 0.0 - 5.0
};

struct Node {
    Song info;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

bool isEmpty(const List& L);
void createList(List& L);
Node* allocate(const Song& S);
void deallocate(Node* P);
void insertFirst(List& L, const Song& S);
void insertLast(List& L, const Song& S);
void insertAfter(List& L, Node* Q, const Song& S);
void insertBefore(List& L, Node* Q, const Song& S);
void deleteFirst(List& L, Song& S);
void deleteLast(List& L, Song& S);
void deleteAfter(List& L, Node* Q, Song& S);
void deleteBefore(List& L, Node* Q, Song& S);
void updateAtPosition(List& L, int posisi, const Song& newS);
void updateBefore(List& L, Node* Q, const Song& newS);
void viewList(const List& L);
void searchByPopularityRange(const List& L, float minScore, float maxScore);

Node* getNodeAt(const List& L, int posisi); // returns nullptr if out of range
float popularityScore(const Song& s);

#endif


//DLLplaylist.cpp
#include <iostream>
#include <iomanip>
#include "DLLPlaylist.h"

bool isEmpty(const List& L) {
    return (L.head == nullptr && L.tail == nullptr);
}

void createList(List& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

Node* allocate(const Song& S) {
    Node* p = new(std::nothrow) Node;
    if (p != nullptr) {
        p->info = S;
        p->prev = nullptr;
        p->next = nullptr;
    }
    return p;
}

void deallocate(Node* P) {
    delete P;
}

void insertFirst(List& L, const Song& S) {
    Node* p = allocate(S);
    if (p == nullptr) return; // allocation failed
    if (isEmpty(L)) {
        L.head = L.tail = p;
    } else {
        p->next = L.head;
        L.head->prev = p;
        L.head = p;
    }
}

void insertLast(List& L, const Song& S) {
    Node* p = allocate(S);
    if (p == nullptr) return;
    if (isEmpty(L)) {
        L.head = L.tail = p;
    } else {
        p->prev = L.tail;
        L.tail->next = p;
        L.tail = p;
    }
}

void insertAfter(List& L, Node* Q, const Song& S) {
    if (Q == nullptr) return;
    if (Q == L.tail) {
        insertLast(L, S);
        return;
    }
    Node* p = allocate(S);
    if (p == nullptr) return;
    p->next = Q->next;
    p->prev = Q;
    Q->next->prev = p;
    Q->next = p;
}

void insertBefore(List& L, Node* Q, const Song& S) {
    if (Q == nullptr) return;
    if (Q == L.head) {
        insertFirst(L, S);
        return;
    }
    Node* p = allocate(S);
    if (p == nullptr) return;
    p->prev = Q->prev;
    p->next = Q;
    Q->prev->next = p;
    Q->prev = p;
}

void deleteFirst(List& L, Song& S) {
    if (isEmpty(L)) return;
    Node* p = L.head;
    S = p->info;
    if (L.head == L.tail) { // single node
        L.head = L.tail = nullptr;
    } else {
        L.head = p->next;
        L.head->prev = nullptr;
    }
    deallocate(p);
}

void deleteLast(List& L, Song& S) {
    if (isEmpty(L)) return;
    Node* p = L.tail;
    S = p->info;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.tail = p->prev;
        L.tail->next = nullptr;
    }
    deallocate(p);
}

void deleteAfter(List& L, Node* Q, Song& S) {
    if (Q == nullptr || Q->next == nullptr) return;
    Node* p = Q->next;
    S = p->info;
    Q->next = p->next;
    if (p->next != nullptr) p->next->prev = Q;
    else L.tail = Q; // removed tail
    deallocate(p);
}

void deleteBefore(List& L, Node* Q, Song& S) {
    if (Q == nullptr || Q->prev == nullptr) return;
    Node* p = Q->prev;
    S = p->info;
    Q->prev = p->prev;
    if (p->prev != nullptr) p->prev->next = Q;
    else L.head = Q; // removed head
    deallocate(p);
}

void updateAtPosition(List& L, int posisi, const Song& newS) {
    Node* target = getNodeAt(L, posisi);
    if (target == nullptr) return;
    target->info = newS;
}

void updateBefore(List& L, Node* Q, const Song& newS) {
    if (Q == nullptr || Q->prev == nullptr) return;
    Q->prev->info = newS;
}

void viewList(const List& L) {
    std::cout << "Daftar Lagu:\n";
    std::cout << std::left
              << std::setw(6) << "No"
              << std::setw(20) << "Title"
              << std::setw(16) << "Artist"
              << std::setw(10) << "Duration"
              << std::setw(12) << "PlayCount"
              << std::setw(8) << "Rating"
              << std::setw(14) << "PopScore"
              << "\n";
    std::cout << "-----------------------------------------------------------------------\n";
    Node* p = L.head;
    int idx = 1;
    while (p != nullptr) {
        std::cout << std::left
                  << std::setw(6) << idx
                  << std::setw(20) << p->info.Title
                  << std::setw(16) << p->info.Artist
                  << std::setw(10) << p->info.DurationSec
                  << std::setw(12) << p->info.PlayCount
                  << std::setw(8) << std::fixed << std::setprecision(1) << p->info.Rating
                  << std::setw(14) << std::fixed << std::setprecision(2) << popularityScore(p->info)
                  << "\n";
        p = p->next;
        idx++;
    }
    std::cout << std::defaultfloat;
}

void searchByPopularityRange(const List& L, float minScore, float maxScore) {
    std::cout << "\nHasil Searching PopularityScore dalam rentang [" << minScore << ", " << maxScore << "]:\n";
    Node* p = L.head;
    int idx = 1;
    bool found = false;
    while (p != nullptr) {
        float ps = popularityScore(p->info);
        if (ps >= minScore && ps <= maxScore) {
            found = true;
            std::cout << "Posisi " << idx << " - " << p->info.Title << " | Artist: " << p->info.Artist
                      << " | PopScore: " << std::fixed << std::setprecision(2) << ps << "\n";
        }
        p = p->next;
        idx++;
    }
    if (!found) std::cout << "Tidak ditemukan lagu dalam rentang tersebut.\n";
}

Node* getNodeAt(const List& L, int posisi) {
    if (posisi <= 0) return nullptr;
    Node* p = L.head;
    int idx = 1;
    while (p != nullptr && idx < posisi) {
        p = p->next;
        idx++;
    }
    return (idx == posisi) ? p : nullptr;
}

float popularityScore(const Song& s) {
    return 0.8f * static_cast<float>(s.PlayCount) + 20.0f * s.Rating;
}


//main.cpp
#include <iostream>
#include "DLLPlaylist.h"

int main() {
    List L;
    createList(L);

    // 1. Masukkan 3 lagu menggunakan insertLast
    Song s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2f};
    Song s2 = {"Langkahmu", "Delta", 185, 320, 4.8f};
    Song s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9f};

    insertLast(L, s1);
    insertLast(L, s2);
    insertLast(L, s3);

    // 3. Tampilkan list
    std::cout << ">>> Setelah insertLast 3 lagu:\n";
    viewList(L);

    // 4. Lakukan deleteLast sebanyak 1x
    Song removed;
    deleteLast(L, removed);
    std::cout << "\n>>> Setelah deleteLast 1x (menghapus: " << removed.Title << ")\n";
    viewList(L);

    // 5. Update node pada posisi ke-2 menggunakan updateAtPosition()
    Song newPos2 = {"Pelita", "Luna", 200, 260, 4.5f};
    updateAtPosition(L, 2, newPos2); // pos 2
    std::cout << "\n>>> Setelah updateAtPosition posisi 2 diganti menjadi 'Pelita':\n";
    viewList(L);

    // 7. Operasi BEFORE
    // Gunakan node pada posisi ke-2 untuk operasi before:
    Node* nodePos2 = getNodeAt(L, 2);
    if (nodePos2 == nullptr) {
        std::cerr << "Node posisi 2 tidak ditemukan. Operasi BEFORE dilewati.\n";
    } else {
        // a. insertBefore pada node posisi 2
        Song sb = {"Senandung", "Mira", 175, 120, 4.0f};
        insertBefore(L, nodePos2, sb);
        std::cout << "\n>>> Setelah insertBefore pada posisi 2 (menambahkan 'Senandung'):\n";
        viewList(L);

        // b. updateBefore pada node posisi 2 (masukkan data baru bebas)
        Song ub = {"Nada Baru", "Cinta", 190, 80, 3.7f}; // data bebas
        // get node at pos 2 again because list changed: we want 'node posisi 2' original reference
        nodePos2 = getNodeAt(L, 2);
        updateBefore(L, nodePos2, ub);
        std::cout << "\n>>> Setelah updateBefore pada node posisi 2 (mengubah node sebelum pos2):\n";
        viewList(L);

        Node* nodePos3 = getNodeAt(L, 3);
        if (nodePos3 != nullptr) {
            Song delb;
            deleteBefore(L, nodePos3, delb);
            std::cout << "\n>>> Setelah deleteBefore pada posisi 3 (menghapus node sebelum pos3: " << delb.Title << ")\n";
            viewList(L);
        } else {
            std::cout << "Node posisi 3 tidak ada; deleteBefore dilewati.\n";
        }
    }

    float minScore = 150.0f;
    float maxScore = 300.0f;
    searchByPopularityRange(L, minScore, maxScore);

    return 0;
}


```
### ouput soal2
<img width="940" height="635" alt="image" src="https://github.com/user-attachments/assets/f3bbce57-9ff1-4ca3-82e8-e9c2d6ea459e" />
<img width="940" height="622" alt="image" src="https://github.com/user-attachments/assets/195220d7-b2f0-4879-ba97-fce2b8b1f6c4" />




### soal 3
```C++
//stackmahasiswa.h
#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S, Mahasiswa &M);
void Update(StackMahasiswa &S, int posisi, Mahasiswa M);
void View(StackMahasiswa S);
float NilaiAkhir(Mahasiswa M);
void SearchNilaiAkhir(StackMahasiswa S, float Min, float Max);
void MaxNilaiAkhir(StackMahasiswa S);

#endif


//stackmahasiswa.cpp
#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push.\n";
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = M;
}

void Pop(StackMahasiswa &S, Mahasiswa &M) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak bisa pop.\n";
        return;
    }
    M = S.dataMahasiswa[S.Top];
    S.Top--;
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    // posisi dari 1 (atas) kebawah
    int index = S.Top - posisi + 1;
    if (index < 0 || index > S.Top) {
        cout << "Posisi tidak valid.\n";
        return;
    }
    S.dataMahasiswa[index] = M;
}

float NilaiAkhir(Mahasiswa M) {
    return 0.2 * M.NilaiTugas + 0.4 * M.NilaiUTS + 0.4 * M.NilaiUAS;
}

void View(StackMahasiswa S) {
    cout << "\n=== Isi Stack Mahasiswa ===\n";
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    int posisi = 1;
    for (int i = S.Top; i >= 0; i--) {
        cout << posisi << ". "
             << S.dataMahasiswa[i].Nama << " | "
             << S.dataMahasiswa[i].NIM << " | "
             << "Tugas: " << S.dataMahasiswa[i].NilaiTugas << " | "
             << "UTS: " << S.dataMahasiswa[i].NilaiUTS << " | "
             << "UAS: " << S.dataMahasiswa[i].NilaiUAS
             << " | NA: " << NilaiAkhir(S.dataMahasiswa[i]) << endl;
        posisi++;
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float Min, float Max) {
    cout << "\n=== Searching Nilai Akhir (" << Min << " - " << Max << ") ===\n";

    bool found = false;
    int posisi = 1;

    for (int i = S.Top; i >= 0; i--) {
        float NA = NilaiAkhir(S.dataMahasiswa[i]);
        if (NA >= Min && NA <= Max) {
            cout << "Posisi " << posisi << " - "
                 << S.dataMahasiswa[i].Nama
                 << " | Nilai Akhir: " << NA << endl;
            found = true;
        }
        posisi++;
    }

    if (!found) {
        cout << "Tidak ada data dalam rentang tersebut.\n";
    }
}

void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    float maxNA = -999;
    for (int i = S.Top; i >= 0; i--) {
        float nilai = NilaiAkhir(S.dataMahasiswa[i]);
        if (nilai > maxNA) maxNA = nilai;
    }

    cout << "\n=== Nilai Akhir Terbesar: " << maxNA << " ===\n";

    int posisi = 1;
    for (int i = S.Top; i >= 0; i--) {
        if (NilaiAkhir(S.dataMahasiswa[i]) == maxNA) {
            cout << "Posisi " << posisi << " - "
                 << S.dataMahasiswa[i].Nama
                 << " (" << S.dataMahasiswa[i].NIM << ")\n";
        }
        posisi++;
    }
}


//main.cpp
#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    // Data mahasiswa sesuai soal
    Mahasiswa m1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa m2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa m3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa m4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa m5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa m6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    // Push semua data
    Push(S, m1);
    Push(S, m2);
    Push(S, m3);
    Push(S, m4);
    Push(S, m5);
    Push(S, m6);

    cout << "=== STACK SETELAH INPUT ===\n";
    View(S);

    // Pop 1x
    Mahasiswa removed;
    Pop(S, removed);
    cout << "\n=== SETELAH POP 1X ===\n";
    View(S);

    // Update posisi ke-3
    Mahasiswa updateData = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, updateData);

    cout << "\n=== SETELAH UPDATE POSISI 3 ===\n";
    View(S);

    // Searching sesuai soal
    cout << "\n=== SEARCH NILAI AKHIR 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    // Max nilai akhir
    cout << "\n=== NILAI AKHIR TERBESAR ===\n";
    MaxNilaiAkhir(S);

    return 0;
}
```
### output soal 3
<img width="940" height="570" alt="image" src="https://github.com/user-attachments/assets/e84675fd-9b4c-42dc-babf-652c0a6def7d" />
<img width="940" height="577" alt="image" src="https://github.com/user-attachments/assets/6ddf1240-b509-44f1-a99b-ec8ed8e15d22" />

### soal 4
```C++
//queuePengiriman.h
#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <string>
using namespace std;

struct Paket {
    string Resi, Pengirim, Tujuan;
    int Berat;
};

const int MAX = 5;

struct Queue {
    Paket data[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);

void enQueue(Queue &Q, Paket P);
void deQueue(Queue &Q, Paket &P);
void viewQueue(Queue Q);

long long totalBiaya(Queue Q);

#endif


//queuePengiriman.cpp
#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){ Q.head = Q.tail = -1; }
bool isEmpty(Queue Q){ return Q.head == -1; }
bool isFull(Queue Q){ return Q.tail == MAX-1; }

void enQueue(Queue &Q, Paket P){
    if(isFull(Q)) return;
    if(isEmpty(Q)){
        Q.head = Q.tail = 0;
        Q.data[0] = P;
    } else {
        Q.data[++Q.tail] = P;
    }
}

void deQueue(Queue &Q, Paket &P){
    if(isEmpty(Q)) return;
    P = Q.data[Q.head];
    for(int i=Q.head;i<Q.tail;i++)
        Q.data[i] = Q.data[i+1];
    Q.tail--;
    if(Q.tail < 0) Q.head = Q.tail = -1;
}

void viewQueue(Queue Q){
    if(isEmpty(Q)){ cout<<"(kosong)\n"; return; }
    for(int i=Q.head;i<=Q.tail;i++){
        cout<<i+1<<". "<<Q.data[i].Resi<<" | "
            <<Q.data[i].Pengirim<<" | "
            <<Q.data[i].Berat<<"kg | "
            <<Q.data[i].Tujuan<<"\n";
    }
}

long long totalBiaya(Queue Q){
    long long t = 0;
    for(int i=Q.head;i<=Q.tail;i++)
        t += Q.data[i].Berat * 8250LL;
    return t;
}


//main.cpp
#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main(){
    Queue Q; createQueue(Q);
    Paket p;

    enQueue(Q, {"123456","Hutao","Sumeru",14});
    enQueue(Q, {"234567","Ayaka","Fontaine",10});
    enQueue(Q, {"345678","Bennet","Natlan",7});
    enQueue(Q, {"456789","Furina","Liyue",16});
    enQueue(Q, {"567890","Nefer","Inazuma",6});

    cout<<"Awal:\n"; viewQueue(Q);

    deQueue(Q,p);
    cout<<"\nSetelah deQueue:\n"; viewQueue(Q);

    cout<<"\nTotal Biaya: Rp "<<totalBiaya(Q)<<"\n";
}
```

### output no4
<img width="1128" height="668" alt="image" src="https://github.com/user-attachments/assets/c0b16ea0-1175-436c-8cd1-31e9c1effc40" />




