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

class DisjointSet {
public:
    vector<int> rank, parent, sz;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }

    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ct(n + 1);
    for(int i = 1; i <= n; i++) cin >> ct[i].ff >> ct[i].ss;
    vector<int> c(n + 1), k(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> k[i];
    
    vector<pair<int, pii>> edges;
    for(int i = 1; i <= n; i++) edges.push_back({c[i], {0, i}});
    
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int dist = abs(ct[i].ff - ct[j].ff) + abs(ct[i].ss - ct[j].ss);
            int wt = dist * (k[i] + k[j]);
            edges.push_back({wt, {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int total_cost = 0;
    vector<int> pp;
    vector<pii> cc;
    
    for(auto edge : edges) {
        int wt = edge.ff;
        int u = edge.ss.ff, v = edge.ss.ss;
        if(ds.findPar(u) != ds.findPar(v)) {
            ds.unionBySize(u, v);
            total_cost += wt;
            if(u == 0 || v == 0) pp.push_back(max(u, v));
            else cc.push_back({u, v});
        }
    }
    
    cout << total_cost << endl;
    cout << pp.size() << endl;
    for(auto p : pp) cout << p << " ";
    cout << endl;
    cout << cc.size() << endl;
    for(auto c : cc) cout << c.ff << " " << c.ss << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1; //cin >> t;
    while(t--) {
        solve ();
    }
}
