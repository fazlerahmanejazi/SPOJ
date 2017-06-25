#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int T, n, l, r, m1, m2 ;
lli ans ;
vi h, c ;

lli cost(int x)
  {
    lli res=0 ;
    for(int i=0 ; i<n ; i++)
      res=res+(lli)c[i]*abs(x-h[i]) ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        l=inf ; r=-inf ;
        ans=2*INF ;
        h.clear() ; c.clear() ;
        h.resize(n) ; c.resize(n) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> h[i] ;
            l=min(l, h[i]) ;
            r=max(r, h[i]) ;
          }
        for(int i=0 ; i<n ; i++)
          cin>> c[i] ;
        while(r-l>=3)
          {
            m1=l+(r-l)/3 ;
            m2=r-(r-l)/3 ;
            if(cost(m1)>cost(m2)) l=m1 ;
            else r=m2 ;
          }
        for(int i=l ; i<=r ; i++)
          ans=min(ans, cost(i)) ;
        cout<< ans << endl ;
      }
  }
