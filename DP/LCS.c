#include <stdio.h>
#include<string.h>
#include<math.h>
#define MAX 5000

int dp[MAX+1][MAX+1];

int LCS(char a[],char b[],int n,int m)
{
    if(n==0||m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(a[n-1]==b[m-1])
        return dp[n][m]=1+LCS(a,b,n-1,m-1);
    else
        return dp[n][m]=fmax(LCS(a,b,n-1,m),LCS(a,b,n,m-1));

}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n,m;
	printf("Enter the length of first string: ");
	scanf("%d",&n);
	char a[n];
	printf("Enter the first string: ");
	scanf("%s",&a);
	printf("Enter the length of second string: ");
	scanf("%d",&m);
	char b[m];
	printf("Enter the second string: ");
	scanf("%s",&b);
	printf("\n\nLength of longest common subsequence is %d\n",LCS(a,b,n,m));
}
