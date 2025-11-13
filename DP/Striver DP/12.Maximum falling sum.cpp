
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (vector <vector <int >> & a,int n ,int i ,int j ,vector <vector <int >> & dp ) {
     if (i==0) return a[i][j] ;
     if (dp[i][j]!=-1) return dp[i][j];

     int up= f (a ,n,i-1 ,j,dp) +a[i][j];
     int  ld =f (a,n,i-1 ,j-1 ,dp)+ a[i][j];
     int rd=f (a,n,i-1 ,j+1 ,dp)+ a[i][j];

     return dp[i][j]= max (up ,max (ld ,rd)) ;
        
}   
void solve ()
 {
   int n;cin>>n;
   vector <vector <int>>a (n ,vector <int>(n,0));
   for (int i=0;i<n;i++) {
    for (int j=0 ;j<=i;j++) cin>>a[i][j];
   }

   vector<vector <int> > dp (n,vector <int>(n,-1)) ;
//   cout<< f (a,n,n-1 ,n-1,dp) <<"\n";
//   cout<< f (a,n,n-1 ,n-2,dp) <<"\n";
//   cout<< f (a,n,n-1 ,n-3,dp) <<"\n";
//   cout<< f (a,n,n-1 ,0,dp) <<"\n";

  int mx=-1 ;
  for (int j=0 ;j<=n-1 ;j++) {
    mx= max (mx , f(a,n,n-1 ,j,dp)) ;
  }

 cout<<mx<<"\n";
   
 }
 signed main (){
  solve ();
 }







 

 
 
 
 