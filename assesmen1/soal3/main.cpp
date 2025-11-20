#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    // Data mahasiswa sesuai soal
    Mahasiswa m1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa m2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa m3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa m4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa m5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa m6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    // Push semua data
    Push(S, m1);
    Push(S, m2);
    Push(S, m3);
    Push(S, m4);
    Push(S, m5);
    Push(S, m6);

    cout << "=== STACK SETELAH INPUT ===\n";
    View(S);

    // Pop 1x
    Mahasiswa removed;
    Pop(S, removed);
    cout << "\n=== SETELAH POP 1X ===\n";
    View(S);

    // Update posisi ke-3
    Mahasiswa updateData = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, updateData);

    cout << "\n=== SETELAH UPDATE POSISI 3 ===\n";
    View(S);

    // Searching sesuai soal
    cout << "\n=== SEARCH NILAI AKHIR 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    // Max nilai akhir
    cout << "\n=== NILAI AKHIR TERBESAR ===\n";
    MaxNilaiAkhir(S);

    return 0;
}
