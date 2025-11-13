
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 
int f (int ind ,int cap ,int a[] , int val[],vector< vector <int>>  &dp) {
    if (ind==0) {
        if (cap>=a[0]) return val[ind];
         return 0;
    }
    if (dp[ind][cap]!=-1) return dp[ind][cap];
     int pick=INT_MIN ;
     pick=f (ind-1 ,cap-a[ind],a,val,dp) +val[ind];
     int not_pick= f (ind-1 ,cap,a,val,dp) ;

     return  dp[ind][cap]= pick+not_pick ;
}

void solve ()
 {
   int n ,capacity;cin>>n>>capacity ;
   int a[n] ,val[n];
   for (int i=0;i<n;i++) cin>>a[i];
   for (int i=0;i<n;i++) cin>>val[i];
   
   vector< vector <int>>dp (n+1 ,vector <int> (capacity+1 ,-1) );
   cout<< f (n-1 ,capacity ,a,val ,dp);
   
 }
 signed main (){
  solve ();
 }








 

 
 
 
 