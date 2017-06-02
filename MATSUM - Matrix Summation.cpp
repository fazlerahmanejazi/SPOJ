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

int n, x, y, a, b, val, ans ;
string s ;
int tree[1024+10][1024+10], data[1024+10][1024+10] ;

int sum(int x, int y)
  {
    int temp=0 ;
    for(int i=x ; i>=0 ; i=(i&(i+1))-1)
			for(int j=y ; j>=0 ; j=(j&(j+1))-1)
      	temp+=tree[i][j] ;
    return temp ;
  }

void update(int x, int y, int val)
  {
    for(int i=x ; i<n ; i=(i|(i+1)))
			for(int j=y ; j<n ; j=(j|(j+1)))
      	tree[i][j]+=val ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        memset(tree, 0, sizeof tree) ;
				memset(data, 0, sizeof data) ;
        while(cin>> s && s!="END")
					{
						if(s=="SET")
							{
								cin>> x >> y >> val ;
								update(x, y, val-data[x][y]) ;
								data[x][y]=val ;
							}
						else
							{
								cin>> x >> y >> a >> b ;
								ans=sum(a, b) ;
								if(y>0) ans-=sum(a, y-1) ;
								if(x>0) ans-=sum(x-1, b) ;
								if(x>0 && y>0) ans+=sum(x-1, y-1) ;
								cout<< ans << endl ;
							}
					}
				cout<< endl ;
      }
    }
