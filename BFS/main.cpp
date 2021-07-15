#include <iostream>
#include <Graph.h>
using namespace std;

int main()
{
     Graph G;

    G.AddNode(new Node('s')); //0
    G.AddNode(new Node('r')); //1
    G.AddNode(new Node('v')); //2
    G.AddNode(new Node('w')); //3
    G.AddNode(new Node('t')); //4
    G.AddNode(new Node('x')); //5
    G.AddNode(new Node('u')); //6
    G.AddNode(new Node('y')); //7
    G.GetNode(0)->AddEdge(G.GetNode(1));
    G.GetNode(0)->AddEdge(G.GetNode(3));
    G.GetNode(1)->AddEdge(G.GetNode(0));
    G.GetNode(1)->AddEdge(G.GetNode(2));
    G.GetNode(2)->AddEdge(G.GetNode(1));
    G.GetNode(3)->AddEdge(G.GetNode(0));
    G.GetNode(3)->AddEdge(G.GetNode(4));
    G.GetNode(3)->AddEdge(G.GetNode(5));
    G.GetNode(4)->AddEdge(G.GetNode(3));
    G.GetNode(4)->AddEdge(G.GetNode(5));
    G.GetNode(4)->AddEdge(G.GetNode(6));
    G.GetNode(5)->AddEdge(G.GetNode(4));
    G.GetNode(5)->AddEdge(G.GetNode(3));
    G.GetNode(5)->AddEdge(G.GetNode(6));
    G.GetNode(5)->AddEdge(G.GetNode(7));
    G.GetNode(6)->AddEdge(G.GetNode(7));
    G.GetNode(6)->AddEdge(G.GetNode(5));
    G.GetNode(6)->AddEdge(G.GetNode(4));
    G.GetNode(7)->AddEdge(G.GetNode(6));
    G.GetNode(7)->AddEdge(G.GetNode(5));
    cout<<"LISTA ADIACENZA PRIMO GRAFO"<<endl;
    G.PrintAdjGraph();
    G.BFS(G.GetNode(0));
    cout<<"BFS"<<endl;
    cout<<"N d Parent"<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<G.GetNode(i)->GetData()<<" ";
        cout<<G.GetNode(i)->GetD()<<" ";
        if(G.GetNode(i)->GetParent()==nullptr)
        cout<<G.GetNode(i)->GetParent()<<endl;
        else cout<<G.GetNode(i)->GetParent()->GetData()<<endl;
    }
    return 0;
}
