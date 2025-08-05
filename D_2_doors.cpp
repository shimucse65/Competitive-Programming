#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<pii> g[n + 1];
    vector<int> ans(n + 1);
    vector<array<int, 3>> edges(m);
    for(auto &[u, v, c] : edges) {
        cin>>u>>v>>c;
        if(u == v) ans[u] = c;
        if(u > v) swap(u, v);
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    for(int i = 30; i >= 0; i--) {
        vector<bool> bad(n + 1);
        for(int u = 1; u <= n; u++) {
            for(auto [v, c] : g[u]) {
                if(!(c >> i & 1)) {bad[u] = true; break; }
            }
        }

        for(int u = 1; u <= n; u++) {
            if(bad[u]) continue;
            for(auto [v, c] : g[u]) {
                if(bad[v]) {
                    ans[u] |= (1LL << i);
                    break;
                }
            }
            if(ans[u] >> i & 1) continue;
            for(auto [v, c] : g[u]) {
                ans[v] |= (1LL << i);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<" \n"[i == n];
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