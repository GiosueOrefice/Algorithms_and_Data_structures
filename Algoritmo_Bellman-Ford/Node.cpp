#include "Node.h"

Node::Node(char data)
{
    this->data=data;
    Adj=new list<Node *>;

}

void Node::SetData(char data)
{
    this->data=data;
}

char Node::GetData()
{
    return data;
}


void Node::SetD(int d)
{
    this->d=d;
}

int Node::GetD()
{
    return d;
}

void Node::SetParent(Node *x)
{
    this->p=x;
}

Node* Node::GetParent()
{
    return this->p;
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

list<Node *> *Node::GetAdj()
{
    return this->Adj;
}
