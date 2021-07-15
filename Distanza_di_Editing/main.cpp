#include <iostream>
#include <string>
using namespace std;
void stampa(int *a,int n,int m);
void Distanza_Editing(string s,string t,int n,int m,int *soluzione,char *frecce);
int minimo(int a,int b,int c);
void stampa(char *a,int n,int m);

int main()
{
    string s="TGCATA",t="ATCTGAT";
    int n=s.length()+1;
    int m=t.length()+1;
    int soluzione[m][n];
    char frecce[m][n];
    Distanza_Editing(s,t,n,m,*soluzione,*frecce);
    stampa(*soluzione,n,m);
    stampa(*frecce,n,m);
    return 0;
}

void Distanza_Editing(string s,string t,int n,int m,int *soluzione,char *frecce)
{
    short i,j;
    int q;

    for(i=0;i<m;i++){
        *(soluzione+i*n)=i;
        if(i!=0)*(frecce+i*n)='|';
    }

    for(j=0;j<n;j++){
        *(soluzione+0*n+j)=j;
        if(j!=0)*(frecce+j)='-';
        else *(frecce+j)='0';
    }

    for(i=1;i<m;i++){
        for(j=1;j<n;j++)
        {
            if(t[i-1]==s[j-1]){
                *(soluzione+i*n+j)=*(soluzione+(i-1)*n+j-1);
                *(frecce+i*n+j)='/';
            }

            else {
                q=minimo(*(soluzione+(i-1)*n+j),*(soluzione+(i-1)*n+j-1),*(soluzione+i*n+j-1));
                *(soluzione+i*n+j)=q+1;

                 if(q==*(soluzione+(i-1)*n+j-1)) *(frecce+i*n+j)='/';
                else if(q==*(soluzione+(i-1)*n+j)) *(frecce+i*n+j)='|';
                else *(frecce+i*n+j)='-';
            }
        }
    }

}

void stampa(int *a,int n,int m)
{
    short i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<*(a+i*n+j)<<"    ";
        } cout<<endl;
    }
    cout<<endl<<endl;
}
void stampa(char *a,int n,int m)
{
    short i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<*(a+i*n+j)<<"    ";
        } cout<<endl;
    }
    cout<<endl<<endl;
}

int minimo(int a,int b,int c){
if(a>=b && c>=b)
    return b;
    else if(a<=b && a<=c)
        return a;
    else return c;
}
