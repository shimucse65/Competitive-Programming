//house robber 1
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long


void solve ()
 {
   int n;cin>>n;
   int a[n];
   for (int i=0;i<n;i++) cin>>a[i];
    vector <int>dp (n+1 ,-1);
    dp[0]=a[0] ;
    for (int ind=1;ind<n;ind++) {
        int pick=0 ,not_pick=0 ;
     if (ind-2 >=0)   pick =  dp[ind-2]+ a[ind] ;
     if (ind-1 >=0)  not_pick= dp[ind-1] + 0ll ;
     dp[ind]= max (pick ,not_pick);
    }
   cout<<dp[n-1]<<"\n";
 }
 signed main (){
  solve ();
 }


 //test case : 2 1 4 9 ....ans :11
 //1 2 4 .... ans : 5





