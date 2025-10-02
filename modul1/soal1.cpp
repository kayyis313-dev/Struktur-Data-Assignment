#include <iostream>
using namespace std;

int main() {
    float x, y;
    cout << "Masukkan dua bilangan float: ";
    cin >> x >> y;
    cout << "Penjumlahan: " << x + y << endl;
    cout << "Pengurangan: " << x - y << endl;
    cout << "Perkalian: " << x * y << endl;
    if (y != 0)
        cout << "Pembagian: " << x / y << endl;
        
    return 0;
}