#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int n, q;
int size[N], heavy[N], parent[N], depth[N], head[N], pos[N];
int st[4*N], val[N], arr[N];
vector<int> g[N];
int idx = 1;

void build(int si, int ss, int se) {
    if (ss == se) {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    st[si] = max(st[2*si], st[2*si+1]);
}


void update(int si, int ss, int se, int qi, int newVal) {
    if (ss == se) {
        st[si] = newVal;
        return;
    }
    int mid = (ss + se) / 2;
    if (qi <= mid) update(2*si, ss, mid, qi, newVal);
    else update(2*si+1, mid+1, se, qi, newVal);
    st[si] = max(st[2*si], st[2*si+1]);
}


int query(int si, int ss, int se, int qs, int qe) {
    if (qs > se || qe < ss) return -1e9;
    if (qs <= ss && se <= qe) return st[si];
    int mid = (ss + se) / 2;
    return max(query(2*si, ss, mid, qs, qe), query(2*si+1, mid+1, se, qs, qe));
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
    arr[idx++] = val[node];
    if (heavy[node]) dfsHLD(heavy[node], chain);
    for (int child : g[node]) {
        if (child != parent[node] && child != heavy[node]) dfsHLD(child, child);
    }
}


int get_max(int a, int b) {
    int res = -1e9;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, query(1, 1, n, pos[head[a]], pos[a]));
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    return max(res, query(1, 1, n, pos[a], pos[b]));
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfsHLD(1, 1);
    build(1, 1, n);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            update(1, 1, n, pos[s], x);
            val[s] = x;
        } else {
            int a, b; cin >> a >> b;
            cout << get_max(a, b) << " ";
        }
    }
}

signed main() {
        ios_base::sync_with_stdio(false);
       
      solve();
    return 0;
}
