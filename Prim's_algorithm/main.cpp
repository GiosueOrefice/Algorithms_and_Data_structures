#include <iostream>
#include <Graph.h>
using namespace std;

int main()
{
    Graph G;
    G.AddNode(new Node('a')); //0
    G.AddNode(new Node('b')); //1
    G.AddNode(new Node('c')); //2
    G.AddNode(new Node('d')); //3
    G.AddNode(new Node('e')); //4
    G.AddNode(new Node('f')); //5
    G.AddNode(new Node('g')); //6
    G.AddNode(new Node('h')); //7
    G.AddNode(new Node('i')); //8


    G.AddArco(new Arco(G.GetNode(0),G.GetNode(1),4));
    G.AddArco(new Arco(G.GetNode(0),G.GetNode(7),8));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(7),11));
    G.AddArco(new Arco(G.GetNode(1),G.GetNode(2),8));
    G.AddArco(new Arco(G.GetNode(7),G.GetNode(8),7));
    G.AddArco(new Arco(G.GetNode(7),G.GetNode(6),1));
    G.AddArco(new Arco(G.GetNode(8),G.GetNode(6),6));
    G.AddArco(new Arco(G.GetNode(8),G.GetNode(2),2));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(3),7));
    G.AddArco(new Arco(G.GetNode(2),G.GetNode(5),4));
    G.AddArco(new Arco(G.GetNode(6),G.GetNode(5),2));
    G.AddArco(new Arco(G.GetNode(5),G.GetNode(3),14));
    G.AddArco(new Arco(G.GetNode(5),G.GetNode(4),10));
    G.AddArco(new Arco(G.GetNode(4),G.GetNode(3),9));
    G.Prim(G.GetNode(0));


    return 0;
}
