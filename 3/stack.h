#ifndef STACK_H
#define STACK_H
#define Nil -1
#define N_STACK 2025

#include <iostream>
#include <string>
using namespace std;

struct Stack {
    string info[N_STACK];  
    int top;               
};


void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, string x);
void pop(Stack &S, string &x);
void printStack(Stack S);

void manageAction(Stack &S_Aksi, Stack &S_Redo, string aksi);
void totalDamage(Stack &S, int &damage);

#endif
