#include "Arco.h"

Arco::Arco(Node *u,Node *v,int peso)
{
    this->u=u;
    this->peso=peso;
    this->v=v;
}

Node* Arco::GetU()
{
    return u;
}

Node* Arco::GetV()
{
    return v;
}

int Arco::GetPeso()
{
    return peso;
}

void Arco::SetU(Node *u)
{
    this->u=u;
}

void Arco::SetV(Node *v)
{
    this->v=v;
}

void Arco::SetPeso(int peso)
{
    this->peso=peso;
}

void Arco::PrintArco()
{
    cout<<"("<<u->GetData()<<","<<v->GetData()<<","<<peso<<")";
}

