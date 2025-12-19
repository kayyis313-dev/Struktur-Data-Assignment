# <h1 align="center">Laporan Praktikum Modul 10 - tree(bagian pertama)</h1>
<p align="center">Thoriq Al Kayyis</p>

## Dasar Teori
Kita telah mengenal dan mempelajari jenis-jenis strukur data yang linear, seperti : list, stack dan
queue. Adapun jenis struktur data yang kita pelajari kali ini adalah struktur data yang non-liniar (nonlinear data structure) yang disebut tree.
Tree digambarkan sebagai suatu graph tak berarah terhubung dan tidak terhubung dan tidak
mengandung sirkuit.
Karateristik dari suatu tree T adalah :
1. T kosong berarti empty tree
2. Hanya terdapat satu node tanpa pendahulu, disebut akar (root)
3. Semua node lainnya hanya mempunyai satu node pendahulu

#### A. Materi modul 10
Pada pertemuan ini, kita akan membahas fungsi fungsi pada struktur tree pada BST (Binary Search Tree).

#### 1. Insert
Jika node yang akan di-insert lebih kecil, maka di-insert pada Left Subtree
Jika lebih besar, maka di-insert pada Right Subtree.

#### 2. Search
Proses pencarian elemen pada binary tree dapat menggunakan algoritma rekursif binary search.
Berikut adalah algoritma binary search :
1. Pencarian pada binary search tree dilakukan dengan menaruh pointer dan membandingkan nilai
yang dicari dengan node awal ( root )
2. Jika nilai yang dicari tidak sama dengan node, maka pointer akan diganti ke child dari node yang
ditunjuk:
a. Pointer akan pindah ke child kiri bila, nilai dicari lebih kecil dari nilai node yang ditunjuk saat
itu
b. Pointer akan pindah ke child kanan bila, nilai dicari lebih besar dari nilai node yang ditunjuk
saat itu
3. Nilai node saat itu akan dibandingkan lagi dengan nilai yang dicari dan apabila belum ditemukan,
maka perulangan akan kembali ke tahap 2
4. Pencarian akan berhenti saat nilai yang dicari ketemu, atau pointer menunjukan nilai NULL

#### 3. Delete
LEAF, tidak perlu dilakukan modifikasi.
2. Node dengan 1 Child, maka child langsung menggantikan posisi Parent.
3. Node dengan 2 Child:
- Left Subtree, yang diambil adalah node yang paling kiri (nilai terbesar).
- Right Subtree, yang diambil adalah node yang paling kanan (nilai terkecil).

#### 4. Most Left
Most-left node adalah node yang berada paling kiri dalam tree. Dalam konteks binary search tree
(BST), most-left node adalah node dengan nilai terkecil, yang dapat ditemukan dengan mengikuti
anak kiri (left child) dari root hingga mencapai node yang tidak memiliki anak kiri lagi.

#### 5. Most right
Most-right node adalah node yang berada paling kanan dalam tree. Dalam konteks binary search
tree (BST), most-right node adalah node dengan nilai terbesar, yang dapat ditemukan dengan
mengikuti anak kanan (right child) dari root hingga mencapai node yang tidak memiliki anak kanan
lagi.

#### 6. Pre-Order
Proses Traverse yang melakukan tahapan cetak node yang dikunjungi, kunjungi left node , kunjungi right node.

#### 7. In-Order
Proses Traverse yang melakukan tahapan kunjungi left node, cetak node yang dikunjungi, kunjungi right node.

#### 8. Post-Order
Proses Traverse yang melakukan tahapan kunjungi left node, kunjungi right node, cetak node yang dikunjungi


## Guided 1

### . [Binary Searh Tree] 

```C++
//bst.h
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ //nama struct BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif

//bst.cpp
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
//main.cpp
#include <iostream>
#include "bst.h"
#include "bst.cpp"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
   
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
