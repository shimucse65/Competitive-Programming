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
int level[N] , par[N] ;
vector <int>g[N] ;
int dp[N][21] ;

void dfs (int node ,int p) {
    
    for (auto it :g[node]) {
        if (it==p) continue ;
        par[it]= node ;
        level[it]= level[node]+1 ;
        dfs (it ,node) ;
    }
}

void build (int n) {
    memset (dp ,-1 ,sizeof dp) ;
    dfs (1,-1) ;
    for (int i=1 ;i<=n;i++) dp[i][0]= par[i] ;

    for (int j=1 ;j<=20 ;j++) {
        for (int i=1 ;i<=n ;i++) {
            if (dp[i][j-1] !=-1) {
                dp[i][j] = dp[dp[i][j-1]][j-1] ;
            }
        }
    }
}

int lca (int a ,int b) {
    if (level[a] >level[b]) swap (a,b) ;
    int k= level[b]- level[a] ;

    for (int i=20 ;i>=0 ;i--) {
        if (k & (1<<i)) {
            b= dp[b][i] ;
        }
    }
    if (a==b) return a ;
    for (int i=20 ;i>=0 ;i--) {
        while (dp[a][i] != dp[b][i]) {
            a= dp[a][i] ;
            b= dp[b][i] ;
        }
    }
    return dp[a][0] ;
}

void solve() {
    int n , q;cin>>n>>q ;
    for (int i=2 ;i<=n ;i++) {
        int x ;cin>>x ;
        g[i].push_back (x) ;
        g[x].push_back (i) ;
    }
    build (n) ;
    while (q--) {
        int l ,r ;cin>>l>>r ;
        cout <<lca (l,r) <<"\n" ;
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