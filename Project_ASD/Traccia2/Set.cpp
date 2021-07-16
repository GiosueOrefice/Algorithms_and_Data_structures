#include "Set.h"


Set::Set(Node *x)
{
    this->data=x;
    this->rango=0;
}
void Set::SetData(Node *x){
    data=x;
}
Node* Set::GetData(){
    return data;}

void Set::setParent(Set* y){
    parent=y;}

Set*  Set::getParent(){
    return parent; }

void Set::setRank(int i){
    rango=i;}

int Set::getRank(){
    return rango;}
