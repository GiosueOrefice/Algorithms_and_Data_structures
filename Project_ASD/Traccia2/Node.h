#ifndef NODE_H
#define NODE_H
#include<iostream>
#include <list>

using namespace std;

class Node{

    private:
        int data;
        list<Node *> *adj;

    public:
        Node(int data);
        void addEdge(Node *w);
        list<Node *> *getAdj();
        int getData();
};

#endif // NODE_H
