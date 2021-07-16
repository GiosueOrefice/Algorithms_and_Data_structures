#include "Node.h"

Node::Node(int data){
    this->data=data;
    adj=new list<Node *>;
        }
void Node::addEdge(Node *w){
    adj->push_back(w);}

list<Node *>* Node::getAdj(){
    return adj;}

int Node::getData(){
    return data;}

