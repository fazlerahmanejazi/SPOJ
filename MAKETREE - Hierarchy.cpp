#include <bits/stdc++.h>
using namespace std ;

int n, m, x, y, p ;
vector<vector<int> > adj ;
vector<int> parent, topo ;
bool visit[100010] ;
int parent[100010] ;

void topo_sort(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
      if(!visit[adj[t][i]])
        topo_sort(adj[t][i]) ;
    topo.push_back(t) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>>x ;
        for(int j=0 ; j<x ; j++)
          {
            cin>> y ;
            adj[i].push_back(y) ;
          }
      }
    for(int i=1 ; i<=n ; i++)
      if(!visit[i])
        topo_sort(i) ;
    p=0 ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        parent[topo[i]]=p ;
        p=topo[i] ;
      }
    for(int i=1 ; i<=n ; i++)
      cout<< parent[i] << endl ;
  }
