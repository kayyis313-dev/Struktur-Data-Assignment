#ifndef PELAJARANN_H
#define PELAJARANN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi dan prosedur
pelajaran create_Pelajarann(string namapel, string kodepel);
void tampil_Pelajarann(pelajaran pel);

#endif

#include <iostream>
#include "pelajarann.h"
using namespace std;

pelajaran create_Pelajarann(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_Pelajarann(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}


#include <iostream>
#include <string>
#include "pelajarann.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_Pelajarann(namapel, kodepel);
    tampil_Pelajarann(pel);

    return 0;
}
