#include <iostream>
#include <stdlib.h>
#define max 100
#include <stdio.h>
#include<math.h>

using namespace std;
typedef struct{
    int n;
    char a;
    char b;
    char c;
} nhom;

typedef nhom elem;

struct node {
    elem info;
    node *next;
};

struct stack {
    node *top;
};

void createstack(stack &s)
{
    s.top = NULL;
}

bool emptystack(stack s)
{
    return s.top == NULL;
}

bool push(stack &s, elem x)
{
    node *p = new node;
    if (p == NULL) {
        return false;
    }
    p->info = x;
    p->next = s.top;
    s.top = p;
    return true;
}

bool pop(stack &s, elem &x)
{
    if (emptystack(s)) {
        return false;
    }
    node *p = s.top;
    x = p->info;
    s.top = p->next;
    delete p;
    return true;
}

int main()
{
    stack s;
    nhom bo;
    char A,B,C;
    int N,m,count=0;
    std::cout << "Nhap so dia: ";
    std::cin >> m;
    createstack(s);
    bo.n = m;
    bo.a = 'A';
    bo.b = 'B';
    bo.c = 'C';
    push(s, bo);
    do {
        pop(s, bo);
        A = bo.a;
        B = bo.b;
        C = bo.c;
        if (bo.n == 1) {
            std::cout << "\nChuyen " << bo.a << " qua " << bo.c;
            count++;
        } else {
            N = bo.n;
            bo.n = N - 1;
            bo.a = B;
            bo.b = A;
            bo.c = C;
            push(s, bo);
            bo.n = 1;
            bo.a = A;
            bo.b = ' ';
            bo.c = C;
            push(s, bo);
            bo.n = N - 1;
            bo.a = A;
            bo.b = C;
            bo.c = B;
            push(s, bo);
        }
    } while (!emptystack(s));
    cout<<"\nSo lan chuyen: "<<count<<endl;
    return 0;
}