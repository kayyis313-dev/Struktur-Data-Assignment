#include <iostream>

using namespace std;

int main() {
    
    string tokoroti = "bluebberry";
    string aa=tokoroti;
    cout <<"\n";
    cout << tokoroti << "\n";
    cout << &tokoroti << "\n";
    cout << aa << "\n";
    //cout << *tokoroti << "\n"; NO
    
    cout <<"\n";
    string *ptr = &tokoroti;
    cout << ptr << "\n";
    cout << *ptr << "\n";
    cout << &ptr << "\n";
    
}