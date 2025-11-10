#include "sll.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    return (L.first == Nil);
}

void createList(List &L) {
    L.first = Nil;
}

address alokasi(string nama, string bulan, int jumlah) {
    address p = new ElmList;
    p->info.nama = nama;
    p->info.bulan = bulan;
    p->info.jumlah = jumlah;
    p->next = Nil;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = Nil;
}

void tambahData(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void printList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address q = L.first;
        cout << "--- Data Panen ---" << endl;
        while (q != Nil) {
            cout << "Nama Tanaman : " << q->info.nama
                << ", Bulan Panen : " << q->info.bulan
                << ", Jumlah : " << q->info.jumlah << " kg" << endl;
            q = q->next;
        }
        cout << endl;
    }
}

address panenTerbanyak(List L) {
    if (isEmpty(L)) {
        return Nil;
    } else {
        address p = L.first;
        address maxNode = p;
        while (p != Nil) {
            if (p->info.jumlah > maxNode->info.jumlah) {
                maxNode = p;
            }
            p = p->next;
        }
        return maxNode;
    }
}

void panenBulanan(List L, string bulan) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    bool found = false;
    address p = L.first;
    cout << "Tanaman yang dipanen pada bulan " << bulan << ": ";
    while (p != Nil) {
        if (p->info.bulan == bulan) {
            cout << p->info.nama << " ";
            found = true;
        }
        p = p->next;
    }
    if (!found) cout << "Tidak ada.";
    cout << endl;
}
