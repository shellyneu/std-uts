#ifndef DLL_H
#define DLL_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

typedef string infotype;
typedef struct node *address;

struct node {
    infotype url;
    address next;
    address prev;
};

struct doublylist {
    address first;
    address last;
};

void createList(doublylist &L);
bool isEmpty(doublylist L);
address alokasi(string url);
void dealokasi(address &p);
void insertLast(doublylist &L, address p);
address cariRiwayat(doublylist L, string cari);
void hapusRiwayat(doublylist &L, string cari);
void backward(doublylist L, string url);
void printList(doublylist L);

#endif
