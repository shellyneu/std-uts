#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    antriPrinter(Q, {"Surat Tugas", "Ayu", 10});
    antriPrinter(Q, {"Undangan", "Sasa", 3});
    antriPrinter(Q, {"Notula Rapat", "Ayu", 15});
    antriPrinter(Q, {"Proposal", "Nia", 45});
    antriPrinter(Q, {"Laporan", "Ayu", 12}); 
    antriPrinter(Q, {"Kuitansi", "Ayu", 5}); 

    printQueue(Q);

    simulasiCetak(Q, 50); 
    printQueue(Q);

    antriPrinter(Q, {"Revisi", "Ayu", 25});
    printQueue(Q);

    simulasiCetak(Q, 200);

    return 0;
}
