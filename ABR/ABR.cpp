#include "ABR.h"

void ABR::TREE_INSERT(Node *z)
{
    Node *y=nullptr;
    Node *x=Getradice();
    while (x!=nullptr)
    {
        y=x;
        if(z->GetVal()->GetNum()<x->GetVal()->GetNum())
            x=x->GetSX();
        else x=x->GetDX();
    }

    z->SetParent(y);
    if(y==nullptr)
        Radice=z;
    else if (z->GetVal()->GetNum()<y->GetVal()->GetNum())
        y->SetSX(z);
    else y->SetDX(z);
}

void ABR::stampa(Node *pt)
{
   if(pt!=nullptr){
    stampa(pt->GetSX());
    cout<<pt->GetVal()->GetNum()<<" ";
    stampa(pt->GetDX());}

}

Node* ABR::Minimo(Node *x)
{
    Node *pt=x;
    while(pt->GetSX()!=nullptr)
        pt=pt->GetSX();
   return pt;
}

Node* ABR::Massimo(Node *x)
{
    Node *pt=x;
    while(pt->GetDX()!=nullptr)
        pt=pt->GetDX();
   return pt;
}

bool ABR::Search(Data key)
{
    Node *pt=Radice;
    while(pt!=nullptr){
    if(key.GetNum()>pt->GetVal()->GetNum())
        pt=pt->GetDX();
    else if(key.GetNum()<pt->GetVal()->GetNum())
        pt=pt->GetSX();
    else return true;
    }
    return false;
}

Node *ABR::GetNode(Data key)
{
    Node *pt=Radice;
    while(pt!=nullptr){
    if(key.GetNum()>pt->GetVal()->GetNum())
        pt=pt->GetDX();
    else if(key.GetNum()<pt->GetVal()->GetNum())
        pt=pt->GetSX();
    else return pt;
    }
    return nullptr;
}

Node *ABR::Successor(Node *x)
{
    if(x->GetDX()!=nullptr)
        return Minimo(x->GetDX());
    Node *y=x->GetParent();

    while (y!=nullptr && x==y->GetDX())
    {
        x=y;
        y=y->GetParent();
    }
    return y;
}

Node *ABR::Predecessor(Node *x)
{
    if(x==nullptr)
        return nullptr;
    if(x->GetSX()!=nullptr)
        return Massimo(x->GetSX());
    else
    {
        Node *y=x->GetParent();
        Node *X=x;
        while(y!=nullptr && X==y->GetSX())
        {
            x=y;
            y=y->GetParent();
        }
        return y;
    }
}

void ABR::Transplant(Node *u,Node *v)
{
    if(u->GetParent()==nullptr)
        SetRadice(v);
    else if( u==u->GetParent()->GetSX())
        u->GetParent()->SetSX(v);
    else
        u->GetParent()->SetDX(v);
    if(v!=nullptr)
        v->SetParent(u->GetParent());

}

void ABR::Delete(Node *z)
{
    if(z->GetSX()==nullptr)
        Transplant(z,z->GetDX());
    else if(z->GetDX()==nullptr)
        Transplant(z,z->GetSX());
    else {
        Node *y=Minimo(z->GetDX());
        if(y->GetParent()!=z)
        {
            Transplant(y,y->GetDX());
            y->SetDX(z->GetDX());
            y->GetDX()->SetParent(y);
        }
        Transplant(z,y);
        y->SetSX(z->GetSX());
        y->GetSX()->SetParent(y);
    }

}
