#include "Disjoint.h"

Set *Disjoint::makeSet(Set *x){
   x->setParent(x);
   x->setRank(0);
   return x;
}

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

void Disjoint::Union(Set *x,Set *y){
    Link(FindSet(x),FindSet(y));
}
