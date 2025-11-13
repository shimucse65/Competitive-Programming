#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10 ;
const int inf= 1e15+10 ;
int par[N]  ,table[N][21];
vector <int>g[N] ;
int n,q;

void dfs (int node ,int parent) {
    par[node]=parent ;
    for (auto it :g[node]){
        if (it==parent) continue ;
        dfs (it ,node) ;
    }
}
 
void build() {
    dfs (1,-1);
    memset(table, -1, sizeof(table));
    for (int i = 1; i <= n; i++) table[i][0] = par[i];
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][j-1] != -1) {
              table[i][j]= table[table[i][j-1]][j-1];
            }
        }
    }
}
int kth (int x ,int k){
    for (int i=0 ;i<21;i++) {
        if (k& (1<<i)) {
            x= table [x][i] ;
            if (x==-1) break ;
        }
    }
    return x ;
}
void solve() { 
    cin>>n>>q ;
    par[1]=1 ;

    for (int i=2 ;i<=n ;i++) {
        int x;cin>>x ;
       g[x].push_back(i) ;
       g[i].push_back (x) ;
    }
    build ();
    while (q--) {
        int x,k;cin>>x>>k;
        cout <<kth (x,k) <<"\n";
    }
 
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
