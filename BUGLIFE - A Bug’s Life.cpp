#include <bits/stdc++.h>
using namespace std ;

int n, m, u, v, T ;
vector<vector<int>> adj ;
vector<int> gender ;
bool suspicious ;

void dfs(int t, int c)
  {
    if(suspicious) return ;
    gender[t]=c ;
    for(int i=0 ; i<adj[t].size() ; i++)
      {
        if(gender[adj[t][i]]==-1)
          dfs(adj[t][i], 1-c) ;
        else if(gender[t]==gender[adj[t][i]])
          {
            suspicious=true ;
            return ;
          }
      }
  }

int main()
  {
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m ;
        suspicious=false ;
        adj.clear() ;
        adj.resize(n+1) ;
        gender.assign(n+1, -1) ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
          }
        for(int i=1 ; i<=n ; i++)
          if(gender[i]==-1)
            dfs(i, 0) ;
        cout<< "Scenario #" << tc << ":" << endl ;
        if(suspicious) cout<< "Suspicious bugs found!" << endl ;
        else cout<< "No suspicious bugs found!" << endl ;
      }
  }
