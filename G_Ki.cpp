#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>g[N] ;
int ans[N];

void dfs (int node ,int p) {
    for (auto it :g[node]) {
        if (it==p) continue ;
        ans[it]+= ans[node] ;
        dfs (it ,node) ;
    }
}

void solve() {
    int n,q ;cin>>n>>q ;
    for (int i=0 ;i<n-1 ;i++) {
        int u,v ;cin>>u>>v ;
        g[u].push_back (v) ;
        g[v].push_back (u) ;
    }
    while (q--) {
        int node ,val ;cin>>node >>val ;
        ans[node]+=val ;      
    }
    dfs (1,-1) ;
    for (int i=1 ;i<=n ;i++) cout <<ans[i] <<" " ; cout <<"\n" ;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}