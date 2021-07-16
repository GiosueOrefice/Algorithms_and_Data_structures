#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <Disjoint.h>
#include <iostream>
#include <list>
#include <ctime>

using namespace std;

class HashTable
{
   private:
    int m;
    int p;
    int a;
    int b;
    list<Set *> *Table;

    public:
    HashTable(int m);
    int hashFunction(Set *x);
    int get_m();
    void Insert(Set *x);
    void displayHash();
    bool Search(int key,string value);
    Set *getSet(int key,string value);

};

#endif // HASHTABLE_H
