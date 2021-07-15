#include <iostream>

using namespace std;
#define n 3
void Zaino_Frazionario(float *p,float *w,float *x,int C);
int main()
{
    float p[n]={60,200,120},w[n]={10,40,30};
    float sol[n];
    int i,C=70;
    Zaino_Frazionario(p,w,sol,C);
    for(i=0;i<n;i++)
        cout<<sol[i]<<"  ";
    return 0;
}
void Zaino_Frazionario(float *p,float *w,float *x,int C)
{
    short i;
    for(i=0;i<n;i++)
    {

        if(w[i]<=C)
        x[i]=1;
        else x[i]=C/w[i];

        C=C-x[i]*w[i];
        x[i]=x[i]*w[i];
    }
}
