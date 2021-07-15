#include <iostream>

using namespace std;
#define n 4
#define C 9
void stampa(int *DP);
void knapsack(int *w,int *p,int *DP);
void FindKnapsack(int *DP,int *W,int *p);
int main()
{
    int w[4]={4,2,3,4},p[4]={10,7,8,6};
    int DP[n+1][C+1];
    short i;
    cout<<"CAPACITA' ZAINO: "<<C<<endl;
    cout<<"PESO"<<endl;
    for(i=0;i<n;i++)
        cout<<w[i]<<"  ";
    cout<<endl;
    cout<<"PROFITTO"<<endl;
    for(i=0;i<n;i++)
        cout<<p[i]<<"  ";
        cout<<endl<<endl;
    knapsack(w,p,*DP);
    stampa(*DP);
    FindKnapsack(*DP,w,p);
    return 0;
}

void knapsack(int *w,int *p,int *DP)
{
    short i,c;
    for(i=0;i<=n;i++)
        *(DP+i*(C+1))=0;
    for(c=0;c<=C;c++)
        *(DP+c)=0;
    for(i=1;i<=n;i++){
        for(c=1;c<=C;c++){
            if(w[i-1]<=c)
                *(DP+i*(C+1)+c)=max(*(DP+(i-1)*(C+1)+(c-w[i-1]))+p[i-1],*(DP+(i-1)*(C+1)+c));
            else *(DP+i*(C+1)+c)=*(DP+(i-1)*(C+1)+c);
        }
    }
}

void stampa(int *DP)
{
    short i,j;
    cout<<"    ";
    for(i=0;i<=C;i++)
        cout<<i<<"    ";
    cout<<endl;
    cout<<"_____________________________________________________________"<<endl;
    for(i=0;i<=n;i++){
            cout<<i<<"|"<<" ";
        for(j=0;j<=C;j++){
            cout<<*(DP+i*(C+1)+j)<<"    ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void FindKnapsack(int *DP,int *W,int *p)
{
    short i,k;
    i=n;
    k=C;
    while(i>=0 && k>=0){
        if(*(DP+i*(C+1)+k)!=*(DP+(i-1)*(C+1)+k)){
                cout<<i-1<<" ";
            k=k-W[i-1];}
        i--;
    }
}
