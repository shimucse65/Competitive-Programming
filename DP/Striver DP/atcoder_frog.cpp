#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100007;
const int mod = 1e9 + 7;
int dp[N] ;  

 // return minimim cost for reaching ind 
 int f (int ind ,int n ,int a[])  {
     if (ind==n) return 0 ;
     
     int  &ans= dp[ind] ;
     if (~ans) return ans ;
     
     int one=1e15 ;
     if (ind-1 >=0)
      one =abs (a[ind]-a[ind-1]) + f (ind+1 ,n,a) ;
      
      int two=1e15 ;
      if (ind-2 >=0) {
          two = abs (a[ind]- a[ind-2] )+ f (ind+1 ,n,a) ;
      }
      
     return ans= min (one ,two) ; 
     
 }



void solve() { 
 int n;cin>>n;
 int a[n];
 for (int i=0;i<n;i++) cin>>a[i];
 memset (dp ,-1, sizeof dp) ;
 cout<< f (0 ,n,a) <<"\n";
 
}

signed main() {
    // int t;
    // cin >> t;
    // while (t--) 
    {
        solve();
    }
    return 0;
}
