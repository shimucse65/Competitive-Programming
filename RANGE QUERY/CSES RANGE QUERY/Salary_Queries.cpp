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

struct BIT {
    // 1 Based indexing
    int sz;
    vector<int> bit;
    BIT(int n) {
        sz = n + 1;
        bit = vector<int>(n + 1, 0);
    };

    void add(int x, int val) {
        for(int i = x; i < sz; i += i & -i) {
            bit[i] += val;
        }
    }

    int sum(int x) {
        int sm = 0;
        for(int i = x; i > 0; i -= i & -i) {
            sm += bit[i];
        }
        return sm;
    }

    int qur(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void upd(int x, int val) {
        add(x, -qur(x, x) + val);
    }
};

vector<int> vals;

int get(int x) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}

void solve() {
    int n, q; cin >> n >> q;
    int k = q;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vals = v;
    vector<pair<char, pii>> qq;
    while(q--) {
        char c;
        int x, y; cin >> c >> x >> y;
        qq.push_back ({c, {x, y}});
        if(c == '?') vals.push_back(x);
        vals.push_back(y);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    int mx = -1;
    for(int i = 1 ; i <= n; i++) {
        v[i] = get(v[i]);
        mx = max(mx, v[i]);
    }

    for(auto &[c, p] : qq) {
        if(c == '!') {
            p.ss = get(p.ss);
            mx = max(mx, p.ss);
        } else {
            p.ff = get(p.ff), p.ss = get(p.ss);
            mx = max({mx, p.ff, p.ss});
        }
    }

    BIT bit(mx + 1);
    for(int i = 1 ; i <= n; i++) bit.add(v[i], 1);

    for(int i = 0; i < k; i++) {
        char c = qq[i].ff;
        int a = qq[i].ss.ff, b = qq[i].ss.ss;
        
        if(c == '?') {
            cout << bit.qur(a, b) << "\n";
        } else {
            bit.add(v[a], -1);
            v[a] = b;
            bit.add(v[a], 1);       
        }
    }
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