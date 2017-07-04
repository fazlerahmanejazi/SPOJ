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

int n, q, lq, rq, k, last_ans ;
vi seq ;
vvi tree ;

void build(int p, int l, int r)
  {
    if(l==r) tree[p].pb(seq[l]) ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        vi x=tree[left(p)] ;
        vi y=tree[right(p)] ;
        merge(all(x), all(y), back_inserter(tree[p])) ;
      }
  }

int query(int p, int l, int r, int lq, int rq)
  {
    if(lq>r || rq<l) return 0 ;
    if(lq<=l && rq>=r)
      {
        int z=tree[p].size()-(upper_bound(all(tree[p]), k)-tree[p].begin()) ;
        return z ;
      }
    int x=query(left(p), l, (l+r)/2, lq, rq) ;
    int y=query(right(p), (l+r)/2 + 1, r, lq, rq) ;
    return x+y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    tree.resize(4*n+1) ;
    seq.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      cin>> seq[i] ;
    build(1, 0, n-1) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> lq >> rq >> k ;
        lq^=last_ans ;
        rq^=last_ans ;
        k^=last_ans ;
        last_ans=query(1, 0, n-1, lq-1, rq-1) ;
        cout<< last_ans << endl ;
      }
  }
