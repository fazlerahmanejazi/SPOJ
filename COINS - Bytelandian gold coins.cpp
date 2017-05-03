#include <bits/stdc++.h>
using namespace std ;

map<int, long long> dp;

long long f(int n)
  {
    if(n==0) return 0;
    if(dp[n]!=0) return dp[n];
    dp[n]=max(n, f(n/2)+f(n/3)+f(n/4));
    return dp[n];
  }

int main()
  {
    int n;
    while(cin>>n)
      cout<< f(n) << endl ;
    return 0;
  }
