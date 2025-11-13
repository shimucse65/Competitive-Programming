#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
const int mod=998244353 ;
int dp[N][2] ; 
int n ;
vector <int>g[N] ;

void dfs (int node ,int par){
    
    dp[node][0]= dp[node][1]=0 ;
    int leaf=1 ;
    for (auto it :g[node]) {
        if (it==par) continue ;
        leaf=0 ;
        dfs (it ,node) ;
    }
    
    if (leaf) return ;
    
    
    vector <int>pf ,suff ;
    
    for (auto it :g[node]) {
        if (it==par) continue ;
        pf.push_back (max (dp[it][0] ,dp[it][1])) ;
         suff.push_back (max (dp[it][0] ,dp[it][1])) ;
    }
    
    for (int i=1 ;i<pf.size ();i++) pf[i]+= pf[i-1] ;
    
    
    for (int i=suff.size()-2 ;i>=0 ;i--)  suff[i]+= suff[i+1] ;
    
     dp[node][0]= suff[0] ;
    
    
        dp[node][0] = suff[0];
       int c_no = 0;
       for(int child : g[node])
       {
        if(child == par)continue;
 
        int leftChildren = (c_no == 0) ? 0 : pf[c_no - 1];
        int rightChildren = (c_no == (int)suff.size() - 1) ? 0 : suff[c_no + 1];
 
        dp[node][1] = max(dp[node][1], 1 + leftChildren + rightChildren + dp[child][0]);
        c_no++;
       
       }    
}

void solve() {
    
  cin>>n ;
  for (int i=0;i<n-1 ;i++){
      int u,v;cin>>u>>v ;
      g[u].push_back (v) ;
      g[v].push_back (u) ;
  }

 dfs (1,-1) ;
 cout <<max(dp[1][0] , dp[1][1]) ;
          
           
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
