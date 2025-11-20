// DLLPlaylist.cpp
#include <iostream>
#include <iomanip>
#include "DLLPlaylist.h"

bool isEmpty(const List& L) {
    return (L.head == nullptr && L.tail == nullptr);
}

void createList(List& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

Node* allocate(const Song& S) {
    Node* p = new(std::nothrow) Node;
    if (p != nullptr) {
        p->info = S;
        p->prev = nullptr;
        p->next = nullptr;
    }
    return p;
}

void deallocate(Node* P) {
    delete P;
}

void insertFirst(List& L, const Song& S) {
    Node* p = allocate(S);
    if (p == nullptr) return; // allocation failed
    if (isEmpty(L)) {
        L.head = L.tail = p;
    } else {
        p->next = L.head;
        L.head->prev = p;
        L.head = p;
    }
}

void insertLast(List& L, const Song& S) {
    Node* p = allocate(S);
    if (p == nullptr) return;
    if (isEmpty(L)) {
        L.head = L.tail = p;
    } else {
        p->prev = L.tail;
        L.tail->next = p;
        L.tail = p;
    }
}

void insertAfter(List& L, Node* Q, const Song& S) {
    if (Q == nullptr) return;
    if (Q == L.tail) {
        insertLast(L, S);
        return;
    }
    Node* p = allocate(S);
    if (p == nullptr) return;
    p->next = Q->next;
    p->prev = Q;
    Q->next->prev = p;
    Q->next = p;
}

void insertBefore(List& L, Node* Q, const Song& S) {
    if (Q == nullptr) return;
    if (Q == L.head) {
        insertFirst(L, S);
        return;
    }
    Node* p = allocate(S);
    if (p == nullptr) return;
    p->prev = Q->prev;
    p->next = Q;
    Q->prev->next = p;
    Q->prev = p;
}

void deleteFirst(List& L, Song& S) {
    if (isEmpty(L)) return;
    Node* p = L.head;
    S = p->info;
    if (L.head == L.tail) { // single node
        L.head = L.tail = nullptr;
    } else {
        L.head = p->next;
        L.head->prev = nullptr;
    }
    deallocate(p);
}

void deleteLast(List& L, Song& S) {
    if (isEmpty(L)) return;
    Node* p = L.tail;
    S = p->info;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.tail = p->prev;
        L.tail->next = nullptr;
    }
    deallocate(p);
}

void deleteAfter(List& L, Node* Q, Song& S) {
    if (Q == nullptr || Q->next == nullptr) return;
    Node* p = Q->next;
    S = p->info;
    Q->next = p->next;
    if (p->next != nullptr) p->next->prev = Q;
    else L.tail = Q; // removed tail
    deallocate(p);
}

void deleteBefore(List& L, Node* Q, Song& S) {
    if (Q == nullptr || Q->prev == nullptr) return;
    Node* p = Q->prev;
    S = p->info;
    Q->prev = p->prev;
    if (p->prev != nullptr) p->prev->next = Q;
    else L.head = Q; // removed head
    deallocate(p);
}

void updateAtPosition(List& L, int posisi, const Song& newS) {
    Node* target = getNodeAt(L, posisi);
    if (target == nullptr) return;
    target->info = newS;
}

void updateBefore(List& L, Node* Q, const Song& newS) {
    if (Q == nullptr || Q->prev == nullptr) return;
    Q->prev->info = newS;
}

void viewList(const List& L) {
    std::cout << "Daftar Lagu:\n";
    std::cout << std::left
              << std::setw(6) << "No"
              << std::setw(20) << "Title"
              << std::setw(16) << "Artist"
              << std::setw(10) << "Duration"
              << std::setw(12) << "PlayCount"
              << std::setw(8) << "Rating"
              << std::setw(14) << "PopScore"
              << "\n";
    std::cout << "-----------------------------------------------------------------------\n";
    Node* p = L.head;
    int idx = 1;
    while (p != nullptr) {
        std::cout << std::left
                  << std::setw(6) << idx
                  << std::setw(20) << p->info.Title
                  << std::setw(16) << p->info.Artist
                  << std::setw(10) << p->info.DurationSec
                  << std::setw(12) << p->info.PlayCount
                  << std::setw(8) << std::fixed << std::setprecision(1) << p->info.Rating
                  << std::setw(14) << std::fixed << std::setprecision(2) << popularityScore(p->info)
                  << "\n";
        p = p->next;
        idx++;
    }
    std::cout << std::defaultfloat;
}

void searchByPopularityRange(const List& L, float minScore, float maxScore) {
    std::cout << "\nHasil Searching PopularityScore dalam rentang [" << minScore << ", " << maxScore << "]:\n";
    Node* p = L.head;
    int idx = 1;
    bool found = false;
    while (p != nullptr) {
        float ps = popularityScore(p->info);
        if (ps >= minScore && ps <= maxScore) {
            found = true;
            std::cout << "Posisi " << idx << " - " << p->info.Title << " | Artist: " << p->info.Artist
                      << " | PopScore: " << std::fixed << std::setprecision(2) << ps << "\n";
        }
        p = p->next;
        idx++;
    }
    if (!found) std::cout << "Tidak ditemukan lagu dalam rentang tersebut.\n";
}

Node* getNodeAt(const List& L, int posisi) {
    if (posisi <= 0) return nullptr;
    Node* p = L.head;
    int idx = 1;
    while (p != nullptr && idx < posisi) {
        p = p->next;
        idx++;
    }
    return (idx == posisi) ? p : nullptr;
}

float popularityScore(const Song& s) {
    return 0.8f * static_cast<float>(s.PlayCount) + 20.0f * s.Rating;
}
