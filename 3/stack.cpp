#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return (S.top == Nil);
}

bool isFull(Stack S) {
    return (S.top == N_STACK - 1);
}

void push(Stack &S, string x) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, string &x) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak bisa pop!" << endl;
        x = "";
    } else {
        x = S.info[S.top];
        S.top--;
    }
}

void printStack(Stack S) {
    if (isEmpty(S)) {
        cout << "[kosong]" << endl;
    } else {
        cout << "[ ";
        for (int i = 0; i <= S.top; i++) {
            cout << S.info[i];
            if (i < S.top) cout << ", ";
        }
        cout << " ]" << endl;
    }
}

void manageAction(Stack &S_Aksi, Stack &S_Redo, string aksi) {
    string temp;

    if (aksi == "UNDO") {
        if (!isEmpty(S_Aksi)) {
            pop(S_Aksi, temp);
            push(S_Redo, temp);
            cout << "UNDO dilakukan. Aksi " << temp << " dipindahkan ke stack REDO." << endl;
        } else {
            cout << "Tidak ada aksi untuk di-UNDO!" << endl;
        }

    } else if (aksi == "REDO") {
        if (!isEmpty(S_Redo)) {
            pop(S_Redo, temp);
            push(S_Aksi, temp);
            cout << "REDO dilakukan. Aksi " << temp << " dikembalikan ke stack Aksi." << endl;
        } else {
            cout << "Tidak ada aksi untuk di-REDO!" << endl;
        }

    } else {
        push(S_Aksi, aksi);
        S_Redo.top = Nil;
        cout << "Aksi baru \"" << aksi << "\" ditambahkan." << endl;
    }
}

void totalDamage(Stack &S, int &damage) {
    string aksi;
    damage = 0;

    while (!isEmpty(S)) {
        pop(S, aksi);
        if (aksi == "ATTACK") damage += 30;
        else if (aksi == "DEFENSE") damage += 5;
    }

    cout << "Total damage yang dihasilkan: " << damage << endl;
}
