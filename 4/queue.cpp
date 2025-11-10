#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmpty(queue Q) {
    return (Q.head == Nil);
}

address alokasi(string namaDok, string namaPengguna, int hal) {
    address p = new node;
    p->info.namaDok = namaDok;
    p->info.namaPengguna = namaPengguna;
    p->info.hal = hal;
    p->next = Nil;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = Nil;
}

void enqueue(queue &Q, address p) {
    if (isEmpty(Q)) {
        Q.head = p;
        Q.tail = p;
    } else {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void dequeue(queue &Q, address &p) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        p = Nil;
    } else {
        p = Q.head;
        Q.head = Q.head->next;
        if (Q.head == Nil) {
            Q.tail = Nil;
        }
        p->next = Nil;
    }
}

int countDocByUser(queue Q, string pengguna) {
    int count = 0;
    address p = Q.head;
    while (p != Nil) {
        if (p->info.namaPengguna == pengguna) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void antriPrinter(queue &Q, dataDoc doc) {
    int jumlah = countDocByUser(Q, doc.namaPengguna);
    if (jumlah >= 3) {
        cout << "Pengguna " << doc.namaPengguna 
            << " sudah memiliki 3 dokumen aktif! Tidak bisa menambah lagi." << endl;
        return;
    }

    address p = alokasi(doc.namaDok, doc.namaPengguna, doc.hal);
    enqueue(Q, p);
    cout << "Dokumen \"" << doc.namaDok << "\" dari " 
        << doc.namaPengguna << " berhasil ditambahkan ke antrian." << endl;
}

void simulasiCetak(queue &Q, int kertas) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong!" << endl;
        return;
    }

    cout << "=== Proses Pencetakan Dimulai ===" << endl;
    address p;
    while (!isEmpty(Q)) {
        if (Q.head->info.hal <= kertas) {
            kertas -= Q.head->info.hal;
            dequeue(Q, p);
            cout << "Mencetak: " << p->info.namaDok << " (" 
                 << p->info.namaPengguna << ", " 
                 << p->info.hal << " halaman)" << endl;
            dealokasi(p);
        } else {
            cout << "Kertas tidak mencukupi untuk mencetak dokumen berikutnya!" << endl;
            break;
        }
    }
    cout << "Sisa kertas: " << kertas << endl;
    cout << "=== Proses Pencetakan Selesai ===" << endl << endl;
}

void printQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong." << endl;
    } else {
        cout << "--- Daftar Dokumen Dalam Antrian ---" << endl;
        address p = Q.head;
        while (p != Nil) {
            cout << p->info.namaDok << " - " << p->info.namaPengguna 
                 << " (" << p->info.hal << " halaman)" << endl;
            p = p->next;
        }
        cout << endl;
    }
}
