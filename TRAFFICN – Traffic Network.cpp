#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using pii = pair<int, int> ;
using vi = vector<int> ;

int n, m, k, s, t, u, v, T, d, ans ;
vector<vector<pii>> adj, adj_rev ;
vi ds, dt ;
pii temp ;

void dijkstra(int start, vi &dist, vector<vector<pii>> &adj)
  {
    priority_queue<pii , vector<pii> , greater<pii>> discovered ;
    discovered.push(mp(0, start)) ;
    dist[start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.top() ;
        discovered.pop() ;
        d=temp.ff ; u=temp.ss ;
        if(dist[u]<d) continue ;
        for(int i=0 ; i<adj[u].size() ; i++)
          {
            temp=adj[u][i] ;
            d=temp.ss ; v=temp.ff ;
            if(dist[u]+d < dist[v])
              {
                dist[v]=dist[u]+d  ;
                discovered.push(mp(dist[v], v)) ;
              }
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m >> k >> s >> t ;
        adj.clear() ; adj.resize(n+1) ;
        adj_rev.clear() ; adj_rev.resize(n+1) ;
        ds.assign(n+1, inf) ;
        dt.assign(n+1, inf) ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v >> d ;
            adj[u].pb(mp(v,d)) ;
            adj_rev[v].pb(mp(u,d)) ;
          }
        dijkstra(s, ds, adj) ;
        dijkstra(t, dt, adj_rev) ;
        ans=inf ;
        for(int i=0 ; i<k ; i++)
          {
            cin>> u >> v >> d ;
            ans=min(ds[t], min(ans, d+min(ds[u]+dt[v], ds[v]+dt[u]))) ;
          }
        if(ans==inf) cout<< -1 << endl ;
        else cout<< ans << endl ;
      }
  }
