# <h1 align="center">Laporan Praktikum Modul3 Pengenalan Bahasa C++ (Abstract Data Type (ADT))</h1>
<p align="center">Thoriq Al Kayyis</p>

## Dasar Teori

Bahasa pemrograman C merupakan bahasa yang bersifat terstruktur, di mana program dibagi menjadi beberapa blok atau bagian agar proses pembuatan dan pengembangannya menjadi lebih mudah.
Sementara itu, program C++ biasanya disimpan dengan ekstensi .CPP(singkatan dari *C plus plus*).
Sebelum program tersebut dapat dijalankan (dieksekusi), ia harus terlebih dahulu dikompilasi menggunakan kompiler C++.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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

### 2. soal

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
