#include "sll.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    address p1 = alokasi("Padi", "Maret", 500);
    address p2 = alokasi("Jagung", "Maret", 300);
    address p3 = alokasi("Labu", "April", 200);
    address p4 = alokasi("Kedelai", "Maret", 800);

    tambahData(L, p1);
    tambahData(L, p2);
    tambahData(L, p3);
    tambahData(L, p4);

    printList(L);

    address maxNode = panenTerbanyak(L);
    if (maxNode != Nil) {
        cout << "Hasil panen terbanyak adalah: "
            << maxNode->info.nama << " (" 
            << maxNode->info.jumlah << " kg)" << endl;
    }
    cout << endl;

    panenBulanan(L, "Maret");
    panenBulanan(L, "April");
    panenBulanan(L, "Juni");

    return 0;
}
