#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define pii pair<int, int>
using namespace std;

const int N = 2e5 + 10;
const int inf = 1e18 + 10;

vector<int> g[N];
int vis[N], low[N], tin[N];
int timer = 0;
set<int> ans;

void reset() {
    for (int i = 0; i < N; i++) {
        vis[i] = 0;
        low[i] = inf;
        tin[i] = 0;
        g[i].clear();
    }
    timer = 0;
    ans.clear();
}

void dfs(int node, int par) {
    vis[node] = 1;
    low[node] = tin[node] = timer++;
    int ch = 0;

    for (auto it : g[node]) {
        if (it == par) continue;
        if (vis[it]) {
            low[node] = min(low[node], tin[it]);
        } else {
            dfs(it, node);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && par != -1) ans.insert(node);
            ch++;
        }
    }
    if (ch > 1 && par == -1) ans.insert(node);
}

void solve() {
    int n, m;
    while (cin >> n >> m, n || m) {
        reset();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i, -1);
        }
        cout << ans.size() << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
