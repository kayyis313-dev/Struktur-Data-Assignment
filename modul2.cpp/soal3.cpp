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