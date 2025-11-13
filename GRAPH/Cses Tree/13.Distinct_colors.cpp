#include <bits/stdc++.h>
using namespace std ;
#define int long long 
const int N=2e5+10 ;
set <int> col[N] ;
vector <int>g[N] ;
int ans[N];
void dfs (int node ,int par) {
    for (auto it :g[node]) {
        if (it==par) continue ;
        dfs (it ,node) ;
        if (col[node].size () <col[it].size()) swap (col[node] ,col[it]) ;
        for (auto it :col[it]) col[node].insert (it) ;
    }
    ans[node]= col[node].size () ;
}

void solve (){
    int n;cin>>n ;
   
    for (int i=1 ;i<=n;i++){
        int x ;cin>>x ;
        col[i].insert (x) ;
    }
    
    for (int i=0;i<n-1 ;i++){
        int u,v;cin>>u>>v ;
         g[u].push_back (v) ;
         g[v].push_back (u) ;
    }
    
    dfs (1,-1) ;
    for (int i=1 ;i<=n;i++) cout <<ans[i]<<" " ;
    cout <<"\n" ;
    
}
signed main (){
    solve ();
}
