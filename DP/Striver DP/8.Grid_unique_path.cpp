//Unique path (1) ,leetcode
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (int i ,int j ,vector <vector <int > > & dp ) {

    if (i==0 && j==0) return 1 ;
    if (i<0 || j<0) return 0 ; 
    
    if (dp[i][j]!=-1) return dp[i][j];
    int up= f (i-1 ,j,dp);
    int left =f (i ,j-1 ,dp);
    
    return dp[i][j]= up + left ;
        
}   
void solve ()
 {
   int m,n;cin>>m>>n ;
   vector<vector <int> > dp (m,vector <int>(n,-1)) ;
   cout<< f (m-1 ,n-1,dp) <<"\n";
      
 }
 signed main (){
  solve ();
 }

/*
 3 7
 ans:28
*/




 

 
 
 
 