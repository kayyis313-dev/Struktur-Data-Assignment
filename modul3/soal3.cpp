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
