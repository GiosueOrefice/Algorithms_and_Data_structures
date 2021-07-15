#include <iostream>
#include <Graph.h>
using namespace std;

int main()
{
   Graph g;
    g.AddNode(new Node('u')); //0
    g.AddNode(new Node('v')); //1
    g.AddNode(new Node('y')); //2
    g.AddNode(new Node('x')); //3
    g.AddNode(new Node('w')); //4
    g.AddNode(new Node('z')); //5

    g.GetNode(5)->AddEdge(g.GetNode(5));
    g.GetNode(0)->AddEdge(g.GetNode(1));
    g.GetNode(0)->AddEdge(g.GetNode(3));
    g.GetNode(1)->AddEdge(g.GetNode(2));
    g.GetNode(3)->AddEdge(g.GetNode(1));
    g.GetNode(2)->AddEdge(g.GetNode(3));
    g.GetNode(4)->AddEdge(g.GetNode(2));
    g.GetNode(4)->AddEdge(g.GetNode(5));
    cout<<"LISTA ADIACENZA SECONDO GRAFO"<<endl;
    g.PrintAdjGraph();
    g.DFS();
    cout<<endl<<"DFS"<<endl;
    cout<<"N d f  Parent"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<g.GetNode(i)->GetData()<<" ";
        cout<<g.GetNode(i)->GetD()<<" ";
        cout<<g.GetNode(i)->GetF()<<"   ";

        if(g.GetNode(i)->GetParent()==nullptr)
        cout<<g.GetNode(i)->GetParent()<<endl;
        else cout<<g.GetNode(i)->GetParent()->GetData()<<endl;
    }


    return 0;
}
