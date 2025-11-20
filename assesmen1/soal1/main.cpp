#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {
    List L;
    createList(L);

    // 2. gunakan insertLast untuk 3 produk
    Product p1 {"Pulpen", "A001", 20, 2500.0f, 0.0f};
    Product p2 {"Buku Tulis", "A002", 15, 5000.0f, 10.0f};
    Product p3 {"Penghapus", "A003", 30, 1500.0f, 0.0f};

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    // 3. tampilkan list
    cout << "-- List awal --" << endl;
    viewList(L);
    cout << endl;

    // 4. deleteFirst 1x
    Product temp;
    deleteFirst(L, temp);
    cout << "Setelah deleteFirst() -> produk yang dihapus: " << temp.Nama << " (" << temp.SKU << ")" << endl;

    // 5. tampilkan list kembali
    cout << "-- List setelah deleteFirst --" << endl;
    viewList(L);
    cout << endl;

    // 6. Update data pada posisi ke-2 -> gunakan data baru
    Product newP {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    bool ok = updateAtPosition(L, 2, newP);
    if (!ok) cout << "Update gagal: posisi tidak ada." << endl;

    // 7. tampilkan list setelah update
    cout << "-- List setelah update posisi 2 --" << endl;
    viewList(L);
    cout << endl;

    // 8. searching berdasarkan HargaAkhir dalam rentang [2000, 7000]
    cout << "-- Searching HargaAkhir [2000,7000] --" << endl;
    searchByFinalPriceRange(L, 2000.0f, 7000.0f);
    cout << endl;

    // Bagian B: panggil MaxHargaAkhir
    MaxHargaAkhir(L);

    return 0;
}