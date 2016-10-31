#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int a[1001][1001];
int d[1001][1001][3];
int dp[1001][1001];


int main()
{
   int N,M;

   scanf("%d %d\n",&N,&M);

   for(int j=1;j<=N;j++)
   {
      for(int i =1;i<=M;i++)
      {
         scanf("%d",&a[i][j]);
      }
   }

   dp[1][1] = a[1][1];
   for(int i=2;i<=M;i++)
   {
      dp[i][1] = dp[i-1][1]+a[i][1];
   }

   for(int j=2;j<N;j++)
   {
       
      d[1][j][1] = dp[1][j-1]+a[1][j];
      for(int i=2;i<=M;i++)
      {
         d[i][j][1] = max(d[i-1][j][1],dp[i][j-1])+a[i][j];
      }

      d[M][j][2] = dp[M][j-1]+a[M][j];
      dp[M][j]  = max(d[M][j][1],d[M][j][2]);
      for(int i=M-1;i>0;i--)
      {
         d[i][j][2] = max(dp[i][j-1],d[i+1][j][2])+ a[i][j];
         dp[i][j] = max(d[i][j][1],d[i][j][2]);
      }
   }

   dp[1][N] = dp[1][N-1]+a[1][N];
   for(int i=2;i<=M;i++)
   {
      dp[i][N] = max(dp[i][N-1], dp[i-1][N])+a[i][N];
   }

   printf("%d\n", dp[M][N]);

   return 0;
}
