#include "dll.h"
using namespace std;

void createList(doublylist &L) {
    L.first = Nil;
    L.last = Nil;
}

bool isEmpty(doublylist L) {
    return (L.first == Nil);
}

address alokasi(string url) {
    address p = new node;
    p->url = url;
    p->next = Nil;
    p->prev = Nil;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = Nil;
}

void insertLast(doublylist &L, address p) {
    if (isEmpty(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

address cariRiwayat(doublylist L, string cari) {
    address p = L.first;
    while (p != Nil && p->url != cari) {
        p = p->next;
    }
    return p;
}

void hapusRiwayat(doublylist &L, string cari) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address p = cariRiwayat(L, cari);
    if (p == Nil) {
        cout << "Riwayat \"" << cari << "\" tidak ditemukan." << endl;
        return;
    }

    if (p == L.first && p == L.last) { 
        L.first = Nil;
        L.last = Nil;
    } else if (p == L.first) {
        L.first = p->next;
        L.first->prev = Nil;
    } else if (p == L.last) {
        L.last = p->prev;
        L.last->next = Nil;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    cout << "Riwayat \"" << cari << "\" berhasil dihapus!" << endl;
    dealokasi(p);
}

void backward(doublylist L, string url) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }

    address target = cariRiwayat(L, url);
    if (target == Nil) {
        cout << "Proses backward gagal: URL tidak ditemukan." << endl;
        return;
    }

    cout << "Menelusuri backward dari riwayat terbaru hingga \"" << url << "\":" << endl;
    address p = L.last;
    while (p != Nil) {
        cout << p->url << " ";
        if (p == target) break;
        p = p->prev;
    }
    cout << endl;
}

void printList(doublylist L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        cout << "--- Daftar Riwayat ---" << endl;
        address p = L.first;
        while (p != Nil) {
            cout << p->url << endl;
            p = p->next;
        }
        cout << endl;
    }
}
