#include "HashTable.h"

HashTable::HashTable(int m){
    this->m=m;
    Table=new list<Set *>[m];
    srand(time(NULL));
    this->p=919;
    this->a=rand()%(p-1);
    this->b=1+rand()%(p-1);
}

int HashTable::hashFunction(Set *x) {
    int val=0;
    for (int i=0; i<x->getValue().size(); i++)
        val=((int)x->getValue().at(i)*(i+1))+val;
    val=((val+x->getValue().size())*(p-b))%(m+a);

    int indice=((((val+x->getKey())*a+b)%p)%m);
    if(indice<0)
       indice=indice*-1;

    return indice;
}

int HashTable::get_m(){
    return m;
}

void HashTable::Insert(Set *x){
    int index = hashFunction(x);
    Table[index].push_front(x);
}

void HashTable::displayHash() {
  for (int i = 0; i <m; i++) {
    cout << i;
    for (auto x : Table[i])
      {cout <<"->"; x->printSet();}
    cout << endl;
  }
}

bool HashTable::Search(int key,string value){
   int i= hashFunction(new Set(key,value));
    for(auto vv: Table[i]){
        if(vv->getKey()==key && vv->getValue()==value)
            return true;
    }
    return false;
}


Set* HashTable::getSet(int key,string value){
    int i= hashFunction(new Set(key,value));

    for(auto vv: Table[i]){
    if(vv->getKey()==key && vv->getValue()==value)
        return vv;}
    return nullptr;
}
