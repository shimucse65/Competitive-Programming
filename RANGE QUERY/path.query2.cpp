#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;
int n, q;
int size[N], heavy[N], parent[N], depth[N], head[N], pos[N];
int seg[2 * N], val[N], arr[N];
vector<int> g[N];
int idx = 1;

void build() {
    for (int i = n - 1; i > 0; --i) {
        seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
    }
}

void update(int p, int value) {
    for (seg[p += n] = value; p > 1; p >>= 1) {
        seg[p >> 1] = max(seg[p], seg[p ^ 1]);
    }
}

int query(int l, int r) {
    int res = LLONG_MIN;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

void dfs(int node, int par) {
    size[node] = 1;
    parent[node] = par;
    for (int child : g[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
        size[node] += size[child];
        if (size[child] > size[heavy[node]]) heavy[node] = child;
    }
}

void dfsHLD(int node, int chain) {
    head[node] = chain;
    pos[node] = idx;
    seg[idx + n] = val[node];
    idx++;
    if (heavy[node]) dfsHLD(heavy[node], chain);
    for (int child : g[node]) {
        if (child != parent[node] && child != heavy[node]) dfsHLD(child, child);
    }
}

int get_max(int a, int b) {
    int res = LLONG_MIN;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, query(pos[head[a]], pos[a] + 1));
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    return max(res, query(pos[a], pos[b] + 1));
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfsHLD(1, 1);
    build();

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            update(pos[s], x);
        } else {
            int a, b; cin >> a >> b;
            cout << get_max(a, b) << " ";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
