
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 


void solve ()
 {
   int n;cin>>n;
   int a[n],sm=0;
   for (int i=0;i<n;i++) cin>>a[i],sm+=a[i];

   int dp[n+1][sm+1];
   for (int i=0;i<=n;i++) {
    for (int j=0 ;j<=sm;j++) dp[i][j]=0 ;
   }

   for (int i=0;i<n;i++) dp[i][0]=1 ;
   dp[0][a[0]]=1 ;

   for (int i=1 ;i<n;i++) {
    for (int j=0 ;j<=sm;j++) {
      int pick=0 ,not_pick=0 ;
      pick= dp[i-1][j-a[i]] ;
      not_pick= dp[i-1][j];
      dp[i][j]= pick|not_pick ;
    }
   }
   int mn=INT_MAX ;
   for (int i=0;i<=sm;i++) {
    if (dp[n-1][i]) {
        mn= min (mn ,abs (i ,sm-i)) ;
    }
   }
  cout<<mn<<"\n";
   
 }
 signed main (){
  solve ();
 }








 

 
 
 
 