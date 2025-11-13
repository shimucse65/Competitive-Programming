#include <bits/stdc++.h>
using namespace std ;
const int N=2e5+10 ;
vector <int>g[N] ;
int sz[N] ;

void dfs (int node ,int par) {
    
     sz[node]=1 ;
    for (auto it :g[node]) {
        if (it==par) continue ;
        dfs (it ,node) ;
        sz[node]+= sz[it] ;
    }
}

void solve () {
    int n;cin>>n;
    int cnt=2 ;
    for (int i=0;i<n-1 ;i++) {
        int x;cin>>x ;
        g[x].push_back (cnt) ; cnt++ ;
    }
    dfs (1,-1) ;
    for (int i=1 ;i<=n;i++) cout <<sz[i]-1<<" ";cout <<"\n";
}

signed main () {
    solve () ;
}