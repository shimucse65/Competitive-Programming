//for finding strongly connected component 
#include <bits/stdc++.h>
using namespace std ;
#define int long long 
const int N=2e5+10 ;
vector <int>g[N] ,tra[N] ;
vector <int>order ;
int vis[N];
vector <int>comp ;


void dfs (int node) {
  vis[node]=true ;
  for (auto it:g[node]) {
    if (!vis[it]) dfs (it);
  }
  order.push_back (node) ;
}

void dfs2 (int node) {
  vis[node]=true ;
  for (auto it:tra[node]) {
    if (!vis[it]) dfs2 (it);
  }
 comp.push_back (node);
}

void solve () {

   //input ,main and transposed graph store 
    int n,m;cin>>n>>m ;
    for (int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        g[u].push_back (v);
        tra[v].push_back (u) ;
    }
    

  // finishing time store & reverse 
  for (int i=0 ;i<n;i++) if (!vis[i]) dfs (i) ;
  reverse (order.begin () ,order.end ()) ;


  //order onujayi transposed graph er upor dfs 
   memset (vis ,0 ,sizeof vis);
    for (auto it :order) {
         comp.clear () ;
         if (!vis[it]) dfs2 (it) ;
         for (auto it :comp) cout<<it<<" "; cout<<"\n";
    }
}

signed main () {
    solve () ;
}











 


