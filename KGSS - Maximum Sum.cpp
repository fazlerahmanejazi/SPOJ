#include <bits/stdc++.h>
using namespace std ;

int left (int p) { return p << 1 ; }
int right(int p) { return (p << 1) + 1 ; }

int n, q, a, b, ans, idx, temp, curr ;
char c ;

vector<int> tree, seq, f ;

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=l ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        int x=tree[left(p)] ;
        int y=tree[right(p)] ;
        if(seq[x]>=seq[y]) tree[p]=x ;
        else tree[p]=y ; ;
      }
  }

int query(int p, int l, int r, int i, int j)
  {
    if(i>r || j<l) return -1 ;
    if(i<=l && j>=r) return tree[p] ;
    int x=query(left(p), l, (l+r)/2, i, j) ;
    int y=query(right(p), (l+r)/2 + 1, r, i, j) ;
    if(x==-1) return y ;
    if(y==-1) return x ;
    if(seq[x]>=seq[y]) return x ;
    else return y ;
  }

void update(int p, int l, int r, int idx)
  {
    if(idx<l || idx>r) return ;
    if(l==r) return ;
    update(left(p), l, (l+r)/2, idx) ;
    update(right(p), (l+r)/2 +1, r, idx) ;
    int x=tree[left(p)] ;
    int y=tree[right(p)] ;
    if(seq[x]>=seq[y]) tree[p]=x ;
    else tree[p]=y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> n ;
    tree.assign(4*n, 0) ;
    seq.assign(n, 0) ;
    for(int i=0 ; i<n ; i++)
        cin>> seq[i] ;
    cin>> q ;
    build(1, 0, n-1) ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> c >> a >> b ;
        if(c=='U')
          {
            seq[a-1]=b ;
            update(1, 0 , n-1, a-1) ;
          }
        else
          {
            ans=0 ;
            temp=query(1, 0, n-1, a-1, b-1) ;
            ans+=seq[temp] ;
            seq[temp]=-1 ;
            update(1, 0 , n-1, temp) ;
            curr=query(1, 0, n-1, a-1, b-1) ;
            seq[temp]=ans ;
            update(1, 0 , n-1, temp) ;
            ans+=seq[curr] ;
            cout<< ans << endl ;
          }
      }
  }
