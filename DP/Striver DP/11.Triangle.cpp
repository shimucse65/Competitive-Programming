//leetcode triangle 
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (vector <vector <int >> & a,int n ,int i ,int j ,vector <vector <int >> & dp ) {
     if (i==n-1) return a[i][j] ;
     if (dp[i][j]!=-1) return dp[i][j];
     int bottom= f (a ,n,i+1 ,j,dp) +a[i][j];
     int  diagonal =f (a,n,i+1 ,j+1 ,dp)+ a[i][j];
     return dp[i][j]= min (bottom  , diagonal) ;
        
}   
void solve ()
 {
   int n;cin>>n;
   vector <vector <int>>a (n ,vector <int>(n,0));
   for (int i=0;i<n;i++) {
    for (int j=0 ;j<=i;j++) cin>>a[i][j];
   }
//   for (auto it :a){
//       for (auto el :it) cout<<el<<" ";cout<<"\n";
//   }
   vector<vector <int> > dp (n,vector <int>(n,-1)) ;
  cout<< f (a,n,0 ,0,dp) <<"\n";
   
 }
 signed main (){
  solve ();
 }

/*
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Input: triangle = [[-10]]
Output: -10
 */






 

 
 
 
 