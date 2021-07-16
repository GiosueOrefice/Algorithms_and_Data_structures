#ifndef GRAPH_H
#define GRAPH_H
#include <Node.h>
#include <Arco.h>
#include <vector>

using namespace std;

class Graph{

    private:
        int N;
        int P;
        vector <Node*> G_V;
        vector <Arco*> G_E;

    public:
        Graph(int N,int P);
        int getN();
        int getP();
        void addNode(Node *w);
        Node *getNode(int v);
        void printAdj();
        void addArco(Arco *E);
        Arco* getArco(int e);
        void printArco();
        vector <Arco*> GetG_E();
        vector <Node*> GetG_V();

};


#endif // GRAPH_H
