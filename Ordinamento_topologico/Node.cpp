#include "Node.h"

Node::Node(string data)
{
    this->data=data;
    this->d=INT_MAX;
    Adj=new list<Node *>;

}

void Node::SetData(string data)
{
    this->data=data;
}

string Node::GetData()
{
    return data;
}

void Node::SetColor(string color)
{
    this->color=color;
}

string Node::GetColor()
{
    return color;
}

void Node::SetParent(Node *x)
{
    this->p=x;
}

Node* Node::GetParent()
{
    return p;
}

void Node::AddEdge(Node *x)
{
    Adj->push_back(x);
}

void Node::PrintAdj()
{
    for(auto v:*Adj)
        cout<<v->GetData()<<" ";
}

void Node::SetD(int time)
{
    this->d=time;
}

int Node::GetD()
{
    return d;
}

void Node::SetF(int time)
{
    this->f=time;
}

int Node::GetF()
{
    return this->f;
}

list<Node *> *Node::GetAdj()
{
    return this->Adj;
}
