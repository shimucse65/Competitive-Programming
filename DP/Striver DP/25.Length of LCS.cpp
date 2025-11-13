
 #include<bits/stdc++.h>
 using namespace std;
 #define int long long 
int f (int ind1 ,int ind2 ,string & s1, string &s2,vector< vector <int>>&dp) {
    if (ind1<0 ||ind2<0) return 0 ;
    if (s1[ind1]==s2[ind2]) return dp[ind1][ind2]= f (ind1-1 ,ind2-1,s1,s2,dp)+1 ;
    else return dp[ind1][ind2]= max (f (ind1-1 ,ind2 ,s1,s2,dp) ,f(ind1,ind2-1 ,s1,s2,dp)) ;

}

void solve ()
 {
   string s1 ,s2;cin>>s1>>s2 ;
   vector < vector <int> dp (ind1+1 ,vector <int>(ind2+1 ,-1)) ;
   cout<< f(s1 ,s2,ind1 ,ind2 ,dp)<<"\n";
   
 }
 signed main (){
  solve ();
 }








 

 
 
 
 