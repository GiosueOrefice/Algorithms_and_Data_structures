#include <iostream>
#include <Graph.h>
using namespace std;
void Inizializza(Graph &G,Node *s);
void Relax(Arco *x);
bool Bellman_Ford(Graph &G,Node *s);
int main()
{
    Graph G;
    G.AddNode(new Node('s')); //0;
    G.AddNode(new Node('t')); //1;
    G.AddNode(new Node('y')); //2;
    G.AddNode(new Node('x')); //3;
    G.AddNode(new Node('z')); //4;

    G.AddArco(new Arco(G.GetNode(0),G.GetNode(1),6));
    G.AddArco(new Arco(G.GetNode(0),G.GetNode(2),7));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(2),8));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(3),5));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(4),-4));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(4),9));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(3),-3));
    G.AddArco(new Arco(G.GetNode(3),G.GetNode(1),-2));
    G.AddArco(new Arco(G.GetNode(4),G.GetNode(3),7));
    G.AddArco(new Arco(G.GetNode(4),G.GetNode(0),2));
    G.PrintAdjGraph();
    cout<<endl;
    G.PrintArcoGraph();
    if(Bellman_Ford(G,G.GetNode(0)))
    {
        cout<<endl<<"SOLUZIONE"<<endl;
        for(int i=0;i<G.N_V();i++)
            cout<<G.GetNode(i)->GetData()<<"  "<<G.GetNode(i)->GetD()<<endl;
    }
    else cout<<endl<<"CICLO NEGATIVO"<<endl;
    return 0;
}

void Inizializza(Graph &G,Node *s)
{
    for(int i=0;i<G.N_V();i++)
        G.GetNode(i)->SetD(INT_MAX);
    s->SetD(0);
}

void Relax(Arco *x)
{
    if(x->GetV()->GetD()>x->GetU()->GetD()+x->GetPeso())
    {
        x->GetV()->SetD(x->GetU()->GetD()+x->GetPeso());
        x->GetV()->SetParent(x->GetU());
    }
}

bool Bellman_Ford(Graph &G,Node *s)
{
    Inizializza(G,s);
    for(int i=1;i<=G.N_V()-1;i++){
        for(auto e:*G.GetALLArco())
            Relax(e);}

    for(auto e:*G.GetALLArco())
    {
        if(e->GetV()->GetD()>e->GetU()->GetD()+e->GetPeso())
            return false;
    }
    return true;
}
