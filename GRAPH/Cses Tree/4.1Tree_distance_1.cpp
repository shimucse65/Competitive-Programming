#include <bits/stdc++.h>
using namespace std ;
#define int long long 
const int N=2e5+10 ;
vector <int>g[N] ;
int vis[N] ;
int dp [N][2] ; // row ,col

void dfs (int node ,int par ,int col ,int dis) {
    
    dp[node][col]=dis ;
    
    for (auto it :g[node]) {
        if (it==par) continue ;
        dfs (it ,node ,col ,dis+1 );
    }
}
pair <int ,int> bfs (int node) {
    
    queue <pair <int ,int> > q;
    q.push ({node ,0}) ; vis[node]=1 ;
    
    pair <int ,int>u ;
    while (!q.empty ()) {
        u= q.front (); q.pop () ;
        for (auto it : g[u.first]) {
            if (!vis[it]) {
                vis[it]=1 ;
                q.push ({it , u.second+1}) ;
            }
        } 
    }
    return u ;
    
}
void solve () {
    
    int n;cin>>n ;
    for (int i=0;i<n-1 ;i++) {
        int u,v;cin>>u>>v ;
        g[u].push_back (v) ;
        g[v].push_back (u) ;
    }
    
    pair <int ,int> a= bfs (1) ;
    
    memset (vis ,0 ,sizeof vis) ;
    pair <int ,int> b= bfs (a.first ) ;
    
    //cout <<a.first <<" " <<b.first <<"\n";
    
    
    dfs (a.first ,-1 ,0 ,0) ;
    dfs (b.first ,-1 ,1,0) ;
    
    for(int i=1 ;i<=n;i++) cout <<max (dp[i][0] ,dp[i][1]) <<" ";
    
}

signed main () {
    
    int t;t=1 ;
    while (t--) {
        solve () ;
    }
}