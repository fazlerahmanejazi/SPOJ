#include <bits/stdc++.h>
using namespace std ;

#define mod 100

int main()
  {
    int n, x;
    while(cin>>n)
      {
        vector<vector<int>> mix(n+1, vector<int>(n+1)), dp(n+1, vector<int>(n+1)) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> mix[i][i] ;
            dp[i][i]=0 ;
          }
        for(int i=1 ; i<n ; i++)
          for(int j=0 ; j<n-i ; j++)
            {
              dp[j][j+i]=INT_MAX ;
              for(int k=j ; k<j+i ; k++)
                {
                  x=mix[j][k]*mix[k+1][j+i]+dp[j][k]+dp[k+1][j+i] ;
                  if(x<dp[j][j+i])
                    {
                      dp[j][j+i]=x ;
                      mix[j][j+i]=(mix[j][k]+mix[k+1][j+i])%mod ;
                    }
                }
            }
        cout<< dp[0][n-1] << endl ;
      }
  }
