#include "Graph.h"

Graph::Graph(int N,int P){
    this->N=N;
    this->P=P;
}

int Graph::getN(){
    return N;}

int Graph::getP(){
    return P;}

void Graph::addNode(Node *w){
    G_V.push_back(w);}

Node* Graph::getNode(int v){
    return G_V.at(v);}

void Graph::addArco(Arco *E){
    G_E.push_back(E);
    E->Getu()->addEdge(E->Getv());
    E->Getv()->addEdge(E->Getu());}

Arco* Graph::getArco(int e){
    return G_E.at(e);}


void Graph::printAdj(){
    for(auto v:G_V){
        cout<<"Adj("<<v->getData()<<"):";
        for(auto vv:*v->getAdj())
            cout<<" "<<vv->getData();
        cout<<endl;
    }
}

void Graph::printArco(){
    for(auto e:G_E){
        cout<<"("<<e->Getu()->getData()<<",";
        cout<<e->Getv()->getData()<<")=";
        cout<<e->GetPeso();
        cout<<endl;
    }
}

vector <Arco*> Graph::GetG_E(){
    return G_E;}

vector <Node*> Graph::GetG_V(){
    return G_V;}
