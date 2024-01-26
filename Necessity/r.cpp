#include<bits/stdc++.h>
using namespace std;

int coinchange(int coin[],int n,int w)
{
   int cc[n][w];
   int p;
   for(int i=0;i<=n;i++)
   {
       cc[i][0]=1;
   }
   for(int j=1;j<=w;j++)
   {
       cc[0][j]=0;
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=w;j++)
       {
           if(coin[i]>j)
           {
               cc[i][j]=cc[i-1][j];
           }
           else
           {
              p=coin[i];
              cc[i][j]=cc[i-1]+cc[i][j-p];
           }
       }
   }
}
int main()
{
    int n,w;
    int coin[100];
    cout<<"How many coin you want to store ";
    cin>>n;
    cout<<"what is the amount  ";
    cin>>w;
    cout<<"write the coin values ";
    for(int i=0;i<=n;i++)
    {
        if(i==0)  coin[0]=0;
        else cin>>coin[i];
    }
    int result=coinchange(coin,n,w);
        cout << result;
}