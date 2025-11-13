#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+ 10;
const int inf = 1e15 + 10;
int n ,sz[N];
vector <int>g[N] ;
char ans[N],vis[N] ;

void dfs (int node ,int par){
    sz[node]=1 ;
    for (auto it :g[node]){
        if (it==par ||vis[it]) continue ;
        sz[node]+= sz[it] ;
    }
}

int dfs2 (int node ,int par ,int cur) {
    
    for (auto it :g[node]) {
        if (!vis[it] && it !=par && sz[it]>cur/2)
        return dfs2 (it ,node ,cur) ;
    }
    return node ;
}


void decompose (int node ,int par ,int f) {
    
    dfs (node ,par) ;
    int cent= dfs2 (node ,par ,sz[node]) ;
    vis[cent]=1 ;
    ans[cent]='A'+f ;
    
    for (auto it :g[cent]) {
        if (vis[it]) continue ;
        decompose (it ,cent ,f+1) ;
    }
}


void solve() {
   cin>>n ;
   for (int i=0;i<n-1 ;i++){
       int u,v;cin>>u>>v ;
       g[u].push_back (v) ;
       g[v].push_back (u) ;
   }
   
    decompose (1 ,0,0) ;
   for (int i=1 ;i<=n;i++) cout <<ans[i]<<" " ;cout <<" " ;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
}

//cf : ceil the commander 