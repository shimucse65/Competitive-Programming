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

bool vis[1010][20];
int ans = inf;
vector <pii>g[1010];
int  n , m;

void dfs (int node , int xr) {
    vis[node][xr] = 1;
    if (node == n) ans = min (ans , xr);

    for (auto [v,w] : g[node]) {
        if (!vis[v][xr ^ w]) dfs (v , xr ^ w);
    }
}
void solve() {
   cin >>n >> m;
   for (int i = 0 ;i < m; i++) {
     int u, v, w; cin >> u >> v >> w;
     g[u].push_back({v, w});
   }
   dfs (1,0);
   if (ans == inf) ans = -1 ;
   cout << ans <<"\n";
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