#ifndef SET_H
#define SET_H
#include <Node.h>
#include<iostream>

class Set
{
     private:
        Node *data;
        Set *parent;
        int rango;

    public:
        Set(Node *x);
        void SetData(Node *x);
        Node* GetData();
        void setParent(Set* y);
        Set* getParent();
        void setRank(int i);
        int getRank();
};

#endif // SET_H
