#include "Arco.h"

Arco::Arco(Node *u,Node *v,int peso){
    this->u=u;
    this->v=v;
    this->peso=peso;}

int Arco::GetPeso(){
    return peso;
}

Node* Arco::Getu(){
    return u;}

Node* Arco::Getv(){
    return v;}

void Arco::SetArco(Node *u,Node *v,int peso){
    this->u=u;
    this->v=v;
    this->peso=peso;
}

void Arco::PrintArco(){
    cout<<"("<<this->u->getData()<<",";
    cout<<this->v->getData()<<")=";
    cout<<this->peso<<endl;
}
