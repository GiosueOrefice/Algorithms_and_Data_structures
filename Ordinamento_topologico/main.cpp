#include <iostream>
#include <Graph.h>
#include <list>
using namespace std;
void Ordinamento_Topologico(Graph &G,list<Node*> *Lista);
int main()
{
   Graph g;
    g.AddNode(new Node("camicia")); //0
    g.AddNode(new Node("cravatta")); //1
    g.AddNode(new Node("giacca")); //2
    g.AddNode(new Node("cintura")); //3
    g.AddNode(new Node("orologio")); //4
    g.AddNode(new Node("pantaloni")); //5
    g.AddNode(new Node("mutande")); //6
    g.AddNode(new Node("calze")); //7
    g.AddNode(new Node("scarpe")); //8


    g.GetNode(0)->AddEdge(g.GetNode(1));
    g.GetNode(0)->AddEdge(g.GetNode(3));
    g.GetNode(1)->AddEdge(g.GetNode(2));
    g.GetNode(3)->AddEdge(g.GetNode(2));

    g.GetNode(5)->AddEdge(g.GetNode(3));
    g.GetNode(5)->AddEdge(g.GetNode(8));
    g.GetNode(6)->AddEdge(g.GetNode(5));
    g.GetNode(6)->AddEdge(g.GetNode(8));
    g.GetNode(7)->AddEdge(g.GetNode(8));

    list<Node *> *L=new list<Node *>;
    Ordinamento_Topologico(g,L);

    for(int i=0;i<9;i++)
        cout<<g.GetNode(i)->GetData()<<" "<<g.GetNode(i)->GetD()<<"  "<<g.GetNode(i)->GetF()<<endl;

    cout<<endl<<"ORDINAMENTO TOPOLOGICO"<<endl;
    for(auto l:*L)
        cout<<l->GetData()<<"   ";
    cout<<endl;

    return 0;
}

void Ordinamento_Topologico(Graph &G,list <Node *> *Lista)
{
    G.DFS(Lista);
}
