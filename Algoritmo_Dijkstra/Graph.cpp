#include "Graph.h"

Graph::Graph()
{
    V=new vector<Node *>;
    E=new vector<Arco *>;
}

void Graph::AddNode(Node *x)
{
    V->push_back(x);
}


Node* Graph::GetNode(int i)
{
    return V->at(i);
}

void Graph::PrintAdjGraph()
{
    for(auto v:*V){
        cout<<v->GetData()<<") ";
        v->PrintAdj();
        cout<<endl;
    }
}

void Graph::AddArco(Arco *x)
{
    E->push_back(x);
    x->GetU()->AddEdge(x->GetV());
}

Arco* Graph::GetArco(Node *u,Node *v)
{

    for(auto e:*E)
    {
        if(e->GetU()==u && e->GetV()==v)
            return e;
    }
}

void Graph::PrintArcoGraph()
{
    for(auto e:*E){
        e->PrintArco();
        cout<<endl;
    }
}
