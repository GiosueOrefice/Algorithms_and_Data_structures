#ifndef GRAPH_H
#define GRAPH_H
#include <Node.h>
#include <vector>
#include <list>

class Graph
{
    private:
        vector<Node *> *V;
        int time;
    public:

        Graph();
        void AddNode(Node *x);
        Node *GetNode(int i);
        void PrintAdjGraph();
        void DFS(list<Node *> *Lista);
        void DFS_Visit(Node *u,list<Node *> *Lista);
        int GetTime();
        void SetTime(int time);



};

#endif // GRAPH_H
