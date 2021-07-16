#include "Set.h"

Set::Set(int key,string value){
    this->key=key;
    this->value=value;
}
void Set::setKey(int key){
    this->key=key;
}
int Set::getKey(){
    return key;}

void Set::setValue(string value){
    this->value=value;
}

string Set::getValue(){
    return value;
}

void Set::setParent(Set* i){
    parent=i;}

Set*  Set::getParent(){
    return parent; }

void Set::setRank(int i){
    rango=i;}

int Set::getRank(){
    return rango;}

void Set::printSet(){
    cout<<"("<<getKey()<<","<<getValue()<<")";}
