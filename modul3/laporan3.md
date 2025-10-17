# <h1 align="center">Laporan Praktikum Modul3 Pengenalan Bahasa C++ (Abstract Data Type (ADT))</h1>
<p align="center">Thoriq Al Kayyis</p>

## Dasar Teori

Bahasa pemrograman C merupakan bahasa yang bersifat terstruktur, di mana program dibagi menjadi beberapa blok atau bagian agar proses pembuatan dan pengembangannya menjadi lebih mudah.
Sementara itu, program C++ biasanya disimpan dengan ekstensi .CPP(singkatan dari *C plus plus*).
Sebelum program tersebut dapat dijalankan (dieksekusi), ia harus terlebih dahulu dikompilasi menggunakan kompiler C++.

### ADT
ADT adalah konsep yang memisahkan antara bagian yang tampak oleh pengguna (interface) dan bagian yang tidak tampak (implementasi).
Bagian interface berisi daftar nama serta fungsi-fungsi yang dapat digunakan oleh pemrogram, sedangkan implementasi menjelaskan bagaimana fungsi-fungsi tersebut bekerja di dalam program.

### Struct
struct merupakan tipe data buatan pengguna (user-defined type) yang berfungsi untuk mengelompokkan sejumlah data yang saling berhubungan ke dalam satu kesatuan.

Melalui penggunaan struct, kita dapat menyimpan beberapa variabel dengan tipe data berbeda di bawah satu nama struktur yang sama

## Guided 

### 1. [ADT struct]

### a. ADT (mahasiswa.h)

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;

};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif

```
Bagian ini mendefinisikan struct mahasiswa yang digunakan untuk menyimpan informasi berupa NIM dan dua nilai. Selain itu, terdapat juga deklarasi fungsi inputMhs() yang berfungsi untuk memasukkan data mahasiswa, serta fungsi rata2() yang digunakan untuk menghitung nilai rata-rata mahasiswa tersebut.

### b. ADT (mahasiswa.cpp)
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m){
cout << "input nama : ";
cin >> (m).nim;
cout << "input nilai : ";
cin >> (m).nilai1;
cout << "input nilai2 : ";
cin >> (m).nilai2;

}
float rata2(mahasiswa m){
 return float(m.nilai1+m.nilai2) / 2;
}

```
Bagian ini memuat definisi fungsi yang berasal dari file header.
Fungsi inputMhs() berperan untuk mengambil atau menerima data mahasiswa dari pengguna, sedangkan fungsi rata2() berfungsi untuk melakukan perhitungan dan mengembalikan hasil berupa nilai rata-rata dari dua nilai yang telah diinputkan.

### c. ADT (main.cpp)
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata: " << rata2(mhs);
    return 0;
}
```
Bagian utama program yang menjalankan proses utama. Program akan memanggil inputMhs() untuk mengisi data mahasiswa, kemudian memanggil rata2() untuk menghitung rata-rata dan menampilkan hasilnya ke layar.

Kode di atas digunakan untuk mencetak nilai rata-rata dari dua nilai yang dimasukkan oleh pengguna

## Unguided 

### 1. . Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct mhs {
    string nama, nim;
    float uts, uas, tugas;
};

float nilaiAkhir(mhs d) {
    return (0.3 * d.uts) + (0.4 * d.uas) + (0.3 * d.tugas);
}

void input(mhs &d) {
    cout << "\nNama mahasiswa : ";
    cin >> d.nama;
    cout << "NIM            : ";
    cin >> d.nim;
    cout << "Nilai UTS      : ";
    cin >> d.uts;
    cout << "Nilai UAS      : ";
    cin >> d.uas;
    cout << "Nilai Tugas    : ";
    cin >> d.tugas;
}

int main() {
    mhs data[10];
    int jml;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jml;

    if (jml > 10) {
        cout << "Kebanyakan, maksimal cuma 10!" << endl;
        return 0;
    }

    for (int i = 0; i < jml; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        input(data[i]);
    }

    cout << "\n--- Hasil Nilai Akhir ---" << endl;
    for (int i = 0; i < jml; i++) {
        cout << data[i].nama << " (" << data[i].nim << ")"
             << " -> Nilai Akhir: " << nilaiAkhir(data[i]) << endl;
    }

    return 0;
}
```
#### Output:
<img width="1235" height="609" alt="image" src="https://github.com/user-attachments/assets/75c7596c-4e88-42d5-bfa0-7373d7bd8bae" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1919" height="1135" alt="image" src="https://github.com/user-attachments/assets/8b179f71-e5ac-4bd3-984a-01f8a415b379" />
<img width="1255" height="192" alt="image" src="https://github.com/user-attachments/assets/133186c9-f8a6-4dba-8b46-d0ea08d6a3b8" />


## Unguided 

### 2. <img width="508" height="332" alt="image" src="https://github.com/user-attachments/assets/b4afd600-52cf-4f16-b24c-e6f5ec3bcbd0" />


```C++
// pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

//pelajaran.cpp
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//main.cpp
#include <iostream>
#include <string>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
#### Output:
<img width="1251" height="347" alt="Screenshot 2025-10-16 224127" src="https://github.com/user-attachments/assets/a5840285-4d93-4993-ae6b-454a3d590e4f" />


Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Unguided 

### 3.  Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void printArray(int arr[3][3]){
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
}

void tukarIsi(int m1[3][3], int m2[3][3], int r, int c){
    int simpan = m1[r][c];
    m1[r][c] = m2[r][c];
    m2[r][c] = simpan;
}

void gantiPointer(int *x, int *y){
    int simpan = *x;
    *x = *y;
    *y = simpan;
}

int main(){
    int arr1[3][3] = {
        {5, 7, 1},
        {9, 3, 6},
        {4, 8, 2}
    };
    int arr2[3][3] = {
        {11, 4, 9},
        {6, 10, 5},
        {7, 2, 13}
    };

    cout << "Array 1 awal:\n";
    printArray(arr1);
    cout << "Array 2 awal:\n";
    printArray(arr2);

    // misal mau tukar elemen baris 0 kolom 2
    tukarIsi(arr1, arr2, 0, 2);

    cout << "\nSetelah ditukar elemen (baris 0, kolom 2)\n";
    cout << "Array 1:\n";
    printArray(arr1);
    cout << "Array 2:\n";
    printArray(arr2);

    int a = 12, b = 25;
    cout << "\nNilai sebelum ditukar -> a = " << a << ", b = " << b << endl;
    gantiPointer(&a, &b);
    cout << "Nilai sesudah ditukar -> a = " << a << ", b = " << b << endl;

    return 0;
}
```
#### Output:
<img width="1254" height="630" alt="image" src="https://github.com/user-attachments/assets/2ea82509-0250-426a-9b97-072e94efe167" />


Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1916" height="1124" alt="image" src="https://github.com/user-attachments/assets/b57c79f7-ab6b-4b9e-a023-8613ab9c4457" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
