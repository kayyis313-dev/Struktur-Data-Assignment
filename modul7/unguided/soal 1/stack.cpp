// stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

void initStack(Stack &S) {
    S.atas = -1;
}

void push(Stack &S, Data x) {
    if (S.atas == MAKS - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.atas++;
        S.item[S.atas] = x;
    }
}

Data pop(Stack &S) {
    if (S.atas == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        Data temp = S.item[S.atas];
        S.atas--;
        return temp;
    }
}

void tampil(Stack S) {
    cout << "(TOP) ";
    for (int i = S.atas; i >= 0; i--) {
        cout << S.item[i] << " ";
    }
    cout << endl;
}

void balik(Stack &S) {
    Stack bantuan;
    initStack(bantuan);

    while (S.atas != -1) {
        push(bantuan, pop(S));
    }

    S = bantuan;
}
