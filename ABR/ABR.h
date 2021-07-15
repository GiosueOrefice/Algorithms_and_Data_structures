#ifndef ABR_H
#define ABR_H
#include <Node.h>
#include <iostream>

using namespace std;
class ABR
{
    private:
        Node *Radice;


    public:
        ABR():Radice(nullptr){};
        void TREE_INSERT(Node *z);
        Node *Getradice(){return Radice;};
        Node *SetRadice(Node *x){this->Radice=x;};
        void stampa(Node *pt);
        Node *Minimo(Node *x);
        Node *Massimo(Node *x);
        bool Search(Data key);
        Node *GetNode(Data key);
        Node *Successor(Node *x);
        Node *Predecessor(Node *x);
        void Transplant(Node *u,Node *v);
        void Delete(Node *z);
};

#endif // ABR_H
