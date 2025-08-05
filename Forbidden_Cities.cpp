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
vector<int> g[N], g1[N], g2[N];
bool u[N];
int tin[N], tout[N], fup[N], root[N], p[N];
int timer;

void dfs(int v) {
    tin[v] = fup[v] = ++timer;
    u[v] = 1;
    int c = 0;
    for (auto to : g[v]) {
        if (to == p[v]) continue;
        if (u[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            p[to] = v;
            root[to] = root[v];
            dfs(to);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v]) {
                g1[v].push_back(to);
            } else {
                g2[v].push_back(to);
            }
            c++;
        }
    }
    tout[v] = ++timer;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

  
    fill(tin, tin + N, 0);
    fill(tout, tout + N, 0);
    fill(fup, fup + N, 0);
    fill(root, root + N, 0);
    fill(u, u + N, false);

    for (int i = 1; i <= n; i++) {
        if (!u[i]) {
            root[i] = i;
            dfs(i);
        }
    }

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (root[a] != root[b]) {
            cout << "NO\n";
            continue;
        }

        bool ok = false;
        if (!g2[c].empty()) {
            bool f1 = false, f2 = false;
            if (tin[a] < tin[c] || tout[a] > tout[c]) {
                f1 = true;
            }
            if (tin[b] < tin[c] || tout[b] > tout[c]) {
                f2 = true;
            }
            for (auto to : g2[c]) {
                if (tin[to] <= tin[a] && tout[to] >= tout[a]) f1 = true;
                if (tin[to] <= tin[b] && tout[to] >= tout[b]) f2 = true;
            }
            if (f1 && f2) ok = true;
        } else if ((tin[a] < tin[c] || tout[a] > tout[c]) && (tin[b] < tin[c] || tout[b] > tout[c])) {
            ok = true;
        }

        for (auto to : g1[c]) {
            if (tin[to] <= tin[a] && tout[to] >= tout[a] &&
                tin[to] <= tin[b] && tout[to] >= tout[b]) {
                ok = true;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
}
