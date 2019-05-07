/*
* Author    : Kevin Dyandradiva
* NPM       : 140810180046
* Kelas     : B
* Deskripsi : Exercise 2
* Tanggal   : 7 Mei 2019
*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct stack
{
    char isi;
    stack *next;
}   *stk, *ptr;

void newNode(ptr &pNew, char fill)
{
    pNew = new stack;
    pNew->isi=fill;
    pNew->next = NULL;
}

void push(stk &head, ptr pNew)
{
    if(head==NULL)
        head = pNew;

    else
    {
        pNew->next = head;
        head = pNew;
    }
}

void pop(stk &head, ptr &pSav)
{
    if(head==NULL)
        cout << "STACK EMPTY!\n";

    else if(head->next==NULL)
    {
        pSav=head;
        head=NULL;
    }

    else
    {
        pSav = head;
        head = pSav->next;
        pSav->next = NULL;
    }
}

int main()
{
    stk S=NULL;
    ptr p=NULL;

    for(char i='A'; i<='E'; i++)
    {
        newNode(p,i);
        push(S,p);
    }

    do
    {
        pop(S,p);
        cout << p->isi << "\n";
    }while(S!=NULL);
}
