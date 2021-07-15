#include <iostream>

using namespace std;
int Autonomia_Greedy(int *stazioni,int N,int autonomia,int n);
int main()
{
    int n=7;
    int stazioni[n]={5,16,27,30,48,60,80};
    int N=100;
    int autonomia=20;
    int cont=Autonomia_Greedy(stazioni,N,autonomia,n);
    cout<<"TOTALE STAZIONI: "<<cont;
    return 0;
}

int Autonomia_Greedy(int *stazioni,int N,int autonomia,int n)
{
    short i=1;
    int distanza=0;
    int cont=0;
    while(i<n && distanza<N){
        if(distanza+autonomia<=stazioni[i])
       {
            cont++;
            distanza=stazioni[i-1];
            cout<<stazioni[i-1]<<endl;
        }
        i++;
    }
    i--;

    if(distanza+autonomia<=stazioni[i] && distanza<N)
    {
        cont++;
        distanza=stazioni[i];
            cout<<stazioni[i]<<endl;
    }
    cout<<endl;
    return cont;
}
