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
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, x ;
long long int inv ;
vi a, b ;
vlli tree ;

long long int sum(int i)
  {
    long long int temp=0 ;
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
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        a.clear() ; b.clear() ; tree.clear() ;
        tree.assign(n, 0) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            a.pb(x) ; b.pb(x) ;
          }
        sort(b.begin(), b.end()) ;
        for(int i=0 ; i<n ; i++)
          {
            x=lower_bound(all(b), a[i])-b.begin() ;
            a[i]=x ;
          }
        inv=0 ;
        for(int i=n-1 ; i>=0 ; i--)
          {
            inv+=sum(a[i]) ;
            update(a[i], 1) ;
          }
        cout<< inv << endl ;
      }
    }
