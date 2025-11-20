// main.cpp
#include <iostream>
#include "DLLPlaylist.h"

int main() {
    List L;
    createList(L);

    // 1. Masukkan 3 lagu menggunakan insertLast
    Song s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2f};
    Song s2 = {"Langkahmu", "Delta", 185, 320, 4.8f};
    Song s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9f};

    insertLast(L, s1);
    insertLast(L, s2);
    insertLast(L, s3);

    // 3. Tampilkan list
    std::cout << ">>> Setelah insertLast 3 lagu:\n";
    viewList(L);

    // 4. Lakukan deleteLast sebanyak 1x
    Song removed;
    deleteLast(L, removed);
    std::cout << "\n>>> Setelah deleteLast 1x (menghapus: " << removed.Title << ")\n";
    viewList(L);

    // 5. Update node pada posisi ke-2 menggunakan updateAtPosition()
    Song newPos2 = {"Pelita", "Luna", 200, 260, 4.5f};
    updateAtPosition(L, 2, newPos2); // pos 2
    std::cout << "\n>>> Setelah updateAtPosition posisi 2 diganti menjadi 'Pelita':\n";
    viewList(L);

    // 7. Operasi BEFORE
    // Gunakan node pada posisi ke-2 untuk operasi before:
    Node* nodePos2 = getNodeAt(L, 2);
    if (nodePos2 == nullptr) {
        std::cerr << "Node posisi 2 tidak ditemukan. Operasi BEFORE dilewati.\n";
    } else {
        // a. insertBefore pada node posisi 2
        Song sb = {"Senandung", "Mira", 175, 120, 4.0f};
        insertBefore(L, nodePos2, sb);
        std::cout << "\n>>> Setelah insertBefore pada posisi 2 (menambahkan 'Senandung'):\n";
        viewList(L);

        // b. updateBefore pada node posisi 2 (masukkan data baru bebas)
        Song ub = {"Nada Baru", "Cinta", 190, 80, 3.7f}; // data bebas
        // get node at pos 2 again because list changed: we want 'node posisi 2' original reference
        nodePos2 = getNodeAt(L, 2);
        updateBefore(L, nodePos2, ub);
        std::cout << "\n>>> Setelah updateBefore pada node posisi 2 (mengubah node sebelum pos2):\n";
        viewList(L);

        Node* nodePos3 = getNodeAt(L, 3);
        if (nodePos3 != nullptr) {
            Song delb;
            deleteBefore(L, nodePos3, delb);
            std::cout << "\n>>> Setelah deleteBefore pada posisi 3 (menghapus node sebelum pos3: " << delb.Title << ")\n";
            viewList(L);
        } else {
            std::cout << "Node posisi 3 tidak ada; deleteBefore dilewati.\n";
        }
    }

    float minScore = 150.0f;
    float maxScore = 300.0f;
    searchByPopularityRange(L, minScore, maxScore);

    return 0;
}
