#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 1;

int n, a, b, mx, sz[N];
bool vis[N];
ll ans, ds[N];
vector<int> g[N];

void update(int idx, ll val) {
    for (int i = idx + 1; i <= n; i += -i & i) ds[i] += val;
}

ll query(int idx) {
    ll res = 0;
    for (int i = idx + 1; i > 0; i -= -i & i)
        res += ds[i];
    return res;
}

int getSize(int u = 1, int p = -1) {
    sz[u] = 1;
    for (int v : g[u])
        if (v != p && !vis[v])
            sz[u] += getSize(v, u);

    return sz[u];
}

int centroid(int u, int p, int n) {
    for (int v : g[u])
        if (v != p && !vis[v] && sz[v] > n / 2)
            return centroid(v, u, n);

    return u;
}

void dfs(int u, int p, bool flag, int d = 1) {
    if (d > b) return;

    mx = max(mx, d);
    if (flag) update(d, 1);
    else {
        ans += query(b - d);
        ans -= query(max(0, a - d) - 1);
    }

    for (int v : g[u])
        if (v != p && !vis[v])
            dfs(v, u, flag, d + 1);
}

void solve(int u = 1) {
    int c = centroid(u, -1, getSize(u));
    vis[c] = true;
    mx = 0;

    for (int v : g[c]) {
        if (!vis[v]) {
            dfs(v, c, false);
            dfs(v, c, true);
        }
    }
    for (int i = 1; i <= mx; i++)
        update(i, -query(i) + query(i - 1));

    for (int v : g[c])
        if (!vis[v])
            solve(v);
}

int main() {
    (void)scanf("%d %d %d", &n, &a, &b); 
    for (int i = 0, u, v; i < n - 1; i++) {
        (void)scanf("%d %d", &u, &v); 
        g[u].push_back(v);
        g[v].push_back(u);
    }

    update(0, 1);
    solve();
    printf("%lld\n", ans);
}
