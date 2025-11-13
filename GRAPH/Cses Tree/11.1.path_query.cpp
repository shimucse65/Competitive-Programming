#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+10;
int size[N], heavy[N], parent[N], depth[N];
int head[N], lt[N], pos[N], idx, val[N];
vector<int> g[N];
int st[4*N];
int n, q;

void reset(int n) {
    for (int i = 0; i <=n; i++) {
        size[i] = heavy[i] = parent[i] = depth[i] = 0;
        head[i] = lt[i] = pos[i] = 0;
        val[i] = 0;
        g[i].clear();
    }
}

void build(int si, int ss, int se) {
    if (ss == se) {
        st[si] = lt[ss];
        return;
    }
    int mid = (ss + se) >> 1;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si] = st[2 * si] + st[2 * si + 1];
}

void update(int si, int ss, int se, int qi, int dx) {
    if (ss > qi || se < qi) return;
    if (ss == se) {
        st[si] += dx;
        return;
    }
    int mid = (ss + se) >> 1;
    update(2 * si, ss, mid, qi, dx);
    update(2 * si + 1, mid + 1, se, qi, dx);
    st[si] = st[2 * si] + st[2 * si + 1];
}

int query(int si, int ss, int se, int qs, int qe) {
    if (ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return st[si];
    int mid = (ss + se) >> 1;
    int L = query(2 * si, ss, mid, qs, qe);
    int R = query(2 * si + 1, mid + 1, se, qs, qe);
    return L + R;
}

void dfs(int node, int par) {
    size[node] = 1;
    parent[node] = par;
    for (auto child : g[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
        size[node] += size[child];
        if (size[child] > size[heavy[node]]) {
            heavy[node] = child;
        }
    }
}

void dfsHLD(int node, int chain) {
    head[node] = chain;
    lt[idx] = val[node];
    pos[node] = idx;
    idx++;
    if (heavy[node] != 0) {
        dfsHLD(heavy[node], chain);
    }
    for (auto it : g[node]) {
        if (it != parent[node] && it != heavy[node]) {
            dfsHLD(it, it);
        }
    }
}

int get_path_sum(int a, int b) {
    int sum = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) {
            swap(a, b);
        }
        sum += query(1, 1, n, pos[head[a]], pos[a]);
        a = parent[head[a]];
    }
    if (depth[a] < depth[b]) swap(a, b);
    sum += query(1, 1, n, pos[b], pos[a]);
    return sum;
}

void solve() {
    reset(n);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    idx = 1;
    dfsHLD(1, 1);
    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            int delta = y - val[x];
            update(1, 1, n, pos[x], delta);
            val[x] = y;
        } else {
            int x;
            cin >> x;
            cout << get_path_sum(1, x) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
