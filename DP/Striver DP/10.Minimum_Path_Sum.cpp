//minimum path sum 
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (vector <vector <int >> & a,int i ,int j ,vector <vector <int >> & dp ) {

    
    if (i==0 && j==0) return a[0][0] ;
    if (i<0 || j<0) return INT_MAX ; 
    
    if (dp[i][j]!=-1) return dp[i][j];
    
    
     int up= f (a ,i-1 ,j,dp) +a[i][j];
     int  left =f (a,i ,j-1 ,dp)+ a[i][j];
    
    return dp[i][j]= min (up , left) ;
        
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
[[1,3,1],[1,5,1],[4,2,1]] ans=7 
[[1,2,3],[4,5,6]]  ans=12
*/




 

 
 
 
 