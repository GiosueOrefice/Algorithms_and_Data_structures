#include <iostream>
#include <string>
using namespace std;
void LCS_LENGTH(string X,string Y,int m,int n,int *c,char *b);
void Print_LCS(char *b,string X,short i,short j,int n);
int main()
{
    string X="TACCBT";
    string Y="ATBCBD";
    int m=X.length(),n=Y.length();
    int c[m+1][n+1];
    char b[m+1][n+1];
    LCS_LENGTH(X,Y,m+1,n+1,*c,*b);
    short i,j;
    cout<<"       ";
    for(i=0;i<n;i++)
        cout<<Y[i]<<"    ";
    cout<<endl;
    for(i=0;i<=m;i++){
        if(i>0)cout<<X[i-1]<<" ";
        else cout<<"  ";
        for(j=0;j<=n;j++){
            cout<<c[i][j]<<"    ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"     ";
    for(i=0;i<n;i++)
        cout<<Y[i]<<"    ";
    cout<<endl;

    for(i=1;i<=m;i++){
            cout<<X[i-1];
        for(j=1;j<=n;j++){
            cout<<"    "<<b[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<"LCS: ";
    Print_LCS(*b,X,n,m,n+1);
    return 0;
}

void LCS_LENGTH(string X,string Y,int m,int n,int *c,char *b)
{
    short i,j;
    for(i=0;i<m;i++)
        *(c+i*n+0)=0;
    for(j=0;j<n;j++)
        *(c+j)=0;
    for(i=1;i<m;i++){
        for(j=1;j<n;j++)
        {
            if(X[i-1]==Y[j-1]){
                *(c+i*n+j)=*(c+(i-1)*n+(j-1))+1;
                *(b+i*n+j)='/';
            }
            else if(*(c+(i-1)*n+j)>=*(c+i*n+j-1)){
                *(c+i*n+j)=*(c+(i-1)*n+j);
                *(b+i*n+j)='|';
            }
            else {
                *(c+i*n+j)=*(c+i*n+j-1);
                *(b+i*n+j)='-';
            }
        }
    }


}

void Print_LCS(char *b,string X,short i,short j,int n)
{
    if(i!=0 && j!=0)
{
    if(*(b+i*n+j)=='/'){
        Print_LCS(b,X,i-1,j-1,n);
        cout<<X[i-1];
    }
    else if(*(b+i*n+j)=='|')
        Print_LCS(b,X,i-1,j,n);
    else
        Print_LCS(b,X,i,j-1,n);
}
}
