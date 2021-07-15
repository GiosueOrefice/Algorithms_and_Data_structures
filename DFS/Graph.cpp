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


void Graph::DFS()
{
    for(auto v:*V)
    {
        v->SetColor("white");
        v->SetParent(nullptr);
    }
    SetTime(0);
    for(auto v:*V)
    {
        if(v->GetColor()=="white")
            DFS_Visit(v);
    }
}

void Graph::DFS_Visit(Node *u)
{
    SetTime(GetTime()+1);
    u->SetD(GetTime());
    u->SetColor("gray");
    for(auto v:*u->GetAdj())
    {
        if(v->GetColor()=="white")
        {
            v->SetParent(u);
            DFS_Visit(v);
        }
    }
    SetTime(GetTime()+1);
    u->SetColor("black");
    u->SetF(GetTime());
}

int Graph::GetTime()
{
    return this->time;
}

void Graph::SetTime(int time)
{
    this->time=time;
}
