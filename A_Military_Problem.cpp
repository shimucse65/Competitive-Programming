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

vector<int> g[N];
vector <int> order, vis;
vector <int>sub;

void dfs (int u) {
    vis[u] = 1;
    sub[u] = 1;
    order.push_back(u);
    for (auto it : g[u]) {
        if (!vis[it]) dfs(it);
        sub[u] += sub[it];
    }
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 2 ; i <= n ; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }                        
    for (int i = 1 ; i <= n; i++) {
        sort (g[i].begin(), g[i].end());
    }
    order.clear(); vis.assign(n + 1, 0);
    sub.assign(n + 1, 0);
    dfs(1);
    map<int, int> mp, mpb;

    for(int i = 0; i < order.size(); i++) {
        mp[order[i]] = i + 1;
        mpb[i + 1] = order[i];
    }
    while(q--) {
        int u, k; cin >> u >> k;
        int id = mp[u];
        id = id + k - 1;
        if (sub[u] < k) cout << -1 <<"\n";
        else if(id > n) cout << -1 <<"\n";
        else cout << mpb[id] << "\n";        
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