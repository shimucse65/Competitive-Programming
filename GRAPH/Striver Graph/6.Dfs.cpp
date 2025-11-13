#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first
#define ss second
const int N=1e5+10 ;
const int inf= 1e15+10 ;
int vis[N] ;
vector <int>g[N] ;

void dfs (int node ,int par) {
    vis[node]=true ;
    cout <<node<<" " ;
    for (auto it :g[node]) {
        if (!vis[it]) dfs(it ,node) ;
    }

}
 
void solve() {
   int n,m;cin>>n>>m ;
   for (int i=0;i<n;i++) {
       int u,v;cin>>u>>v ;
       g[u].push_back(v) ;
       g[v].push_back (u) ;
   }
   
  dfs (1,-1) ;  
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t ;
    // while (t--)
    {
        solve();
        
    }
    return 0;
}
