#include <iostream>
#include <string>
using namespace std;

struct mhs {
    string nama, nim;
    float uts, uas, tugas;
};

float nilaiAkhir(mhs d) {
    return (0.3 * d.uts) + (0.4 * d.uas) + (0.3 * d.tugas);
}

void input(mhs &d) {
    cout << "\nNama mahasiswa : ";
    cin >> d.nama;
    cout << "NIM            : ";
    cin >> d.nim;
    cout << "Nilai UTS      : ";
    cin >> d.uts;
    cout << "Nilai UAS      : ";
    cin >> d.uas;
    cout << "Nilai Tugas    : ";
    cin >> d.tugas;
}

int main() {
    mhs data[10];
    int jml;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jml;

    if (jml > 10) {
        cout << "Kebanyakan, maksimal cuma 10!" << endl;
        return 0;
    }

    for (int i = 0; i < jml; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        input(data[i]);
    }

    cout << "\n--- Hasil Nilai Akhir ---" << endl;
    for (int i = 0; i < jml; i++) {
        cout << data[i].nama << " (" << data[i].nim << ")"
             << " -> Nilai Akhir: " << nilaiAkhir(data[i]) << endl;
    }

    return 0;
}