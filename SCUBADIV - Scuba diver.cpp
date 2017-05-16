#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f

int main()
  {
    int T, O, N, zero, one, n ;
    cin>> T ;
    while(T--)
      {
        cin>> O >> N ;
        cin>> n ;
        int dp[n+1][O+1][N+1] ;
        vector<int> oxy(n+1), nit(n+1), weight(n+1) ;
        for(int i=1 ; i<=n ; i++)
          cin>> oxy[i] >> nit[i] >> weight[i] ;
        for(int i=0 ; i<=O ; i++)
          for(int j=0 ; j<=N ; j++)
            if(i<=oxy[1] && j<=nit[1]) dp[1][i][j]=weight[1] ;
            else dp[1][i][j]=inf ;
        dp[1][0][0]=0 ;
        for(int k=2 ; k<=n ; k++)
          for(int i=0 ; i<=O ; i++)
            for(int j=0 ; j<=N ; j++)
              {
                zero=dp[k-1][i][j] ;
                one=dp[k-1][max(i-oxy[k], 0)][max(j-nit[k], 0)]+weight[k] ;
                dp[k][i][j]=min(zero, one) ;
              }
        cout<< dp[n][O][N] << endl ;
      }
  }
