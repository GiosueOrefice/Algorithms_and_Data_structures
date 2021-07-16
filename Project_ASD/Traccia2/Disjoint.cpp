#include "Disjoint.h"

void Disjoint::makeSet(Node *x){
    VSet.push_back(new Set(x));
    VSet[VSet.size()-1]->setParent(VSet[VSet.size()-1]);
}

Set *Disjoint::GetSet(int i){
    return VSet[i];}

Set* Disjoint::FindSet(Set *x){
    if(x!=x->getParent())
        x->setParent(FindSet(x->getParent()));
    return x->getParent();
    }

void Disjoint::Link(Set *x,Set *y){
    if(x->getRank()>y->getRank())
        y->setParent(x);
    else {
        x->setParent(y);
        if(x->getRank()==y->getRank())
            y->setRank(y->getRank()+1);
            }
    }

void Disjoint::Union(Set*x,Set *y){
    Link(FindSet(x),FindSet(y));
        }
