# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Thoriq Al Kayyis</p>

## Dasar Teori
Queue (dibaca : kyu) merupakan struktur data yang dapat diumpamakan seperti sebuah antrean.
Misalkan antrean pada loket pembelian tiket Kereta Api. Orang yang akan mendapatkan pelayanan
yang pertama adalah orang pertamakali masuk dalam antrean tersebut dan yang terakhir masuk dia
akan mendapatkan layanan yang terakhir pula. Jadi prinsip dasar dalam Queue adalah FIFO (First in
Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian
struktur Queue dalam C dapat menggunakan tipe data array dan linked list.

#### A. Materi queue
Dalam praktikum ini hanya akan dibahas pengimplementasian Queue dalam bentuk linked list.
Implementasi Queue dalam linked list sebenarnya tidak jauh berbeda dengan operasi list biasa,
malahan lebih sederhana. Karena sesuai dengan sifat FIFO dimana proses delete hanya dilakukan pada
bagian Head (depan list) dan proses insert selalu dilakukan pada bagian Tail (belakang list) atau
sebaliknya, tergantung dari persepsi masing-masing. Dalam penerapannya Queue dapat diterapkan
dalam Singly linked list dan Doubly linked list. 

#### 1. Enqueue
EnQueue merupakan proses memasukkan data ke akhir antrian dalam bentuk array, sehingga simbol atau elemen yang ditambahkan akan berada di urutan paling belakang.

#### 2. Dequeue
ueue merupakan proses penghapusan elemen yang dilakukan dari bagian terdepan antrian.

## Guided 
### . [guided 1]
### . Penggunaan Queue 

```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif

//queue.cpp
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

//main.cpp
#include "queue.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
   
```
Program ini berfungsi untuk membuat dan mengatur antrian menggunakan linked list dengan aturan FIFO (data yang masuk lebih dulu akan keluar lebih dulu). Program ini dapat menambah, menghapus data paling depan, mengosongkan antrian, dan menampilkan isinya menggunakan fungsi viewQueue.


### . [guided 2]
### . Penggunaan Queue dengan beberapa implementasi

```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama); 
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

//queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void createQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }

//main.cpp
#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini berfungsi untuk mengelola antrian menggunakan array dengan aturan FIFO. Walaupun mirip dengan program sebelumnya, program ini terdiri dari tiga implementasi berbeda, yaitu head tetap dan tail bergerak, head dan tail berpindah, serta head dan tail yang berputar.

## Unguided

## soal 1. {alternatif 1}
<img width="1026" height="886" alt="image" src="https://github.com/user-attachments/assets/715fe1bb-4c2a-4d10-8731-abb4820c4491" />

```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

//queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}
 


int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < Q.head){ 
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

//main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output soal 1 :
<img width="1131" height="548" alt="Screenshot 2025-12-07 201334" src="https://github.com/user-attachments/assets/e538745f-4927-4bbe-9b20-28f6031b91a4" />

Program ini berfungsi membuat antrian dari array berukuran tetap maksimal 5 elemen, dengan metode di mana head tidak berubah dan tail terus bergerak.

### soal 2. {alternatif 2}
<img width="979" height="75" alt="image" src="https://github.com/user-attachments/assets/b6ae3434-880c-481a-86ff-cecddc772123" />

```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

//queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}


void dequeue(queue &Q){
     if(isEmpty(Q) == true){
         cout << "Queue kosong!" << endl;
     } else {
         Q.head++;
         if(Q.head > Q.tail){
             Q.head = -1;
             Q.tail = -1;
         }
     }
 }

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

//main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output:
<img width="1126" height="474" alt="image" src="https://github.com/user-attachments/assets/1a7ac747-3991-48a1-94eb-05ccf2b4cb05" />

Program ini berfungsi membuat antrian menggunakan array berukuran maksimum 5 elemen, dengan cara head dan tail berpindah saat ada proses enqueue dan dequeue.

### soal 3. {alternatif3}
<img width="992" height="125" alt="image" src="https://github.com/user-attachments/assets/ca182d50-25e1-4a23-ad2e-f10ba0f2f85c" />

```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

//queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q)
{
    if (Q.head == -1 && Q.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(queue Q)
{
    if ((Q.tail + 1) % MAX == Q.head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createQueue(queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X)
{
    if (isFull(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmpty(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q)
{
    if (isEmpty(Q) == true)
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(queue Q)
{
    if (isEmpty(Q) == true)
    {
    cout << Q.head << " - " << Q.tail << " | Empty Queue" << endl;
    return;
    }
    else
    {
        cout << Q.head << " - " << Q.tail << " | ";
        int i = Q.head;
        int count = 1;
        while (true)
        {
            cout << Q.info[i] << " ";

            if (i == Q.tail)
                break;

            cout << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

//main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output:
<img width="1121" height="480" alt="image" src="https://github.com/user-attachments/assets/12a2b596-1475-4384-bc86-b6269a1d2abc" />

Program ini digunakan untuk membentuk struktur antrian (queue) menggunakan array berukuran tetap dengan kapasitas maksimum 5 elemen, serta menerapkan implementasi ketiga, yaitu head dan tail yang bergerak secara berputar (circular).


### Full code Screenshot:
<img width="1919" height="1124" alt="image" src="https://github.com/user-attachments/assets/1ad9c5c7-22aa-4915-accc-c55f7847863c" />


### Kesimpulan
Pada pembelajaran ini, kita mempelajari struktur data queue, yaitu antrian yang menggunakan prinsip FIFO (First In First Out), di mana data yang pertama masuk akan keluar terlebih dahulu. Hal ini berbeda dengan stack yang menggunakan prinsip LIFO (Last In First Out). Selain itu, dalam implementasinya, queue dapat dibuat dengan beberapa metode, yaitu terdapat tiga jenis implementasi yang berbeda.


## Referensi
[1] Queue in C++ STL. https://www.geeksforgeeks.org/cpp/queue-cpp-stl/
[2] https://www.geeksforgeeks.org/cpp/how-to-enqueue-an-element-into-a-queue-in-cpp/
[3] Deque in C++ STL. https://www.geeksforgeeks.org/cpp/deque-cpp-stl/
