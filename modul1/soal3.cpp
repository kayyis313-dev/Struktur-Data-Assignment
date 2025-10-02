#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:\n";
    for (int i = n; i >= 1; i--) {
        // Print angka dari i ke 1
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*";
        // Print angka dari 1 ke i
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    cout << "*" << endl;
    return 0;
}
