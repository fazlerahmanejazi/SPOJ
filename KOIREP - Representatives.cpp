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
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, diff=inf, l, r, x, lim, check=0 ;
    cin>> n >> m ;
    vpii a ;
    vi cnt(n+1, 0) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> x ;
          a.pb(mp(x, i+1)) ;
        }
    lim=n*m ;
    l=r=0 ;
    sort(a.begin(), a.end()) ;
    check=1 ;
    cnt[a[0].se]++ ;
    while(r<lim && l<lim)
      {
        if(check==n)
          {
            diff=min(diff, a[r].fi-a[l].fi) ;
            cnt[a[l].se]-- ;
            if(!cnt[a[l].se]) check-- ;
            l++ ;
          }
        else
          {
            r++ ;
            if(r==lim) break ;
            cnt[a[r].se]++ ;
            if(cnt[a[r].se]==1) check++ ;
          }
      }
    cout<< diff ;
  }
