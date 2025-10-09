# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Thoriq Al Kayyis</p>

## Dasar Teori
## 1. Array
Array adalah struktur data yang berisi kumpulan elemen dengan tipe data yang sama, di mana setiap elemen disimpan pada alamat memori tertentu. Selain array satu dimensi, terdapat juga array dua dimensi yang berbentuk seperti matriks dengan susunan baris dan kolom, sehingga dapat digunakan untuk merepresentasikan data yang lebih kompleks.

## 2. Function
Fungsi merupakan sekumpulan perintah atau kode yang memiliki nama, dapat menerima masukan dari pemanggilnya, menjalankan proses tertentu, dan dapat mengembalikan nilai hasil dari proses tersebut.

## 3. Procedure
Prosedur adalah sekumpulan langkah atau instruksi algoritmik yang memiliki nama dan digunakan untuk menjalankan tugas tertentu yang menghasilkan efek atau perubahan yang telah ditentukan.

## 4. Pointer
Pointer dalam bahasa C++ adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, kita bisa mengakses dan memodifikasi data secara langsung di lokasi memori yang ditunjuk.

## 5. Reference
Reference adalah variabel yang berfungsi sebagai nama lain atau alias dari variabel yang sudah ada, sehingga memungkinkan kita untuk mengakses dan memanipulasi data aslinya secara langsung tanpa membuat salinan baru.

## Guided 

### 1. [Pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

main () {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value a : " << a << endl;
    cout << "Address a : " << &a << endl;
    cout << "Value stored in otr (address of a) : " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;


tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}
```
Kode di atas digunakan untuk Menukarkan nilai dari dua variabel menggunakan fungsi yang menerima parameter berupa pointer.

## Unguided 

### 1. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3]

```C++
#include <iostream>
using namespace std;

void tampilkanMatriks(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {5, 3, 1},
        {7, 0, 1},
        {2, 1, 5}
    };
    int arrB[3][3] = {
        {1, 3, 2},
        {4, 1, 3},
        {5, 0, 2}
    };
    int arrC[3][3] = {0}; 
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanMatriks(arrC);

    cout << endl;

 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan : " << endl;
    tampilkanMatriks(arrD);

    cout << endl;


    for (int i = 0; i < 3; i++) {            
        for (int j = 0; j < 3; j++) {       
            for (int k = 0; k < 3; k++) {  
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanMatriks(arrE);

    return 0;
}
```
#### Output:
<img width="1248" height="447" alt="image" src="https://github.com/user-attachments/assets/fcca3cd4-bba5-4c8a-8ad1-fdc03935080f" />


Kode di atas digunakan untuk menerapkan operasi dasar pada matriks berukuran 3x3, yaitu penjumlahan, pengurangan, dan perkalian, kemudian menampilkan hasil perhitungannya ke layar melalui sebuah fungsi

#### Full code Screenshot:
<img width="1919" height="1130" alt="image" src="https://github.com/user-attachments/assets/eedf233f-c257-4051-9506-d99043f00223" />


## Unguided 

### 2. [Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel]

```C++
#include <iostream>
using namespace std;

void tukarNilai(int *p, int *q, int *r) {
    int temp = *r;
    *r = *q;
    *q = *p;
    *p = temp;
}

int main() {
    int a = 7, b = 14, c = 21;

    cout << "Nilai awal:\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarNilai(&a, &b, &c);

    cout << "\nSetelah ditukar nilainya :\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}

```
#### Output:


#### Full code Screenshot:


## Unguided 

### 3. [Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
<img width="425" height="155" alt="image" src="https://github.com/user-attachments/assets/228e0882-5564-424b-9caf-48b8dae7b9ea" />


```C++
#include <iostream>
using namespace std;

int cariMaks(int arr[], int n){
    int maks = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

int cariMin(int arr[], int n){
    int min = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

void hitungRataRata(int arr[], int n){
    float total = 0;
    for(int i=0; i<n; i++){
        total += arr[i];
    }
    cout << "Rata-rata = " << total/n << endl;
}

int main(){
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilih;

    do{
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch(pilih){
            case 1:
                cout << "Isi array: ";
                for(int i=0; i<n; i++){
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaks(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMin(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            default:
                cout << "Pilihan tidak ada!\n";
        }
    } while (pilih != 5);

    return 0;
}
```

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
