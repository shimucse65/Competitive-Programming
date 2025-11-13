//unique path(ii)
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (vector <vector <int >> & a,int i ,int j ,vector <vector <int >> & dp ) {

    if (i>=0 && j>=0 && a[i][j]==1) return 0 ; 
    if (i==0 && j==0) return 1 ;
    if (i<0 && j<0) return 0 ; 
    
    if (dp[i][j]!=-1) return dp[i][j];
    
    int up=0 ,left=0 ;
    if (i-1>=0) up= f (a ,i-1 ,j,dp);
    if (j-1>=0 )left =f (a,i ,j-1 ,dp);
    
    return dp[i][j]= up + left ;
        
}   
void solve ()
 {
   int n,m;cin>>n>>m;
   vector <vector <int>>a (n ,vector <int>(m,0));
   for (int i=0;i<n;i++) {
    for (int j=0 ;j<m;j++) cin>>a[i][j];
   }
   vector<vector <int> > dp (n,vector <int>(m,-1)) ;
   cout<< f (a,n-1 ,m-1,dp) <<"\n";
   
 }
 signed main (){
  solve ();
 }

/*
 [[0,0,0],[0,1,0],[0,0,0]] 
 ans=2 
[[0,1],[0,0]]  ans=1
*/




 

 
 
 
 