#include <iostream>
using namespace std;

int main() {
    string satuan[9] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[9] = {"sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", 
                         "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[9] = {"sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", 
                         "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else if (angka == 0) {
        cout << "nol" << endl;
    } else if (angka < 10) {
        cout << satuan[angka - 1] << endl;
    } else if (angka == 10) {
        cout << "sepuluh" << endl;
    } else if (angka < 20) {
        cout << belasan[angka - 11] << endl;
    } else if (angka % 10 == 0 && angka < 100) {
        cout << puluhan[(angka / 10) - 1] << endl;
    } else if (angka > 20 && angka < 100) {
        cout << puluhan[(angka / 10) - 1] << " " << satuan[(angka % 10) - 1] << endl;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    }

    return 0;
}
