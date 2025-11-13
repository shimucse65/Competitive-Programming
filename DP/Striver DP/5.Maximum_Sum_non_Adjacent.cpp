//house robber 1
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f ( int v[],int ind ,vector <int>&dp){

    if (ind ==0) return v[0] ;
    if (dp[ind]!=-1) return dp[ind];
    
    int pick=0 ,not_pick=0 ;
   if (ind-2 >=0)   pick = f (v,ind-2 ,dp)+ v[ind] ;
   if (ind-1 >=0)  not_pick= f (v,ind-1 ,dp) + 0ll ;

   
     return max (pick ,not_pick);
}
void solve ()
 {
   int n;cin>>n;
   int a[n];
   for (int i=0;i<n;i++) cin>>a[i];
    vector <int>dp (n+1 ,-1);
    cout<< f(a,n-1 ,dp)<<"\n";

 }
 signed main (){
  solve ();
 }

 
 //test case : 2 1 4 9 ....ans :11 
 //1 2 4 .... ans : 5
 
 
 
 
 
 