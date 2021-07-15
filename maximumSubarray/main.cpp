#include <iostream>

using namespace std;
int maxsottoarray(int *a,int inizio,int fine);
int somma_Da_med (int *a,int inizio,int med,int fine);
int main()
{
    int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int inizio=0,fine=15,i;
    for(i=0;i<16;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"MAX SOTTOARRAY:"<<maxsottoarray(a,inizio,fine)<<endl;


    return 0;
}

int maxsottoarray(int *a,int inizio,int fine)
{
    int med,leftsum,rightsum,crosssum;
    if(inizio==fine) return a[inizio];
    else {
        med=(inizio+fine)/2;
        leftsum=maxsottoarray(a,inizio,med);
        rightsum=maxsottoarray(a,med+1,fine);
        crosssum=somma_Da_med(a,inizio,med,fine);
        if(leftsum>rightsum && leftsum>crosssum)
            return leftsum;
        else if (rightsum>leftsum && rightsum>crosssum)
            return rightsum;
        else return crosssum;

    }
}

int somma_Da_med (int *a,int inizio,int med,int fine)
{
    int leftsum=INT_MIN,right_sum=INT_MIN,sum=0;
    short i;
    for(i=med;i>=inizio;i--)
    {
        sum=sum+a[i];
        if(sum>leftsum) leftsum=sum;
    }
    sum=0;
    for(i=med+1;i<=fine;i++){
        sum=sum+a[i];
    if(sum>right_sum) right_sum=sum;}
    return (leftsum+right_sum);
}
