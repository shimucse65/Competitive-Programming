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
const int N = 3e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>g[N] ;
int up[N] ,down[N] ;

void dfs_down (int node ,int p) {
    for (auto it:g[node]) {
        if (it==p) continue;
        dfs_down (it ,node) ;
        down [node]= max (down[node] ,down[it]+1) ;
    }
}

void dfs_up (int node ,int p) {
    vector <int>pf ,sf ;
    for (auto it :g[node]) {
        if (it==p) continue ;
        pf.push_back (down[it]);
        sf.push_back (down [it]);
    }
    int sz= pf.size () ;

    for (int i=1 ;i<sz;i++) pf[i]= max (pf[i], pf[i-1]);
    for (int i=sz-2 ;i>=0;i--) sf[i]= max (sf[i], sf[i+1]);
    int i=0 ;
    for (auto it :g[node]) {
        if (it==p) continue ;
        int l=  (i-1 >=0) ? pf[i-1]:-1 ;
        int r= (i+1 <sz) ? sf[i+1]:-1 ;

        up[it]= max (up[it],2+ max (l,r)) ;
        up[it]= max (up[it] , 1+ up[node]);
        i++ ;
        dfs_up (it , node) ;
    }
}

void solve() {
    int n ; cin>>n ;
    for (int i=0 ;i<n-1 ;i++) {
        int x,y ;cin>>x>>y ;
        g[x].push_back (y) ;
        g[y].push_back (x) ;
    }
    dfs_down (1,0) ;
    dfs_up (1,0) ;

    int mx=0 ;
    for (int i=1 ;i<=n ;i++) {
        mx= max (mx , up[i]+ down[i]) ;
    }
    for (int i=1 ;i<=n ;i++) {
        int ans= mx ;
        ans= max (ans ,up[i]+1) ;
        ans= max (ans , down[i]+1);
        cout <<ans <<"\n" ;
    }

    
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