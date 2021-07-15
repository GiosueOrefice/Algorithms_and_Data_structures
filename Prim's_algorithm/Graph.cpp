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
    x->GetV()->AddEdge(x->GetU());
}

Arco* Graph::GetArco(Node *u,Node *v)
{

    for(auto e:*E)
    {
        if(e->GetU()==u && e->GetV()==v)
            return e;
        if(e->GetU()==v && e->GetV()==u)
            return new Arco(e->GetV(),e->GetU(),e->GetPeso());
    }
}

void Graph::PrintArcoGraph()
{
    for(auto e:*E){
        e->PrintArco();
        cout<<endl;
    }
}

void Graph::Prim(Node *r)
{
    int tot=0;
    for(auto v:*V)
    {
        v->SetKey(999);
        v->SetParent(nullptr);
    }
    r->SetKey(0);

    CodaMinPriority Q(V);
    Q.Build_MinHeap();

   Node *u;
   Arco *x;
   while(Q.GetHeapSize()>1)
   {
    u=Q.Extract_Min();
   for(auto v:*u->GetAdj())
   {
       x=GetArco(u,v);

      if(Q.Search(v)==true  && x->GetPeso()<v->GetKey())
      {
          v->SetParent(u);
          Q.Decrementa_Key(v,x->GetPeso());
      }

   }
   if(u->GetParent()!=nullptr){
        GetArco(u->GetParent(),u)->PrintArco();
        tot=GetArco(u->GetParent(),u)->GetPeso()+tot;
        cout<<endl;
   }

   }

   cout<<tot<<endl;

}

