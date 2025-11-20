// DLLPlaylist.h
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>

struct Song {
    std::string Title;
    std::string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; // 0.0 - 5.0
};

struct Node {
    Song info;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

bool isEmpty(const List& L);
void createList(List& L);
Node* allocate(const Song& S);
void deallocate(Node* P);
void insertFirst(List& L, const Song& S);
void insertLast(List& L, const Song& S);
void insertAfter(List& L, Node* Q, const Song& S);
void insertBefore(List& L, Node* Q, const Song& S);
void deleteFirst(List& L, Song& S);
void deleteLast(List& L, Song& S);
void deleteAfter(List& L, Node* Q, Song& S);
void deleteBefore(List& L, Node* Q, Song& S);
void updateAtPosition(List& L, int posisi, const Song& newS);
void updateBefore(List& L, Node* Q, const Song& newS);
void viewList(const List& L);
void searchByPopularityRange(const List& L, float minScore, float maxScore);

Node* getNodeAt(const List& L, int posisi); // returns nullptr if out of range
float popularityScore(const Song& s);

#endif
