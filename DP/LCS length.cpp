#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string a,b,s="";
    cout<<"Enter the first string : ";
    cin>>a;
    cout<<"Enter the second string : ";
    cin>>b;
    int n=a.length(),m=b.length(),dp[n+1][m+1],i,j,k=0;
    memset(dp,0,sizeof(dp));

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"The table for Longest common subsequence is \n\n";

    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=m;j++)
    	{
    		cout<<"  "<<dp[i][j]<<"  ";
    	}
    	cout<<"\n";
    }
}
