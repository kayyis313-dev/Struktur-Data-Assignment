# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Thoriq al kayyis</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [input & output]

```C++
#include <iostream>
using namespace std;

int main () {
    int n;
    const float pi = 3.14;

    cout << "Masukan Angka: ";
    cin >> n ;

    cout << "Angka dikeluarkan: " << n << endl;
    cout << "Nilai konstanta pi: " << pi << endl;
    return 0;
}

```
Kode di atas digunakan untuk menerima inputan angka dari pengguna, lalu menampilkan angka tersebut dan juga menampilkan nilai konstanta tersebut.

## Unguided 

### 1.  Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.


```C++
#include <iostream>
using namespace std;

int main() {
    float x, y;
    cout << "Masukkan dua bilangan float: ";
    cin >> x >> y;
    cout << "Penjumlahan: " << x + y << endl;
    cout << "Pengurangan: " << x - y << endl;
    cout << "Perkalian: " << x * y << endl;
    cout << "Pembagian: " << x / y << endl;
        
    return 0;
}
```
#### Output:
<img width="1265" height="206" alt="image" src="https://github.com/user-attachments/assets/6b1048d2-bcc5-411c-91c6-d9dbfcec5b1c" />


Kode di atas digunakan untuk melakukan operasi aritmatika dasar(penjumlahan, pengurangan, perkalian, dan pembagian) terhadap dua bilangan bertipe float yang dimasukkan oleh pengguna.
#### Full code Screenshot:
<img width="1919" height="1097" alt="image" src="https://github.com/user-attachments/assets/892fe3ff-c177-4eab-88bb-05fc76b76482" />


## Unguided 

### 2. [Soal]
```C++
#include <iostream>
using namespace std;

int main(){
    string satuan[9] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",};
    string belasan[9] = {"sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[9] = {"sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    int angka;
    cout << "Input Angka: ";
    cin >> angka;

    if (angka < 10) {
        cout << satuan[angka - 1] << endl;
    } else if (angka < 20) {
        cout << belasan[angka - 11] << endl;
    } else if (angka %10 == 0) {
        cout << puluhan[angka / 10 - 1] << endl;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka > 20 && angka < 100) {
        cout << puluhan[ (angka/10)-1 ] << " " << satuan[ (angka%10)-1 ] << endl;
    }

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)


#### Full code Screenshot:
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 3. [Soal]
```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  "; // dua spasi biar rapi
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}


#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

#### Full code Screenshot:
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002. 
