#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=1e9+7 ;
const int N=100005 ;
int dp[N]

void solve() { 
 int n;cin>>n ;   
 vector <int>v(n) ;
 for (auto & x:v) cin>>x ;
 
 
 dp[0]= dp[1]=1 ;
 
  
  for (int i=0 ;i<n;i++) {
      
     int tmp=v[i] ;
     vector <int>divi;
     for (int i=1 ;i*i<=tmp ;i++) {
         if (tmp%i==0) {
             divi.push_back (i) ;
             if (i*i !=tmp) {
                  divi.push_back (tmp/i) ;
             }
         }
     }
     
     sort (divi.begin () ,divi.end ()) ;
     reverse (divi.begin () ,divi.end ()) ;
     
     for (auto it :divi) {
         dp[it]+= dp[it-1] ;
         dp[it] %=mod ;
     }
     
  }
  
   int ans=0 ;
   for (int ln=1 ;ln<=n ;ln++) {
      ans+= dp[ln] ;
      ans%=mod ;
  }
  cout<<ans <<"\n";
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
