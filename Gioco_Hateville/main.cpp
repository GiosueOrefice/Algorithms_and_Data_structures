#include <iostream>

using namespace std;
#define n 4
int Heatville(int *p);
int Risolve(int *p,int *R);

int main()
{
    int Persone[n]={10,12,23,40};
    int maxs,i;
    for(i=0;i<n;i++)
        cout<<Persone[i]<<" ";
    maxs=Heatville(Persone);
    cout<<endl<<maxs<<endl;

    return 0;
}

int Heatville(int *p)
{
    short i;
    int R[n+1];
    for(i=0;i<=n;i++)
        R[i]=0;
    int ris=Risolve(p,R);


}

int Risolve(int *p,int *R)
{
    short i=0;
    short j=i+1;

    R[j]=p[i];
    i++; j++;

        for(i=1;i<n;i++){
        R[j]=max(R[j-1],R[j-2]+p[i]);
        j++;
        }
    return R[n];
}


