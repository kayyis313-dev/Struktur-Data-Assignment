# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Nama Topik]

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
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

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
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

## Unguided 

### 2. [Soal]

```C++


```

## Unguided 

### 3. [Soal]

```C++

```

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
