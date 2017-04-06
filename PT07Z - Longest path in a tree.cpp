#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
int T, n, u, v, far, s, dia ;
vector<vector<int> > adj ;

void dfs(int u, int prev, int far)
  {
    if (far>dia)
      {
        dia=far ;
        s=u ;
      }
    for (int i=0 ; i<adj[u].size() ; i++)
      if(adj[u][i]!=prev)
        dfs(adj[u][i], u, far+1) ;
  }
int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> n ;
    adj.clear() ;
    adj.resize(n+1) ;
    dia=-inf ;
    for(int i=1 ; i<=n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
      }
    dfs(1, -1, 0) ;
    dfs(s, -1, 0) ;
    cout<< dia ;
    return 0 ;
  }
