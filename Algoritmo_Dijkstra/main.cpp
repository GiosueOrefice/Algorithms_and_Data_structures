#include <iostream>
#include <Graph.h>
#include <CodaMinPriority.h>
void Inizializza(Graph &G,Node *s);
void Relax(Arco *x);
void Dijkstra(Graph &G,Node *s);

using namespace std;

int main()
{
    Graph G;
    G.AddNode(new Node('s')); //0;
    G.AddNode(new Node('t')); //1;
    G.AddNode(new Node('y')); //2
    G.AddNode(new Node('x')); //3
    G.AddNode(new Node('z')); //4;

    G.AddArco(new Arco(G.GetNode(0),G.GetNode(1),10));
    G.AddArco(new Arco(G.GetNode(0),G.GetNode(2),5));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(2),2));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(3),1));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(1),3));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(3),9));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(4),2));
    G.AddArco(new Arco(G.GetNode(3),G.GetNode(4),4));
    G.AddArco(new Arco(G.GetNode(4),G.GetNode(3),6));
    G.AddArco(new Arco(G.GetNode(4),G.GetNode(0),7));

    G.PrintAdjGraph();
    cout<<endl;
    G.PrintArcoGraph();
    cout<<endl;
    Dijkstra(G,G.GetNode(0));
    for(auto v:*G.GetALLNode())
        cout<<v->GetData()<<"  "<<v->GetD()<<endl;
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

void Dijkstra(Graph &G,Node *s)
{
    Inizializza(G,s);
    CodaMinPriority Q(G.GetALLNode());
    Q.Build_MinHeap();
    Node *u;
    Arco *x;
    while(Q.GetHeapSize()!=1)
    {
        u=Q.Extract_Min();
        for(auto v:*u->GetAdj()){
            x=G.GetArco(u,v);
            //NON USO RELAX PERCHE' DEVO AGGIORNARE CODA DI MIN PRIORITY
            if(v->GetD()>u->GetD()+x->GetPeso()){
            Q.Decrementa_Key(v,x->GetPeso()+u->GetD());
            v->SetParent(u);
            }
        }

    }
}
