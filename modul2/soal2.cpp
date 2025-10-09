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

    cout << "\nSetelah ditukar nilainya (pointer) :\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
