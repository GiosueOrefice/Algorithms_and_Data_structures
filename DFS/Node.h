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
        list<Node *> *Adj;
        Node *p;
        int d;
        int f;

    public:
        Node(char data);
        void SetData(char data);
        char GetData();
        void SetColor(string color);
        string GetColor();
        void SetParent(Node *x);
        Node* GetParent();
        void AddEdge(Node *x);
        void PrintAdj();
        void SetD(int time);
        int GetD();
        void SetF(int time);
        int GetF();
        list<Node *> *GetAdj();

};

#endif // NODE_H
