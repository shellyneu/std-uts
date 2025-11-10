#ifndef SLL_H
#define SLL_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct Panen {
    string nama;
    string bulan;
    int jumlah;
};

typedef Panen datapanen;         
typedef struct ElmList *address; 

struct ElmList {
    datapanen info;
    address next;
};

struct List {
    address first;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(string nama, string bulan, int jumlah);
void dealokasi(address &p);
void tambahData(List &L, address p);
void printList(List L);
address panenTerbanyak(List L);
void panenBulanan(List L, string bulan);

#endif
