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

int n, m, k, l, r, x, mid ;
lli curr, val ;
vvi sector, test ;
vlli tree ;
vi req ;
vpii range ;
vector<pair<pii, lli>> meteor ;
bool check ;

lli query(int i)
  {
    lli temp=0 ;
    for( ; i>0 ; i-=(i&-i))
      temp+=tree[i] ;
    return temp ;
  }

void update(int i, lli val)
  {
    for( ; i<=m ; i+=(i&-i))
      tree[i]+=val ;
  }

void rangeUpdate(int i)
  {
    l=meteor[i].fi.fi ; r=meteor[i].fi.se ; val=meteor[i].se ;
    update(l, val) ;
    update(r+1, -val) ;
    if(l>r) update(1, val) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    sector.resize(n+1) ;
    range.resize(n+1) ;
    req.resize(n+1) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> x ;
        sector[x].pb(i) ;
      }
    for(int i=1 ; i<=n ; i++)
      cin>> req[i] ;
    cin>> k ;
    meteor.resize(k+1) ;
    for(int i=1 ; i<=k ; i++)
      cin>> meteor[i].fi.fi >> meteor[i].fi.se >> meteor[i].se ;
    for(int i=1 ; i<=n ; i++)
      {
        range[i].fi=1 ;
        range[i].se=k+1 ;
      }
    while(1)
      {
        check=true ;
        tree.assign(m+1, 0) ;
        test.clear() ; test.resize(k+2) ;
        for(int i=1 ; i<=n ; i++)
          {
            mid=(range[i].fi+range[i].se)/2 ;
            if(range[i].fi!=range[i].se) test[mid].pb(i) ;
          }
        for(int i=1 ; i<=k ; i++)
          {
            rangeUpdate(i) ;
            for(int j=0 ; j<test[i].size() ; j++)
              {
                check=false ;
                x=test[i][j] ;
                curr=0 ;
                for(int l=0 ; l<sector[x].size() ; l++)
                  {
                    curr+=query(sector[x][l]) ;
                    if(curr>=req[x]) break ;
                  }
                if(curr>=req[x]) range[x].se=i ;
                else range[x].fi=i+1 ;
              }
          }
        if(check) break ;
      }
    for(int i=1 ; i<=n ; i++)
      if(range[i].fi<=k) cout<< range[i].fi << endl ;
      else cout<< "NIE" << endl ;
  }
