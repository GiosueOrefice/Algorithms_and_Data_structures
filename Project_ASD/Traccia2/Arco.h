#ifndef ARCO_H
#define ARCO_H
#include <Node.h>

class Arco{

    private:
        Node *u;
        Node *v;
        int peso;

    public:
        Arco(Node *u,Node *v,int peso);
        int GetPeso();
        Node *Getu();
        Node *Getv();
        void SetArco(Node *u,Node *v,int peso);
        void PrintArco();
};

#endif // ARCO_H
