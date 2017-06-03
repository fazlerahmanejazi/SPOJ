#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
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

vi tree ;

int sum(int idx)
  {
    int temp=0 ;
    for( ; idx>=0 ; idx=(idx&(idx+1))-1)
      temp+=tree[idx] ;
    return temp ;
  }

void update(int idx, int val, int n)
  {
    for( ; idx<n ; idx=(idx|(idx+1)))
      tree[idx]+=val ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, d, l, r, pos=0, idx ;
    map<int , int> last ;
    cin>> n ;
    vi a(n) ;
    tree.resize(n, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        last[a[i]]=-1 ;
      }
    cin>> d ;
    vector<pair<pii, int>> q ;
    vi ans(d) ;
    for(int i=0 ; i<d ; i++)
      {
        cin>> l >> r ;
        q.pb(mp(mp(r-1, l-1), i)) ;
      }
    sort(q.begin(), q.end()) ;
    for(int i=0 ; i<n ; i++)
      {
        if(last[a[i]]!=-1) update(last[a[i]], -1, n) ;
        last[a[i]]=i ;
        update(i, 1, n) ;
        while(pos<d && q[pos].fi.fi==i)
          {
            l=q[pos].fi.se ; r=q[pos].fi.fi ; idx=q[pos].se ;
            ans[idx]=sum(r) ;
            if(l>0) ans[idx]-=sum(l-1) ;
            pos++ ;
          }
      }
    for(int i=0 ; i<d ; i++)
      cout<< ans[i] << endl ;
  }
