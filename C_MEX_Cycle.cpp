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
vector <int>g[N];
int vis[N] ,res[N];
int dp[N][3];

void reset (int n) {
    for (int i=0 ;i<=n;i++) {
        g[i].clear ();
        vis[i]=0;
        res[i]=0;
    }
}

void dfs (int u) {
    vis[u]=1 ; 
    int ache=-1 ;
    for (int i=0 ;i<=2;i++) {
        if (dp[u][i]!=-1) {
            ache=i ; break;
        }
    }
    res[u]= ache;
    for (auto it :g[u]) {
        dp[it][ache]=-1;
    }
    for (auto it :g[u]) {
        if (!vis[it]) dfs (it);
    }
}
void solve() {
   
    int n ,u,v;cin>>n>>u>>v;
    reset (n);
    for (int i=1 ;i<=n ;i++) {
        if (i==1) {
            g[i].push_back (2);
            g[2].push_back (i);
            g[i].push_back (n);
            g[n].push_back (i);

        } else if (i==n) {
             g[n].push_back (1);
             g[1].push_back (n);
             g[n].push_back (n-1);
             g[n-1].push_back (n);

        } else {
             g[i].push_back (i+1);
             g[i+1].push_back (i);
             g[i].push_back (i-1);
             g[i-1].push_back (i);
        }
    }
     g[u].push_back (v);
     g[v].push_back (u);
     memset (dp ,0 ,sizeof dp); 
     dp[u][1]=-1 , dp[u][2]=-1;
     dfs (u);
     for (int i=1 ;i<=n ;i++) cout << res[i] <<" "; cout <<"\n";    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}