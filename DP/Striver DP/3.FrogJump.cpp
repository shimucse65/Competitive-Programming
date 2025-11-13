//Atcoder frog 1
 #include<bits/stdc++.h>
using namespace std;
#define int long long 

int f (int a[] ,int ind ,vector <int>&dp){
    if (ind ==0) return 0 ;
    if (dp[ind]!=-1) return dp[ind];
    int left = f (a,ind-1 ,dp)+ abs (a[ind]- a[ind-1]) ;
    int right ;
    if (ind==1) right=INT_MAX ;
    else right = f(a,ind -2,dp) + abs (a[ind]- a[ind-2]) ;
     return dp[ind]= min (left ,right);
}



void solve ()
 {
   int n;cin>>n;
   int a[n];
   for (int i=0;i<n;i++) cin>>a[i];
   vector <int>dp (n+1 ,-1);
   cout<<f (a,n-1,dp) <<"\n";

 }
 signed main (){
  solve ();
 }

 
 //test case : 10 20 30 10  ....ans :20 
 
 
 
 
 
 
 