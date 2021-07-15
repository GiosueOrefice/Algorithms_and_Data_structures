#ifndef GRAPH_H
#define GRAPH_H
#include <Node.h>
#include <vector>
#include <queue>

class Graph
{
    private:
        vector<Node *> *V;
    public:

        Graph();
        void AddNode(Node *x);
        Node *GetNode(int i);
        void PrintAdjGraph();
        void BFS(Node *s);

};

#endif // GRAPH_H
