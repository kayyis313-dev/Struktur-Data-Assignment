# <h1 align="center">Laporan Praktikum Modul4 Singly Linked List (Bagian Pertama)</h1>
<p align="center">Thoriq Al Kayyis</p>

## Dasar Teori

Bahasa pemrograman C merupakan bahasa yang bersifat terstruktur, di mana program dibagi menjadi beberapa blok atau bagian agar proses pembuatan dan pengembangannya menjadi lebih mudah.
Sementara itu, program C++ biasanya disimpan dengan ekstensi .CPP(singkatan dari *C plus plus*).
Sebelum program tersebut dapat dijalankan (dieksekusi), ia harus terlebih dahulu dikompilasi menggunakan kompiler C++.

#### 1. ADT
ADT adalah konsep yang memisahkan antara bagian yang bisa dilihat dan digunakan oleh pemrogram (interface) dengan bagian yang berisi cara kerjanya di dalam program (implementasi).
Bagian interface berisi daftar nama atau fungsi yang bisa dipakai, sedangkan implementasi menjelaskan bagaimana fungsi-fungsi itu dijalankan agar program bisa bekerja sesuai tujuan.

#### 2. Linked List
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan)
berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat
tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data
tunggal atau data majemuk. 


## Guided 

### 1. [ADT Linked List (insert)] 

```C++
//list.h
//header guard digunakan untuk mencegah file  header yang sama
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataMahasiswa isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { //Ini linked listnya
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev); 
void insertLast(linkedList &List, address nodeBaru);

#endif

//list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//main.cpp
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; //nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; //semua diinisialisasi Nil
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Kode di atas digunakan untuk membentuk struktur Linked List yang memiliki fungsi penyisipan (insert), yaitu menambahkan node baru ke dalam daftar, serta menampilkan hasil setelah proses penambahan dilakukan.


### 2. [ADT Linked list(insert, delete, count, clear)]

```C++
//list.h
//header guard digunakan untuk mencegah file  header yang sama
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataMahasiswa isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { 
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif


//list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama 
                 << ", NIM : " << nodeBantu->isidata.nim 
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}


//main.cpp
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; //nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; //semua diinisialisasi Nil
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Kode di atas digunakan untuk membangun ADT Linked List yang dilengkapi dengan beberapa fungsi tambahan, seperti penghapusan node, alokasi dan dealokasi memori, manipulasi data, serta menampilkan jumlah node setelah proses penghapusan.



## Unguided 

### 1. 
<img width="1015" height="531" alt="image" src="https://github.com/user-attachments/assets/7399840c-70c4-4e34-9fea-1fa3b6e28fc4" />
<img width="977" height="628" alt="image" src="https://github.com/user-attachments/assets/86ca996e-0043-4a61-b4d6-75db20dc8a31" />
<img width="958" height="423" alt="image" src="https://github.com/user-attachments/assets/ff3f6bcd-055b-4d3c-951f-17c749b7e0b8" />

```C++
//Singlylist.h
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

//singlylist.cpp
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

//main.cpp
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

```
#### Output:
<img width="1179" height="100" alt="Screenshot 2025-10-22 224432" src="https://github.com/user-attachments/assets/83df7a52-c05d-4c8a-ab65-cf56d214096d" />

Kode di atas digunakan untuk membuat ADT Single Linked List yang memiliki fungsi penyisipan data (insert) serta menampilkan isi list setelah data dimasukkan.


#### Full code Screenshot:
<img width="1896" height="1113" alt="image" src="https://github.com/user-attachments/assets/b8fb1f57-e809-4064-b03c-b0a066f1efc9" />



## Unguided 

### 2. 
<img width="940" height="339" alt="image" src="https://github.com/user-attachments/assets/b5b4d5b3-a58d-4a7c-9338-e973e222821b" />

```C++
//slinglylist.h
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


//singlylist.cpp
#include "SinglyList.h"

void createList(List &L) {
    L.first = nullptr;
}

Node* alokasi(infotype x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(Node* P) {
    delete P;
}

void insertLast(List &L, Node* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            dealokasi(L.first);
            L.first = nullptr;
        } else {
            Node* Q = L.first;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            dealokasi(Q->next);
            Q->next = nullptr;
        }
    }
}

void deleteAfter(List &L, infotype key) {
    Node* Q = L.first;
    while (Q != nullptr && Q->info != key) {
        Q = Q->next;
    }
    if (Q != nullptr && Q->next != nullptr) {
        Node* P = Q->next;
        Q->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.first = nullptr;
    cout << "\n- List Berhasil Terhapus -\n";
}

void printList(List L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}


//main.cpp
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
```
#### Output:
<img width="1188" height="272" alt="image" src="https://github.com/user-attachments/assets/10ebd82c-3783-46b2-9940-585e86dbfd98" />


Kode di atas digunakan untukmembangun dan mengelola struktur data Single Linked List menggunakan bahasa C++.
Dalam program ini, setiap elemen (node) menyimpan data serta penunjuk ke elemen berikutnya.

Dengan kata lain, program ini digunakan untuk menunjukkan cara kerja dasar dari ADT (Abstract Data Type) Single Linked List, yang meliputi operasi penambahan, penghapusan, penelusuran, dan pembersihan data.

#### Full code Screenshot:
<img width="1912" height="1129" alt="image" src="https://github.com/user-attachments/assets/ec4bd6a1-3d4a-4d6a-83ea-f8e4887c3090" />



## Kesimpulan
Dalam pembelajaran ini, kita mempelajari berbagai fungsi seperti deleteFirst, deleteAfter, dan fungsi lainnya yang digunakan untuk menghapus node pada struktur data yang telah dibuat. Program ini juga menerapkan konsep ADT (Abstract Data Type) dalam proses pengelolaannya.

## Referensi
[1] CS115 Lab: Abstract Data Types (ADT's)
      Implemented as CLASSES in C++. https://www.labs.cs.uregina.ca/115/04-abstractD/
[2] Linked List C++. https://www.teachmesoft.com/2019/03/linked-list-c-disertai-contoh-tugas.html>
[3] Linked List: Pengertian dan Implementasi Dasar
Published by Fazry on May 25, 2024> https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/
