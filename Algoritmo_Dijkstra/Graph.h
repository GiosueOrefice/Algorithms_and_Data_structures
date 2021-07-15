#ifndef GRAPH_H
#define GRAPH_H
#include <Node.h>
#include <vector>
#include <Arco.h>
class Graph
{
    private:
        vector<Node *> *V;
        vector<Arco *> *E;
    public:

        Graph();
        int N_V(){return this->V->size();}
        int N_E(){return this->E->size();}
        vector<Arco *> *GetALLArco(){return this->E;}
        vector<Node *> *GetALLNode(){return this->V;}
        void AddNode(Node *x);
        Node *GetNode(int i);
        void PrintAdjGraph();
        void AddArco(Arco *x);
        Arco *GetArco(Node *u,Node *v);
        void PrintArcoGraph();

};

#endif // GRAPH_H
