#ifndef ARCO_H
#define ARCO_H
#include <Node.h>
#include <iostream>

using namespace std;

class Arco
{
    private:
        Node *u;
        Node *v;
        int peso;
    public:
        Arco(Node *u,Node *v,int peso);
        Node* GetU();
        Node* GetV();
        int GetPeso();
        void SetU(Node *u);
        void SetV(Node *v);
        void SetPeso(int peso);
        void PrintArco();

};

#endif // ARCO_H
