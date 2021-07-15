#ifndef GRAPH_H
#define GRAPH_H
#include <Node.h>
#include <vector>
#include <Arco.h>
#include <CodaMinPriority.h>
class Graph
{
    private:
        vector<Node *> *V;
        vector<Arco *> *E;
    public:

        Graph();
        void AddNode(Node *x);
        Node *GetNode(int i);
        void PrintAdjGraph();
        void AddArco(Arco *x);
        Arco *GetArco(Node *u,Node *v);
        void PrintArcoGraph();
        void Prim(Node *r);


};

#endif // GRAPH_H

