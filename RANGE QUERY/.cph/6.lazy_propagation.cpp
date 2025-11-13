#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

#define lc (id << 1)
#define rc (id << 1 | 1)

struct Node {
    int mn, cnt, lz; // {min, min_cnt, lz}
    Node() : mn(0), cnt(0), lz(0) {}
    Node(int n) : mn(n), cnt(0), lz(0) {}
};

int n, m;
vector<Node> seg(4 * N);

void push(int id, int l, int r) {
    seg[id].mn += seg[id].lz;
    if(l ^ r) {
        seg[lc].lz += seg[id].lz;
        seg[rc].lz += seg[id].lz;
    }
    seg[id].lz = 0;
}

void pull(int id) {
    seg[id].mn = min(seg[lc].mn, seg[rc].mn);
    seg[id].cnt = seg[lc].cnt * (seg[id].mn == seg[lc].mn) + seg[rc].cnt * (seg[id].mn == seg[rc].mn);
}

void build(int id = 1, int lo = 1, int hi = 2 * n) {
    if(lo == hi) {
        seg[id].mn = seg[id].lz = 0;
        seg[id].cnt = hi - lo + 1;
    } else {
        int mid = (lo + hi) / 2;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(id);
    }
}

void upd(int l, int r, int x, int id = 1, int lo = 1, int hi = 2 * n) {
    
    push(id, lo, hi);
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r) {
        seg[id].lz += x;
        push(id, lo, hi);
        return;
    }

    int mid = (lo + hi) / 2;
    upd(l, r, x, lc, lo, mid);
    upd(l, r, x, rc, mid + 1, hi);

    pull(id);
}

Node merge(Node x, Node y) {
    Node res = Node(0);
    res.mn = min(x.mn, y.mn);
    res.cnt = x.cnt * (x.mn == res.mn) + y.cnt * (y.mn == res.mn);
    return res;
}

Node query(int l, int r, int id = 1, int lo = 1, int hi = 2 * n) {
    push(id, lo, hi);
    if(l > hi || r < lo) return Node(INF);
    if(l <= lo && hi <= r) {
        return seg[id];
    }
    int mid = (lo + hi) / 2;
    return merge(query(l, r, lc, lo, mid), query(l, r, rc, mid + 1, hi));
}

void solve() {
    cin>>n>>m;
    vector<int> g[n + 1];
    
    for(int i = 0; i <= 4 * n; i++) seg[i] = Node();

    build();

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        upd(u, v - 1, +1);
    }
    
    int ans = n - 1;

    for(int i = 1; i <= n; i++) {
        auto q = query(i, i + n - 1);
        ans = min(ans, n - q.cnt * (q.mn == 0));

        for(auto j : g[i]) {
            upd(i, i + (j - i + n) % n - 1, -1);
            upd((j > i ? j : j + n), i + n - 1, +1);
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
