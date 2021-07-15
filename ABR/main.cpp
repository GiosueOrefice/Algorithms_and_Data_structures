#include <iostream>
#include "ABR.h"
using namespace std;

int main()
{

    ABR x;
    x.TREE_INSERT(new Node(new Data(15)));
    x.TREE_INSERT(new Node(new Data(6)));
    x.TREE_INSERT(new Node(new Data(18)));
    x.TREE_INSERT(new Node(new Data(3)));
    x.TREE_INSERT(new Node(new Data(7)));
    x.TREE_INSERT(new Node(new Data(17)));
    x.TREE_INSERT(new Node(new Data(20)));
    x.TREE_INSERT(new Node(new Data(2)));
    x.TREE_INSERT(new Node(new Data(4)));
    x.TREE_INSERT(new Node(new Data(13)));
    x.TREE_INSERT(new Node(new Data(9)));
    x.stampa(x.Getradice());
    cout<<endl;
    cout<<"IL MASSIMO: "<<x.Massimo(x.Getradice())->GetVal()->GetNum()<<endl;
    cout<<"IL MINIMO: "<<x.Minimo(x.Getradice())->GetVal()->GetNum()<<endl;
    cout<<endl;
    cout<<"IL Numero 17: ";
    if(x.Search(Data(17)))
        cout<<"E' PRESENTE"<<endl;
    else cout<<"NON E' PRESENTE"<<endl;

    cout<<"Il successore del nodo con val 15: "<<x.Successor(x.GetNode(Data(15)))->GetVal()->GetNum()<<endl;
    cout<<"Il successore del nodo con val 13: "<<x.Successor(x.GetNode(Data(13)))->GetVal()->GetNum()<<endl;

    cout<<endl;
    cout<<"Il predecessore del nodo con val 15: "<<x.Predecessor(x.GetNode(Data(15)))->GetVal()->GetNum()<<endl;
    cout<<"Il predecessore del nodo con val 6: "<<x.Predecessor(x.GetNode(Data(6)))->GetVal()->GetNum()<<endl;
    cout<<endl<<"ELIMINO IL NODO 18"<<endl;
    x.Delete(x.GetNode(18));
    x.stampa(x.Getradice());
    cout<<endl;
    return 0;
}

