#include <bits/stdc++.h>
using namespace std ;

int n, m, u, v ;
vector<vector<int>> adj ;
vector<bool> visit ;
bitset<1010> mask[1010] ;

void dfs(int v)
  {
    int to ;
    visit[v]=true ;
    for(int i=0 ; i<adj[v].size() ; i++)
      {
        to=adj[v][i] ;
        if(!visit[to]) dfs(to) ;
        mask[v] |= mask[to];
        mask[v].set(to);
      }
   }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        if(mask[v][u] || u==v) cout<< u << " " << v << endl ;
        else if(mask[u][v]) continue ;
        else
          {
            adj[u].push_back(v) ;
            visit.assign(n+1, false) ;
            for(int i=1 ; i<=n ; i++)
              if(!visit[i]) dfs(i) ;
          }
      }
    cout<< 0 << " " << 0 << endl ;
  }
