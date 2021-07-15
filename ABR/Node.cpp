#include "Node.h"

Node::Node(Data *val)
{
   this->val=val;
   this->sx=nullptr;
   this->dx=nullptr;
   this->parent=nullptr;
}

Data* Node::GetVal()
{
    return val;
}

void Node::SetVal()
{
    this->val=val;
}

void Node::SetSX(Node *x)
{
    this->sx=x;
}

void Node::SetDX(Node *x)
{
    this->dx=x;
}

void Node::SetParent(Node *x)
{
    this->parent=x;
}

Node *Node::GetSX()
{
    return sx;
}

Node* Node::GetDX()
{
    return dx;
}

Node* Node::GetParent()
{
    return parent;
}
