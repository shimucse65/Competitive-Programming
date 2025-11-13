//house robber 2 
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (  vector <int>&v,int ind ,vector <int>&dp){

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
   vector <int>v(n);
   for (int i=0;i<n;i++) cin>>v[i];
    vector <int>dp (n+1 ,-1);
    vector <int>tmp1 ,tmp2 ;
    for (int i=0;i<n;i++){
        if (i!=0) tmp1.push_back (v[i]);
        if (i!=n-1) tmp2.push_back (v[i]);
    }
    int ans1= f (tmp1 ,n-1 ,dp);
    int ans2 = f (tmp2 ,n-1 ,dp);
    cout<<max (ans1 ,ans2)<<"\n";

 }
 signed main (){
  solve ();
 }

 /*
 [1,2,3,1] ans=4 
 [2,3,2] ans=3 
 */

 
 
 
 
 