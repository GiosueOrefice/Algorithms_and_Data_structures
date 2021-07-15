#include <iostream>

using namespace std;
#define n 11
int Greedy_Activity_Selector(int *s,int *f,int *sol);
void stampa_matrice(int *p);
int main()
{
    int s[n]={1,3,0,5,3,5,6,8,8,2,12},f[n]={4,5,6,7,9,9,10,11,12,14,16};
    int sol[n];
    int l_sol;
    int DP[n+1][n+1];
    short i,j;

   l_sol=Greedy_Activity_Selector(s,f,sol);
    cout<<"Gli intervalli da prendere sono:"<<endl;
    for(i=0;i<l_sol;i++)
        cout<<sol[i]<<"  ";
    return 0;
}

int Greedy_Activity_Selector(int *s,int *f,int *sol)
{
    //se non sono ordinati bisogna ordinare per tempo di fine
    short i=0;
    sol[i]=0;
    int cont=1;
    short k,m;
    k=0;
    for(m=1;m<11;m++)
    {
        if(s[m]>=f[k]){
            sol[++i]=m;
            k=m; cont++;
        }
    }
    return cont;
}

void stampa_matrice(int *p)
{
    short i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            cout<<*(p+i*(n+1)+j)<<"   ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
