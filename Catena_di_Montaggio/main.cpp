#include <iostream>

using namespace std;
void catena_di_montaggio(int *e,int *x,int *s1,int *t1,int *t2,int *s2);
int main()
{
    int e[2]={2,4};
    int x[2]={3,2};
    int s1[6]={7,9,3,4,8,4},s2[6]={8,5,6,4,5,7};
    int t1[5]={2,3,1,1,4},t2[5]={2,1,2,2,1};
    catena_di_montaggio(e,x,s1,t1,t2,s2);
    return 0;
}

void catena_di_montaggio(int *e,int *x,int *s1,int *t1,int *t2,int *s2)
{
    int sol1[7];sol1[0]=e[0]+s1[0];
    int sol2[7];sol2[0]=e[1]+s2[0];
    cout<<min(sol1[0],sol2[0])<<" ";
    for(int i=1;i<6;i++){
        sol1[i]=min(sol1[i-1]+s1[i],sol2[i-1]+t2[i-1]+s1[i]);
        sol2[i]=min(sol2[i-1]+s2[i],sol1[i-1]+t1[i-1]+s2[i]);
        cout<<min(sol1[i],sol2[i])<<" ";
    }
    sol1[6]=sol1[5]+x[0];
    sol2[6]=sol2[5]+x[1];
    cout<<endl<<"Soluzione ottima: ";
    if(sol1[6]>=sol2[6])
        cout<<sol2[6]<<endl;
        else cout<<sol1[6]<<endl;

}
