#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, u, v ;
int dp[100000+10][2] ;
vvi adj ;

int cover(int x, int y, int prev)
  {
    int ans ;
    if(dp[x][y]!=-1) return dp[x][y] ;
    if(y==1)
      {
        ans=1 ;
        for(int i=0 ; i<adj[x].size() ; i++)
          if(adj[x][i]!=prev)
            ans+=min(cover(adj[x][i], 0, x), cover(adj[x][i], 1, x)) ;
        dp[x][y]=ans ;
        return ans ;
      }
    else
      {
        ans=0 ;
        for(int i=0 ; i<adj[x].size() ; i++)
          if(adj[x][i]!=prev)
            ans+=cover(adj[x][i], 1, x) ;
        dp[x][y]=ans ;
        return ans ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    memset(dp, -1, sizeof dp) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    cout<< min(cover(1, 0, -1), cover(1, 1, -1)) ;
  }
