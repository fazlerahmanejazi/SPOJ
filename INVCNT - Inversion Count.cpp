#include <bits/stdc++.h>
using namespace std ;

int T, n, x ;
vector<int> seq, temp ;

long long int merge(int left, int mid, int right)
  {
    int i=left, j=mid, k=left ;
    long long int count=0 ;
    while(i<=mid-1 && j<=right)
      {
        if(seq[i]<seq[j])
          temp[k++]=seq[i++] ;
        else
          {
            temp[k++]=seq[j++] ;
            count+=mid-i ;
          }
      }
    while(i<=mid-1)
      temp[k++]=seq[i++] ;
    while(j<=right)
      temp[k++]=seq[j++] ;
    for(int l=left ; l<=right ; l++)
      seq[l]=temp[l] ;
    return count ;
  }

long long int mergeSort(int left, int right)
  {
    int mid ;
    long long int count=0 ;
    if(right>left)
      {
        mid=(right+left)/2 ;
        count+=mergeSort(left, mid) ;
        count+=mergeSort(mid+1, right) ;
        count+=merge(left, mid+1, right) ;
      }
    return count ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        temp.clear() ;
        seq.clear() ;
        temp.resize(n) ;
        for(int i=0 ; i<n; i++)
          {
            cin>> x;
            seq.push_back(x) ;
          }
        cout<< mergeSort(0, n-1) << endl ;
      }
  }
