#include "dll.h"
#include <iostream>
using namespace std;

int main() {
    doublylist L;
    createList(L);

    insertLast(L, alokasi("google.com"));
    insertLast(L, alokasi("youtube.com"));
    insertLast(L, alokasi("github.com"));
    insertLast(L, alokasi("stackoverflow.com"));
    insertLast(L, alokasi("wikipedia.org"));

    printList(L);

    hapusRiwayat(L, "github.com");
    printList(L);

    backward(L, "youtube.com");

    backward(L, "linkedin.com");

    return 0;
}
