
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 
int  f (int ind ,int target ,int a[] , vector< vector <int>>  &dp) {
    if (ind==0) {
        if (target==0) return 1 ;
        if (target==a[0]) return 1 ;
        return 1 ;
    }
    if (dp[ind][target]!=-1) return dp[ind][target];
     int pick=false ;
     pick=f (ind-1 ,target-a[ind],a,dp) ;
     int not_pick= f (ind-1 ,target,a,dp) ;

     return  dp[ind][target]= pick+not_pick ;
}

void solve ()
 {
   int n,d;cin>>n>>d;
   int a[n] ,sm=0;
   for (int i=0;i<n;i++) cin>>a[i],sm+=a[i];
   int target=(sm-d)/2 ;
   vector< vector <int>>dp (n+1 ,vector <int> (target+1 ,-1) );
   cout<< f (n-1 ,target ,a,dp);
   
 }
 signed main (){
  solve ();
 }








 

 
 
 
 