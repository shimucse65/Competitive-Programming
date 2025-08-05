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

// 1 i x -> upd
// 2 i x -> add
// 3 l r -> sum

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    BIT bit(n);
    for(int i = 1; i <= n; i++) bit.upd(i, v[i - 1]);

    int q; cin >> q;
    while(q--) {
        int ty; cin >> ty;
        if(ty == 1) {
            int x, val; cin >> x >> val; 
            bit.upd(x, val);
        } else if(ty == 2) {
            int x, val; cin >> x >> val; 
            bit.add(x, val);
        } else {
            int l, r; cin >> l >> r; 
            cout << bit.qur(l, r) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; // cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}