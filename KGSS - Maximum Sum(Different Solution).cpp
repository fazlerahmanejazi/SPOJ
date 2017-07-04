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

int left (int p) { return p<<1 ; }
int right(int p) { return (p<<1)+1 ; }

int n, q, lq, rq, t, idx, val ;
char c ;
pii z ;
vi seq ;
vpii tree ;

pii merge(pii x, pii y)
  {
    vi a ;
    a.pb(x.fi) ; a.pb(x.se) ;
    a.pb(y.fi) ; a.pb(y.se) ;
    sort(all(a)) ;
    return mp(a[3], a[2]) ;
  }

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=mp(seq[l], -1) ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        pii x=tree[left(p)] ;
        pii y=tree[right(p)] ;
        tree[p]=merge(x, y) ;
      }
  }

pii query(int p, int l, int r, int lq, int rq)
  {
    if(lq>r || rq<l) return mp(-1, -1) ;
    if(lq<=l && rq>=r) return tree[p] ;
    pii x=query(left(p), l, (l+r)/2, lq, rq) ;
    pii y=query(right(p), (l+r)/2 + 1, r, lq, rq) ;
    return merge(x, y) ;
  }

void update(int p, int l, int r, int idx, int val)
  {
    if(idx<l || idx>r) return ;
    if(l==r)
      {
        tree[p]=mp(seq[l], -1) ;
        return ;
      }
    update(left(p), l, (l+r)/2, idx, val) ;
    update(right(p), (l+r)/2 +1, r, idx, val) ;
    pii x=tree[left(p)] ;
    pii y=tree[right(p)] ;
    tree[p]=merge(x, y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    z=mp(0, 0) ;
    tree.assign(4*n+1, z) ;
    seq.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      cin>> seq[i] ;
    build(1, 0, n-1) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> c ;
        if(c=='U')
          {
            cin>> idx >> val ;
            seq[idx-1]=val ;
            update(1, 0, n-1, idx-1, val) ;
          }
        else
          {
            cin>> lq >> rq ;
            z=query(1, 0, n-1, lq-1, rq-1) ;
            cout<< z.fi + z.se << endl ;
          }
      }
  }
