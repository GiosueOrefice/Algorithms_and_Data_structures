#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <list>

using namespace std;
class Node
{
    private:
        char data;
        string color;
        int d;
        list<Node *> *Adj;
        Node *p;

    public:
        Node(char data);
        void SetData(char data);
        char GetData();
        void SetColor(string color);
        string GetColor();
        void SetD(int d);
        int GetD();
        void SetParent(Node *x);
        Node* GetParent();
        void AddEdge(Node *x);
        void PrintAdj();
        list<Node *> *GetAdj();

};

#endif // NODE_H

