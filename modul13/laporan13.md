# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>
<p align="center">Thoriq Al Kayyiss</p>

## Dasar Teori
Multi List merupakan sekumpulan list yang berbeda yang memiliki suatu keterhubungan satu sama
lain. Tiap elemen dalam multi link list dapat membentuk listsendiri.Biasanya ada yang bersifat sebagai
list induk dan list anak .

#### A. Materi modul 13
Pada pertemuan ini, kita akan membahas fungsi fungsi pada struktur MLL (Multi Linked List)

#### 1. Insert Anak dan Induk
Insert induk adalah proses menambahkan elemen utama (node induk) ke dalam sebuah list.
Node ini menjadi acuan atau parent yang dapat memiliki elemen lain yang ditambahkan berdasarkan node tersebut.
Sedangkan Insert anak adalah proses menambahkan elemen baru (node anak) ke dalam list berdasarkan node induk tertentu, biasanya dengan cara menyisipkan node anak setelah node induk (insertAfter).

#### 2.  Delete Anak dan Induk
Delete induk adalah proses menghapus elemen utama (node induk) dari suatu struktur data list.
Penghapusan node induk menyebabkan node tersebut tidak lagi menjadi bagian dari list.
Sedangkan Delete anak adalah proses menghapus elemen turunan (node anak) dari list berdasarkan node induk tertentu, tanpa menghapus node induknya.



## Guided 

### . [Multi Linked List dengan beberapa fungsi] 

```C++
//MLL.H

//MLL.CPP

//main.cpp

   
```
Dengan menggunakan menu yang ada di main.cpp, program ini dapat membuat BST. Pada program ini, ada menu yang memungkinkan untuk memasukkan node ke dalam pohon, menghapus node untuk menghapus node yang ada di pohon, mencari pohon untuk mencari data atau node yang ada di pohon, dapat menampilkan pohon secara preorder, inorder, dan postorder, menghitung jumlah node, dan menampilkan pohon secara mostright dan mostleft. Selain itu, ada menu yang memungkinkan untuk menghapus seluruh pohon.


## Unguided

## soal 1. 
<img width="1035" height="827" alt="image" src="https://github.com/user-attachments/assets/ebbdf9d1-a1d0-495c-af1c-3c9fed174358" />
<img width="736" height="157" alt="image" src="https://github.com/user-attachments/assets/6e2c3767-bf9b-444c-8ed7-8ca122374c15" />

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

// alokasi node
address alokasi(infotype x);

// insert node ke BST
void insertNode(address &root, infotype x);

// mencari node
address findNode(infotype x, address root);

// traversal inorder
void InOrder(address root);

#endif


//bstree.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

// fungsi alokasi
address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

// fungsi insert BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika sama → tidak dimasukkan
}

// fungsi cari node
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x)
        return root;
    if (x < root->info)
        return findNode(x, root->left);
    return findNode(x, root->right);
}

// traversal InOrder
void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

//main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    return 0;
}

```
### Full code screenshot:
<img width="1916" height="1120" alt="image" src="https://github.com/user-attachments/assets/95497d4e-5867-445b-819b-0d4136395b4d" />
<img width="1917" height="1128" alt="image" src="https://github.com/user-attachments/assets/24e2d285-6105-4b71-b2b8-f4640136b051" />
<img width="1915" height="983" alt="image" src="https://github.com/user-attachments/assets/27569ff1-0ac2-4a40-9d45-007ab82d1e1a" />

### Output soal 1 :
<img width="1258" height="109" alt="image" src="https://github.com/user-attachments/assets/69126e65-f415-4968-9a56-05bb6f051ab7" />

Dengan menggunakan metode alokasi dan insert untuk menambah data atau node, program ini dapat membuat pohon secara BST dan meng-output kan inputan tersebut secara inOrder. Dengan kata lain, program akan mengunjungi subtree kiri, mencetak nilai dari node saat ini, dan kemudian mengunjungi subtree kanan.

### soal 2. 
<img width="889" height="196" alt="image" src="https://github.com/user-attachments/assets/86122002-be0b-4f46-8397-3f8119f0d379" />
<img width="908" height="647" alt="image" src="https://github.com/user-attachments/assets/42baeba7-7f3f-4c3c-8c0b-81a452a8e5d7" />

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif

//bstree.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungNode(address root) {
    if (root == Nil)
        return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil)
        return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,7);

    InOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}

```
### Full code screenshot:
<img width="1919" height="1115" alt="image" src="https://github.com/user-attachments/assets/e03aaad9-6d6c-4f04-af7c-271ec47061c8" />
<img width="1917" height="1125" alt="image" src="https://github.com/user-attachments/assets/72c6c6cc-73f7-45ec-b876-f69379144b9b" />
<img width="1919" height="1128" alt="image" src="https://github.com/user-attachments/assets/dba3d402-0e15-472c-a1f1-a1f13b42f3a6" />

### Output:
<img width="1257" height="164" alt="image" src="https://github.com/user-attachments/assets/eba34332-7f02-4465-acf7-a3950e0998aa" />

Dengan menggunakan alokasi dan insertNode untuk menambah data tanaman atau node, program ini dapat membuat BST (Binary Search Tree). Kemudian, program dapat menggunakan fungsi hitung JumlahNode untuk menghitung jumlah node, fungsi hitung TotalInfo untuk menghitung total node, dan fungsi untuk menghitung kedalaman tanaman. Perbedaan antara pengukuran kedalaman dan ketinggian terletak pada jarak: kedalaman mengukur jarak antara node dari root, sedangkan ketinggian mengukur jarak antara node dan lead (daun) terjauh di bawahnya.

### soal 3.
<img width="877" height="438" alt="image" src="https://github.com/user-attachments/assets/451700e8-cc21-46c1-bcc1-26878676f2f5" />

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
void preOrder(address root);
void postOrder(address root);

#endif

//bstree.cpp
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    cout << "Tampilkan preOrder : " ;
             preOrder(root); 
             cout << endl;
    cout << "Tampilkan postOrder : "; 
             postOrder(root);
             cout << endl;
    return 0;
}

```
### Full code screenshot:
<img width="1918" height="1111" alt="image" src="https://github.com/user-attachments/assets/e171c807-c512-4e5f-a7a9-f3446ac86b28" />
<img width="1918" height="1125" alt="image" src="https://github.com/user-attachments/assets/5cad3df6-0db3-477b-ab5e-c32c18fdcfbf" />
<img width="1919" height="1124" alt="image" src="https://github.com/user-attachments/assets/3afa001d-20c4-4e8d-8cd2-429d598e347a" />

### Output:
<img width="1264" height="148" alt="image" src="https://github.com/user-attachments/assets/5cacdbcb-24cb-4e64-a4d4-661b747c2218" />

Berfungsi untuk membuat pohon (BST), program ini kemudian dapat menampilkan output dari pohon tersebut secara preOrder (yaitu, mengunjungi dasar dan mencetak atau menampilkan node terlebih dahulu, kemudian mengunjungi subtree kiri, kemudian mengunjungi subtree kanan), dan secara postOrder (yaitu, mengunjungi subtree kiri terlebih dahulu, kemudian mengunjungi subtree kanan, dan node atau root diproses/dicetak dan ditampilkan di akhir).

### Kesimpulan
Pada materi tree ini, dibahas beberapa fungsi utama yang digunakan dalam struktur data tree, seperti proses penyisipan data menggunakan fungsi alokasi dan insertNode. Selain itu, juga dibahas perhitungan jumlah node melalui fungsi hitungJumlahNode, perhitungan total nilai informasi dengan fungsi hitungTotalInfo, serta perhitungan kedalaman tree menggunakan fungsi hitungKedalaman. Meskipun secara konsep kedalaman dan ketinggian tree terlihat serupa, keduanya memiliki perbedaan dalam implementasi. Oleh karena itu, perhitungan kedalaman dan ketinggian pada suatu tree merupakan dua fungsi yang berbeda dan tidak dapat disamakan.

## Referensi
[1] Binary Tree in C++. https://www.geeksforgeeks.org/cpp/binary-tree-in-cpp/
[2] Binary Search Tree (BST) Traversals – Inorder, Preorder, Post Order. https://www.geeksforgeeks.org/dsa/binary-search-tree-traversal-inorder-preorder-post-order/
[3] Memahami Konsep Tree dalam Struktur Data Lengkap dengan Source Code Programnya. https://daismabali.medium.com/memahami-konsep-tree-dalam-struktur-data-lengkap-dengan-source-code-programnya-acbd0a8733d6
