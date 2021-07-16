#ifndef SET_H
#define SET_H
#include <iostream>
#include <string>
using namespace std;

class Set
{
    private:
        int key;
        string value;
        Set *parent;
        int rango;

    public:
        Set(int key,string value);
        void setKey(int key);
        int getKey();
        void setValue(string value);
        string getValue();
        void setParent(Set* i);
        Set* getParent();
        void setRank(int i);
        int getRank();
        void printSet();
};

#endif // SET_H
