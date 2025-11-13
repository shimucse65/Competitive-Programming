
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long   
 void solve ()
 {
   string s1 ,s2;cin>>s1>>s2 ;
   int n=s1.size () ,m=s2.size() ;
   vector < vector <int> dp (n ,vector <int>(m ,-1)) ;
   for (int i=0 ;i<n;i++) dp[i][0]=0 ;
   for (int j=0 ;j<m;j++) dp[0][j]=0 ;
   
   for (int i=1 ;i<=n ;i++)  {
    for (int j=1 ;j<=m;j++) {
        if (s1[i-1]==s2[j-1]) dp[i][j]=1+ dp[i-1][j-1] ;
        else dp[i][j]= max (dp[i-1][j] ,dp[i][j-1]) ;
     }
   }
   string ans="";
   while (i>0 && j>0) {
    if (s1[i-1]==s2[j-1]) ans+= s1[i-1] ;i--;j--;
    else if (dp[i-1][j] >dp[i][j-1]) i-- ;
    else j-- ;
   }

 reverse (ans.begin () ,ans.end ()) ;
 cout<<ans <<"\n";

 }
 signed main (){
  solve ();
 }







   








 

 
 
 
 