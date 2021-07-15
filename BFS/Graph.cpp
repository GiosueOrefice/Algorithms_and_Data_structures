#include "Graph.h"

Graph::Graph()
{
    V=new vector<Node *>;
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

void Graph::BFS(Node *s)
{
    Node *u;
    for(auto v:*V){
        v->SetD(INT_MAX);
        v->SetColor("white");
        v->SetParent(nullptr);
    }

    s->SetD(0);
    s->SetColor("gray");
    s->SetParent(nullptr);
    queue<Node *> Q;
    Q.push(s);
    while(Q.size()!=0)
    {
        u=Q.front();
        Q.pop();
        for(auto v:*u->GetAdj())
        {
            if(v->GetColor()=="white")
            {
                v->SetD(u->GetD()+1);
                v->SetColor("gray");
                v->SetParent(u);
                Q.push(v);
            }
        }

    }
}


