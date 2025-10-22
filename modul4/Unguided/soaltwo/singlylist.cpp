#include "SinglyList.h"

void createList(List &L) {
    L.first = nullptr;
}

Node* alokasi(infotype x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(Node* P) {
    delete P;
}

void insertLast(List &L, Node* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            dealokasi(L.first);
            L.first = nullptr;
        } else {
            Node* Q = L.first;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            dealokasi(Q->next);
            Q->next = nullptr;
        }
    }
}

void deleteAfter(List &L, infotype key) {
    Node* Q = L.first;
    while (Q != nullptr && Q->info != key) {
        Q = Q->next;
    }
    if (Q != nullptr && Q->next != nullptr) {
        Node* P = Q->next;
        Q->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.first = nullptr;
    cout << "\n- List Berhasil Terhapus -\n";
}

void printList(List L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}