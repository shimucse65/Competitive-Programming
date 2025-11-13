#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10 ;
const int inf= 1e15+10 ;
int n;
set <int>st[N] ; 
int par[N] ,sub[N] ;

int dfs (int node ,int par){
    sub[node]=1 ;
    for (auto it :st[node]) {
        if (it==par) continue ;
        dfs (it ,node) ;
        sub[node]+= sub[it] ;
    }
    return sub[node] ;
}

int dfs2 (int node ,int par ,int sz) {
   
    for (auto it :st[node]) {
          if (it==par) continue ;
          if (sub[it] > n/2) return dfs2 (it ,node ,sz) ;
    }
    return node ;
}

void solve() { 
   cin>>n ;
  for (int i=0;i<n-1 ;i++){
      int u,v;cin>>u>>v ;
      st[u].insert(v) ;
      st[v].insert (u) ;
  }
   dfs (1,-1) ;
  cout <<dfs2 (1,-1 ,sub[1])<<"\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    {
        solve();
        
    }
    return 0;
}
