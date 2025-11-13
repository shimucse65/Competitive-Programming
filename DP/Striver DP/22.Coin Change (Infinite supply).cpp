
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 
int f (int ind ,int target ,int a[] ,vector< vector <int> >  &dp) {
    if (ind==0) {
         if (target%a[0]) return target/a[i];
         return 0 ;
    }  
    if (dp[ind][target]!=-1) return dp[ind][target];
     int pick=INT_MAX ;
     pick=f (ind ,target-a[ind],a,dp) +1;
     int not_pick= f (ind-1 ,target,a,dp) ;

     return  dp[ind][cap]=min( pick ,not_pick ) ;
}

void solve ()
 {
   int n ,target;cin>>n >>target;
   int a[n] ;
   for (int i=0;i<n;i++) cin>>a[i];
   
   
   vector< vector <int>>dp (n+1 ,vector <int> (target+1 ,-1) );
   cout<< f (n-1 ,target ,a,dp);
   
 }
 signed main (){
  solve ();
 }








 

 
 
 
 