#include <bits/stdc++.h>
using namespace std ;

int T, n, l, w, ans, temp ;

int main()
  {
    cin>> T ;
    while(T--)
      {
        vector<pair<int, int>> sticks ;
        cin>> n ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> l >> w ;
            sticks.push_back(make_pair(l, w)) ;
          }
        sort(sticks.begin(), sticks.end()) ;
        ans=0 ;
        vector<bool> taken(n+1, false) ;
        for(int i=0 ; i<n ; i++)
          if(!taken[i])
            {
              taken[i]=true ;
              temp=sticks[i].second ;
              for(int j=i+1 ; j<n ; j++)
                if(!taken[j] && sticks[j].second>=temp)
                  {
                    taken[j]=true ;
                    temp=sticks[j].second ;
                  }
              ans++ ;
            }
        cout<< ans << endl ;
      }
  }
