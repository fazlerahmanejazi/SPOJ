#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
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

int n, q, x, l, r, k, pos, idx ;
vpii a ;
vector<tuple<int, int, int, int>> query ;
vi tree, res ;

lli sum(int i)
  {
    lli temp=0 ;
    for( ; i>=0 ; i=(i&(i+1))-1)
      temp+=tree[i] ;
    return temp ;
  }

void update(int i, int val)
  {
    for( ; i<n ; i=(i|(i+1)))
      tree[i]+=val ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    tree.assign(n, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.pb(mp(x, i)) ;
      }
    cin>> q ;
    res.resize(q) ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> l >> r >> k ;
        query.pb(mt(k, l-1, r-1, i)) ;
      }
    sort(all(query)) ; reverse(all(query)) ;
    sort(all(a)) ; reverse(all(a)) ;
    for(int i=0 ; i<q ; i++)
      {
        tie(k, l, r, idx)=query[i] ;
        while(pos<n && a[pos].fi>k)
          update(a[pos++].se, 1) ;
        res[idx]=sum(r) ;
        if(l) res[idx]-=sum(l-1) ;
      }
    for(int i=0 ; i<q ; i++)
      cout<< res[i] << endl ;
  }
