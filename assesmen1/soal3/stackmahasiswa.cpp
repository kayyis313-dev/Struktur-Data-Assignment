#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push.\n";
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = M;
}

void Pop(StackMahasiswa &S, Mahasiswa &M) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak bisa pop.\n";
        return;
    }
    M = S.dataMahasiswa[S.Top];
    S.Top--;
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    // posisi dari 1 (atas) kebawah
    int index = S.Top - posisi + 1;
    if (index < 0 || index > S.Top) {
        cout << "Posisi tidak valid.\n";
        return;
    }
    S.dataMahasiswa[index] = M;
}

float NilaiAkhir(Mahasiswa M) {
    return 0.2 * M.NilaiTugas + 0.4 * M.NilaiUTS + 0.4 * M.NilaiUAS;
}

void View(StackMahasiswa S) {
    cout << "\n=== Isi Stack Mahasiswa ===\n";
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    int posisi = 1;
    for (int i = S.Top; i >= 0; i--) {
        cout << posisi << ". "
             << S.dataMahasiswa[i].Nama << " | "
             << S.dataMahasiswa[i].NIM << " | "
             << "Tugas: " << S.dataMahasiswa[i].NilaiTugas << " | "
             << "UTS: " << S.dataMahasiswa[i].NilaiUTS << " | "
             << "UAS: " << S.dataMahasiswa[i].NilaiUAS
             << " | NA: " << NilaiAkhir(S.dataMahasiswa[i]) << endl;
        posisi++;
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float Min, float Max) {
    cout << "\n=== Searching Nilai Akhir (" << Min << " - " << Max << ") ===\n";

    bool found = false;
    int posisi = 1;

    for (int i = S.Top; i >= 0; i--) {
        float NA = NilaiAkhir(S.dataMahasiswa[i]);
        if (NA >= Min && NA <= Max) {
            cout << "Posisi " << posisi << " - "
                 << S.dataMahasiswa[i].Nama
                 << " | Nilai Akhir: " << NA << endl;
            found = true;
        }
        posisi++;
    }

    if (!found) {
        cout << "Tidak ada data dalam rentang tersebut.\n";
    }
}

void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    float maxNA = -999;
    for (int i = S.Top; i >= 0; i--) {
        float nilai = NilaiAkhir(S.dataMahasiswa[i]);
        if (nilai > maxNA) maxNA = nilai;
    }

    cout << "\n=== Nilai Akhir Terbesar: " << maxNA << " ===\n";

    int posisi = 1;
    for (int i = S.Top; i >= 0; i--) {
        if (NilaiAkhir(S.dataMahasiswa[i]) == maxNA) {
            cout << "Posisi " << posisi << " - "
                 << S.dataMahasiswa[i].Nama
                 << " (" << S.dataMahasiswa[i].NIM << ")\n";
        }
        posisi++;
    }
}