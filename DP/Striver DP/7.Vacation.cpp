//atcoder :Vacation
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 

int f (vector <vector <int >> & a ,int ind ,int last ,vector <vector <int >> & dp ){

    if (ind==0) {
        int mx= INT_MIN ;
        for (int task=0 ;task<3 ;task++){
            if (task==last) continue ;
            mx= max (mx ,a[0][task]) ;
        }
        return mx ;
    }
    if (dp[ind][last]!=-1) return dp[ind][last];

        int mx= INT_MIN ;    
        for (int task=0 ;task<3 ;task++){
            if (task==last) continue ;
            int point= a[ind][task] + f (a,ind-1 ,task ,dp);
               mx= max (mx ,point) ;
        }
        return dp[ind][last]=mx ;
    

}
void solve ()
 {
   int n;cin>>n;
   vector <vector <int>>a (n ,vector <int>(3,0));
   for (int i=0;i<n;i++) {
    for (int j=0 ;j<3;j++) cin>>a[i][j];
   }
   vector<vector <int> > dp (n,vector <int>(4,-1)) ;
   cout<< f (a ,n-1 ,3 ,dp) <<"\n";
   
 }
 signed main (){
  solve ();
 }
/* 3
10 40 70
20 50 80
30 60 90
ans=210 */



 
 

 
 
 

 
 
 
 
 