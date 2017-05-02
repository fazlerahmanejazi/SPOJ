#include <bits/stdc++.h>
using namespace std ;

int n, u, m, res, x, y, curr ;
vector<bool> visit ;
vector<int> seq, ans, temp ;

void dfs(int t)
  {
    visit[t]=true ;
    ans.push_back(t) ;
    if(!visit[seq[t]])
       dfs(seq[t]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    for(int tc=1 ; ; tc++)
    {
      cin>> n ;
      if(!n) break ;
      map<int, int> idx, val ;
      visit.assign(n+1, false) ;
      seq.clear() ;
      temp.clear() ;
      seq.resize(n+1) ;
      temp.resize(n+1) ;
      for(int i=1 ; i<=n ; i++)
        {
          cin>> u ;
          seq[i]=temp[i]=u ;
        }
      sort(temp.begin()+1, temp.end()) ;
      m=temp[1] ;
      res=0 ;
      for(int i=1 ; i<=n ; i++)
        {
          idx[temp[i]]=i ;
          val[i]=temp[i] ;
        }
      for(int i=1 ; i<=n ; i++)
        seq[i]=idx[seq[i]] ;
      for(int i=1 ; i<=n ; i++)
        {
          ans.clear() ;
          if(!visit[i])
            dfs(i) ;
          if(!ans.empty())
            {
              sort(ans.begin(), ans.end()) ;
              curr=min(val[ans[0]]*(ans.size()-1), 2*(val[ans[0]]+m)+m*(ans.size()-1)) ;
              for(int i=1 ; i<ans.size() ; i++)
                curr+=val[ans[i]] ;
              res+=curr ;
            }
        }
      cout<< "Case " << tc << ": " << res << endl ;
      cout<< endl ;
    }
  }
