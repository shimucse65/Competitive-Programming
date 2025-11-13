#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int LOG = 30;  
vector<int> g[N];
int par[N], level[N], val[N];
int table[N][LOG];

void reset(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = 0;
        level[i] = 0;
        g[i].clear();
        val[i] = 0;
        for (int j = 0; j < LOG; j++) {
            table[i][j] = -1;
        }
    }
}

void dfs(int v, int p = -1) {
    par[v] = p;
    for (auto child : g[v]) {
        if (child == p) continue;
        level[child] = level[v] + 1;
        dfs(child, v);
    }
}

void dfs1(int node, int par) {
    int x = val[node];
    for (auto it : g[node]) {
        if (it == par) continue;
        dfs1(it, node);
        x += val[it];
    }
    val[node] = x;
}

void build(int n) {
    dfs(1);  
    for (int i = 1; i <= n; i++) table[i][0] = par[i];

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][j - 1] != -1) {
                int x = table[i][j - 1];
                table[i][j] = table[x][j - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (level[a] > level[b]) swap(a, b);
    int d = level[b] - level[a];

    while (d > 0) {
        int i = log2(d);
        b = table[b][i];
        d -= (1 << i);
    }
    if (a == b) return a;
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (table[a][i] != table[b][i]) {
            a = table[a][i];
            b = table[b][i];
        }
    }
    return table[a][0];
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build(n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int x = lca(a, b);
         cout <<  (level[a]- level[x] )+ ( level[b]- level[x] ) <<"\n";

    }

  
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
