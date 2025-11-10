#ifndef QUEUEPRINTER_H
#define QUEUEPRINTER_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct dokumen {
    string namaDok;
    string namaPengguna;
    int hal; 
};

typedef dokumen dataDoc;
typedef struct node *address;

struct node {
    dataDoc info;
    address next;
};

struct queue {
    address head;
    address tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
address alokasi(string namaDok, string namaPengguna, int hal);
void dealokasi(address &p);
void enqueue(queue &Q, address p);
void dequeue(queue &Q, address &p);
int countDocByUser(queue Q, string pengguna);
void antriPrinter(queue &Q, dataDoc doc);
void simulasiCetak(queue &Q, int kertas);
void printQueue(queue Q);

#endif
