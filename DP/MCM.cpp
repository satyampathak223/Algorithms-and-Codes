#include <iostream>
#include <cstring>
#include<climits>
using namespace std;

int MATRIX_CHAIN_MULTIPLY(int arr[],int dp[][101],int i,int j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=MATRIX_CHAIN_MULTIPLY(arr,dp,i,k)+MATRIX_CHAIN_MULTIPLY(arr,dp,k+1,j)+arr[i-1]*arr[k]*arr[j];
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}

int main()
{
	int dp[101][101];
    memset(dp,-1,sizeof(dp));
    cout<<"Enter the number of matrices to multiply: ";
    int n;
    cin>>n;
    cout<<"Enter the dimensions of matrices: ";
    int arr[n],i,j;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Optimal Cost of parenthesization is : "<<MATRIX_CHAIN_MULTIPLY(arr,dp,1,n-1);
}
