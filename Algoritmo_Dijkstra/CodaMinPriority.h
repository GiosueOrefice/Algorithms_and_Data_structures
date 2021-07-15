#ifndef CODAMINPRIORITY_H
#define CODAMINPRIORITY_H
#include <vector>
#include <Node.h>
#include <iostream>
using namespace std;

class CodaMinPriority
{
    private:

        vector<Node *> Q;
        int HeapSize;

    public:

        CodaMinPriority(vector <Node *> *V);
        int GetHeapSize();
        void SetHeapSize(int heapsize);
        int Getsize(){return Q.size();}
        Node* GetNode(int i){return Q[i];}
        void Build_MinHeap ();
        void MinHeapify (int i);
        Node* Heap_Min(){return Q[1];}
        Node* Extract_Min();
        void Decrementa_Key (Node *v,int key);
        bool Search(Node *u);
};


#endif // CODAMINPRIORITY_H
