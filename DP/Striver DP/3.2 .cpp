//Atcoder frog 1
 #include<bits/stdc++.h>
using namespace std;
#define int long long
void solve ()
 {
    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    vector <int>dp (n+1 ,-1);
    dp[0]=0 ;
    for (int ind=1 ;ind<=n;ind++) {
    int left = dp[ind-1]+ abs (a[ind]- a[ind-1]) ;
    int right ;
    if (ind==1) right=INT_MAX ;
    else right = dp[ind-2] + abs (a[ind]- a[ind-2]) ;
     dp[ind]= min (left ,right);
   }
   //for (int i=0 ;i<n;i++) cout<<dp[i]<<" " ;cout<<"\n";
   cout<< dp[n-1]<<"\n";

 }
 signed main (){
  solve ();
 }


 //test case : 10 20 30 10  ....ans :20






