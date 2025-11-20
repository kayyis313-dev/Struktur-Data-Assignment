#include <iostream>
#include "SLLinventory.h"

int main() {
    List L;
    createList(L);

    // 2. Gunakan insertLast: tiga produk awal
    Product p1 = {"Pulpen", "A001", 20, 2500.0f, 0.0f};
    Product p2 = {"Buku Tulis", "A002", 15, 5000.0f, 10.0f};
    Product p3 = {"Penghapus", "A003", 30, 1500.0f, 0.0f};

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    // 3. Tampilkan list
    std::cout << "=== Setelah insertLast 3 produk ===\n";
    viewList(L);
    std::cout << std::endl;

    // 4. deleteFirst 1x
    Product temp;
    deleteFirst(L, temp);
    std::cout << "=== Setelah deleteFirst 1x (produk yang dihapus) ===\n";
    std::cout << "Nama: " << temp.Nama << " | SKU: " << temp.SKU << "\n\n";

    // 5. Tampilkan list kembali
    std::cout << "=== Tampilkan list setelah deleteFirst ===\n";
    viewList(L);
    std::cout << std::endl;

    // 6. Update data pada posisi ke-2 dengan data baru
    Product newData = {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    updateAtPosition(L, 2, newData);

    // 7. Tampilkan list setelah update
    std::cout << "=== Setelah update posisi ke-2 ===\n";
    viewList(L);
    std::cout << std::endl;

    // 8. Searching berdasarkan HargaAkhir min=2000 max=7000
    std::cout << "=== Searching HargaAkhir in [2000, 7000] ===\n";
    searchByFinalPriceRange(L, 2000.0f, 7000.0f);
    std::cout << std::endl;

    // Bagian B: MaxHargaAkhir
    std::cout << "=== MaxHargaAkhir ===\n";
    MaxHargaAkhir(L);
    std::cout << std::endl;

    return 0;
}
