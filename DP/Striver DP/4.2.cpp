//Atcoder frog 2
 #include<bits/stdc++.h>
using namespace std;
#define int long long
void solve ()
 {
    int n,k;cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    vector <int>dp (n+1 ,-1);
    dp[0]=0 ; int left;
    int mn=INT_MAX ;
    for (int ind=1 ;ind<n;ind++) {
      for (int j=1;j<=k ;j++) {
       if (ind-j >=0)
       left = dp[ind-j]+ abs (a[ind]- a[ind-j]) ;
       dp[ind]=min (mn ,left);
    }
   }
   //for (int i=0 ;i<n;i++) cout<<dp[i]<<" " ;cout<<"\n";
   cout<< dp[n-1]<<"\n";

 }
 signed main (){
  solve ();
 }

/*
 5 3
10 30 40 50 20
ans :30
*/







