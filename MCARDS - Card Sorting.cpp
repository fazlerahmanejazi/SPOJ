#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    int c, n, x, y, cnt, res=INT_MAX, maxM=0 ;
    cin>> c >> n ;
    vector<pair<int, int>> card ;
    vector<int> color(c), correct(c*n), dp(c*n, 1) ;
    //vector<vector<int>> pos(c+1, vector<int>(n+1)) ;
    for(int i=0 ; i<c*n ; i++)
      {
        cin>> x >> y ;
        card.push_back(make_pair(x, y)) ;
      }
    for(int i=0 ; i<c ; i++)
      color[i]=i+1 ;
    while(1)
      {
        cnt=maxM=0 ;
        /*for(int i=0 ; i<c ; i++)
          for(int j=1 ; j<=n ; j++)
            pos[color[i]][j]=cnt++ ;
        for(int i=0 ; i<c*n ; i++)
          correct[i]=pos[card[i].first][card[i].second] ;*/
        for(int i=0 ; i<c*n ; i++)
          correct[i]=n*(color[card[i].first-1]-1)+(card[i].second-1) ;
        dp.assign(c*n, 1) ;
        for(int i=0 ; i<c*n ; i++)
          {
            for(int j=0 ; j<i ; j++)
              if(correct[i]>correct[j])
                dp[i]=max(dp[i], dp[j]+1) ;
            maxM=max(maxM, dp[i]) ;
          }
        res=min(res, c*n-maxM) ;
        if(!next_permutation(color.begin(), color.end())) break ;
      }
    cout<< res ;
  }
