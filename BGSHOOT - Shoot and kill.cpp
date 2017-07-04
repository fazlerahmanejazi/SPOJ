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

int n, q, l, r, c, maxm ;

vi tree, seq ;
vpii data, queries ;
set<int> times ;
set<int>::iterator it ;
map<int, int> compress ;

void init()
  {
    tree.assign(4*c+1, 0) ;
    seq.assign(c+1, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        seq[compress[data[i].fi]]++ ;
        seq[compress[data[i].se]+1]-- ;
      }
    for(int i=1 ; i<=c ; i++)
      seq[i]+=seq[i-1] ;
  }

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=seq[l] ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        int x=tree[left(p)] ;
        int y=tree[right(p)] ;
        tree[p]=max(x, y) ;
      }
  }

int query(int p, int l, int r, int i, int j)
  {
    if(i>r || j<l) return 0 ;
    if(i<=l && j>=r) return tree[p] ;
    int x=query(left(p), l, (l+r)/2, i, j) ;
    int y=query(right(p), (l+r)/2 + 1, r, i, j) ;
    return max(x, y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> l >> r ;
        data.pb(mp(l, r)) ;
        times.insert(l) ;
        times.insert(r) ;
      }
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> l >> r ;
        queries.pb(mp(l, r)) ;
        times.insert(l) ;
        times.insert(r) ;
      }
    it=times.begin() ;
    c=0 ;
    while(it!=times.end())
      {
        compress[*it]=c++ ;
        it++ ;
      }
    init() ;
    build(1, 0, c) ;
    for(int i=0 ; i<q ; i++)
      {
        l=compress[queries[i].fi] ;
        r=compress[queries[i].se] ;
        cout<< query(1, 0, c, l, r) << endl ;
      }
    }
 
