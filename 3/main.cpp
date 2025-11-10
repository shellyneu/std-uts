#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S_Aksi, S_Redo;
    createStack(S_Aksi);
    createStack(S_Redo);

    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "DEFENSE");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "UNDO");
    manageAction(S_Aksi, S_Redo, "UNDO");
    manageAction(S_Aksi, S_Redo, "REDO");
    manageAction(S_Aksi, S_Redo, "DEFENSE");

    cout << "\n=== Stack Aksi ===" << endl;
    printStack(S_Aksi);

    cout << "=== Stack Redo ===" << endl;
    printStack(S_Redo);

    int total = 0;
    totalDamage(S_Aksi, total);

    return 0;
}
