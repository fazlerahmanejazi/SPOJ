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

#define sum(p) get<0>(p)
#define prefix(p) get<1>(p)
#define suffix(p) get<2>(p)
#define best(p) get<3>(p)

using node = tuple<int, int, int, int> ;
int left (int p) { return p<<1 ; }
int right(int p) { return (p<<1)+1 ; }

int n, q, c, lq, rq, t, idx, val ;
vi seq ;
node z ;
vector<node> tree ;

node merge(node x, node y)
  {
    node z ;
    sum(z)=sum(x)+sum(y) ;
    prefix(z)=max(prefix(x), sum(x)+prefix(y)) ;
    suffix(z)=max(suffix(y), sum(y)+suffix(x)) ;
    best(z)=max({best(x), best(y), suffix(x)+prefix(y)}) ;
    return z ;
  }

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=mt(seq[l], seq[l], seq[l], seq[l]) ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        node x=tree[left(p)] ;
        node y=tree[right(p)] ;
        tree[p]=merge(x, y) ;
      }
  }

node query(int p, int l, int r, int lq, int rq)
  {
    if(lq>r || rq<l) return mt(0, -inf, -inf, -inf) ;
    if(lq<=l && rq>=r) return tree[p] ;
    node x=query(left(p), l, (l+r)/2, lq, rq) ;
    node y=query(right(p), (l+r)/2 + 1, r, lq, rq) ;
    return merge(x, y) ;
  }

void update(int p, int l, int r, int idx, int val)
  {
    if(idx<l || idx>r) return ;
    if(l==r)
      {
        tree[p]=mt(seq[l], seq[l], seq[l], seq[l]) ;
        return ;
      }
    update(left(p), l, (l+r)/2, idx, val) ;
    update(right(p), (l+r)/2 +1, r, idx, val) ;
    node x=tree[left(p)] ;
    node y=tree[right(p)] ;
    tree[p]=merge(x, y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    z=mt(0, 0, 0, 0) ;
    tree.assign(4*n+1, z) ;
    seq.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      cin>> seq[i] ;
    build(1, 0, n-1) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> t ;
        if(t==0)
          {
            cin>> idx >> val ;
            seq[idx-1]=val ;
            update(1, 0, n-1, idx-1, val) ;
          }
        else
          {
            cin>> lq >> rq ;
            cout<< best(query(1, 0, n-1, lq-1, rq-1)) << endl ;
          }
      }
  }
