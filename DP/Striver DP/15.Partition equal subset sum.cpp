
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 
bool f (int ind ,int target ,int a[] , vector<int> & dp) {
    if (ind==0) {
        if (target==0) return true ;
        if (target==a[0]) return true ;
        return false ;
    }
    if (dp[ind]!=-1) return dp[ind];
     int pick=false ;
     pick=f (ind-1 ,target-a[ind],a,dp) ;
     int not_pick= f (ind-1 ,target,a,dp) ;

     return  dp[ind]= pick|not_pick ;
}

void solve ()
 {
   int n,target;cin>>n>>target;
   int a[n];
   for (int i=0;i<n;i++) cin>>a[i];
   
   vector<int >dp (n+1 ,-1);
   cout<< f (n-1 ,target ,a,dp);
   
 }
 signed main (){
  solve ();
 }








 

 
 
 
 