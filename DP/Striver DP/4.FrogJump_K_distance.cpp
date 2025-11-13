//atcoder frog 2 
 #include<bits/stdc++.h>
using namespace std;
#define int long long 


int f (int a[] ,int ind ,vector <int>&dp,int k){
    if (ind ==0) return 0 ;
    if (dp[ind]!=-1) return dp[ind];

    int mn = INT_MAX , left =INT_MAX;
    for (int j=1 ;j<= k;j++){
    
    if (ind-j>=0){
         left = f (a,ind-j ,dp,k)+ abs (a[ind]- a[ind-j]) ;
    }
   mn= min (mn ,left); 
 } 
    
   return dp[ind]=mn ;

}

void solve ()
 {
   int n,k;cin>>n>>k;
   int a[n];
   for (int i=0;i<n;i++) cin>>a[i];
   vector <int>dp (n+1 ,-1);
   cout<<f (a,n-1,dp,k) <<"\n";

 }
 signed main (){
  solve ();
 }

 /*
 5 3
10 30 40 50 20
ans :30
*/

 
 
 
 
 
 
 