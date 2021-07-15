#include <iostream>

using namespace std;
#define size 11
void HeapSort (int *a);
void Build_MaxHeap (int *a);
void MaxHeapify (int *a,int i,int heapsize);
void swappo(int &a,int &b);
int Heap_Max(int *a);
void Heap_Extract_Max(int *a,int heapsize);
void Heap_Increase_Key (int *a,int i,int key);
void Heap_Insert(int *a,int key,int heapsize);
int main()
{
    int a[size]={' ',16,14,10,8,7,9,3,2,4,1},heapsize=size-1;
    for(short j=1;j<size;j++)
        cout<<a[j]<<" ";
        cout<<endl;
    HeapSort(a);
    short i;
    for(i=1;i<size;i++)
        cout<<a[i]<<" ";

    cout<<endl<<endl;

    int b[size]={' ',2,1,4,3,6,5,8,7,0,9};
    cout<<"NUOVO ARRAY"<<endl;
    for(short j=1;j<size;j++)
            cout<<b[j]<<" ";
    cout<<endl<<"BUIL_MAX_HEAP"<<endl;
    Build_MaxHeap(b);
        for(short j=1;j<size;j++)
            cout<<b[j]<<" ";
        cout<<endl;

    cout<<"Il valore massimo è: "<<Heap_Max(b)<<endl;
    Heap_Extract_Max(b,heapsize);
    cout<<"Nuovo heap dopo estrazione MAX"<<endl;
    for(short j=1;j<size-1;j++)
    cout<<b[j]<<" ";
    cout<<endl;
    cout<<"Incremeto il valore dell'indice 3 (20)"<<endl;
    Heap_Increase_Key(b,3,20);
    for(short j=1;j<size-1;j++)
    cout<<b[j]<<" ";
    cout<<endl;
    cout<<"Inserimento di un nuovo valore (50)"<<endl;
    Heap_Insert(b,50,heapsize+1);
    for(short j=1;j<size;j++)
    cout<<b[j]<<" ";
    cout<<endl;

        return 0;
}

void HeapSort (int *a)
{
    Build_MaxHeap(a);
    short i;
    int heapsize=size;
    for(i=size-1;i>1;i--){
        swap(a[1],a[i]);
        heapsize--;
        MaxHeapify(a,1,heapsize);
    }
}

void Build_MaxHeap (int *a)
{
    short i,j;
    for(i=(size/2);i>0;i--)
        MaxHeapify(a,i,size);

    }

void MaxHeapify (int *a,int i,int heapsize)
{
    short l,r;
    int massimo;
    l=2*i;
    r=2*i+1;
    if(l<heapsize && a[l]>a[i])
        massimo=l;
    else massimo=i;
    if(r<heapsize && a[r]>a[massimo])
        massimo=r;
    if(massimo!=i){
        swappo(a[i],a[massimo]);
        MaxHeapify(a,massimo,heapsize);}

}

 void swappo(int &a,int &b)
 {
     int c=a;
     a=b;
     b=c;
 }

 int Heap_Max(int *a)
 {
     return a[1];
 }

 void Heap_Extract_Max(int *a,int heapsize)
 {

     if(heapsize<1)
        cout<<"HEAPSIZE MINORE DI 1"<<endl;
     else {
        a[1]=a[heapsize];
        heapsize--;
        MaxHeapify(a,1,heapsize);
     }
 }

 void Heap_Increase_Key (int *a,int i,int key)
 {
     if(key<a[i])
        cout<<"LA CHIAVE E' MINORE DEL VALORE DA AGGIORNARE"<<endl;
     else {
        a[i]=key;
        while(i>1 && a[i/2]<a[i])
        {
            swap(a[i],a[i/2]);
            i=i/2;
        }
     }
 }

 void Heap_Insert(int *a,int key,int heapsize)
 {
     heapsize=heapsize+1;
     a[heapsize]=INT_MIN;
     Heap_Increase_Key(a,heapsize,key);
 }
