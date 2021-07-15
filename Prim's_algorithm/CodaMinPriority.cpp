#include "CodaMinPriority.h"
CodaMinPriority::CodaMinPriority(vector <Node *> *V)
{
    Q.push_back(new Node('-1'));
    for(auto v:*V)
        Q.push_back(v);
    this->HeapSize=0;
}
int CodaMinPriority::GetHeapSize()
{
    return this->HeapSize;
}

void CodaMinPriority::SetHeapSize(int heapsize)
{
    this->HeapSize=heapsize;
}

void CodaMinPriority::Build_MinHeap (){
    SetHeapSize(Q.size());
    short i;
    for(i=((Q.size())/2);i>0;i--)
        MinHeapify(i);
}

void CodaMinPriority::MinHeapify (int i)
{
    short l,r;
    int minimo;
    l=2*i;
    r=2*i+1;
    if(l<GetHeapSize() && Q[l]->GetKey()<Q[i]->GetKey())
        minimo=l;
    else minimo=i;
    if(r<GetHeapSize() && Q[r]->GetKey()<Q[minimo]->GetKey())
        minimo=r;
    if(minimo!=i){
        swap(Q[i],Q[minimo]);
        MinHeapify(minimo);}

}

Node* CodaMinPriority::Extract_Min()
 {

     if(GetHeapSize()<1)
        cout<<"HEAPSIZE MINORE DI 1"<<endl;
     else {
        Node *minimo=Q[1];
        swap(Q[1],Q[GetHeapSize()-1]);
        SetHeapSize(GetHeapSize()-1);
        MinHeapify(1);
        return minimo;
     }
 }

 void CodaMinPriority::Decrementa_Key (Node *v,int key)
 {
     int pos=1;
    while(Q[pos]!=v && pos<GetHeapSize())
    {
        pos++;
    }
    if(key>Q[pos]->GetKey())
        cout<<"LA CHIAVE E' MAGGIORE DEL VALORE DA AGGIORNARE"<<endl;
     else {
        Q[pos]->SetKey(key);
        while(pos>1 && Q[pos/2]->GetKey()>Q[pos]->GetKey())
        {
            swap(Q[pos],Q[pos/2]);
            pos=pos/2;
        }
     }
 }

 bool CodaMinPriority::Search(Node *u)
 {
     for(int i=1;i<GetHeapSize();i++)
     {
         if (Q[i]==u)
            return true;
     }
     return false;
 }



