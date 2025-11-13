#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first 
#define ss second 
const int N=2e5+10 ;
const int inf= 1e15+10 ;
int n ;
int size[N] ,subdis[N] ,ans[N] ;
vector <int>g[N];

void dfs1 (int node ,int par){
    size[node]=1 ;
    for (auto it :g[node]){
        if (it==par) continue ;
        dfs1 (it ,node) ;
        size[node]+= size[it] ;
        subdis[node]+= subdis[it]+ size[it] ;
    }
}

void dfs2 (int node ,int par) {
    
    ans[node]= subdis[node]+ (ans[par]-size[node]-subdis[node])+ (n-size[node]) ;
    
    for (auto it :g[node]) {
        if (it==par) continue ;
        dfs2 (it,node) ;
    }
}



void solve() { 
    cin>>n ;
    for (int i=0;i<n-1 ;i++){
        int u,v;cin>>u>>v ;
        g[u].push_back (v) ;
        g[v].push_back (u);
    }
    
       dfs1 (1,-1) ;
       ans[1]=subdis[1];
    
     for (auto it :g[1] ) dfs2 (it ,1) ;
  
    
     for (int i=1 ;i<=n;i++) cout <<ans[i] <<" " ;

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
