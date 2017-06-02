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

int n, x, pos, idx, l, r, m, curr, y, remain ;
vi ans, tree ;

int query(int i)
  {
    int temp=0 ;
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
        ans.clear() ; ans.resize(n) ;
        tree.assign(n, 0) ;
        for(int i=0 ; i<n ; i++)
          update(i, 1) ;
        curr=1 ; y=1 ;
        remain=n ;
        while(curr<=n)
          {
            y=(y+curr)%remain ;
            if(!y) y=remain ;
            l=0 ; r=n-1 ;
            while(l<=r)
              {
                m=(l+r)/2 ;
                x=query(m) ;
                if(x<y) l=m+1 ;
                else
                  {
                    r=m-1 ;
                    pos=m ;
                  }
              }
            ans[l]=curr++ ;
            update(l, -1) ;
            remain-- ;
          }
        for(int i=0 ; i<n ; i++)
          cout<< ans[i] << " " ;
        cout<< endl ;
      }
    }
