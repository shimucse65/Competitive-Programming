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
const int N = 1e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <pii> g[N];
int n, k;
int mx;
int vis[N];

int dfs (int u) {
    vis[u] = 1;
    for (auto it : g[u]) {
        int v = it.ff;
        int wt = it.ss;
        mx = max (mx, wt);
        if (!vis[v]) dfs (v);
    }
    return mx;
}

void reset (int n) {
    for(int i=0; i < n ; i++) {
        g[i].clear();
        vis[i] =0;
    }
    mx = 0;
}
void solve() {
     cin >> n >> k;
     reset(n);
    for (int i =0; i < n;i++) {
        int x,y, wt; cin >>  x >> y >> wt;
        g[x].push_back({y, wt});
        g[y].push_back ({x, wt}); 
    }
    int mx = dfs(k);
    cout << mx << "\n";
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