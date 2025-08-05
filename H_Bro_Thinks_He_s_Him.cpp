
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
const int mod =  998244353;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int modPow(int base, int exp) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

struct segtree {
    vector<int> seg;
    segtree() { seg.assign(1000005, 0); }

    void build(int ind, int lo, int hi) {
        if (lo == hi) { seg[ind] = 0; return; }
        int mid = (lo + hi) / 2;
        build(ind * 2, lo, mid);
        build(ind * 2 + 1, mid + 1, hi);
        seg[ind] = (seg[ind * 2] + seg[ind * 2 + 1]) % mod;
    }

    void update(int ind, int lo, int hi, int pos, int val) {
        if (hi < pos || lo > pos) return;
        if (lo == hi) { seg[ind] = val % mod; return; }
        int mid = (lo + hi) / 2;
        update(ind * 2, lo, mid, pos, val);
        update(ind * 2 + 1, mid + 1, hi, pos, val);
        seg[ind] = (seg[ind * 2] + seg[ind * 2 + 1]) % mod;
    }

    int query(int ind, int lo, int hi, int qs, int qe) {
        if (hi < qs || lo > qe) return 0;
        if (qs <= lo && qe >= hi) return seg[ind];
        int mid = (lo + hi) / 2;
        return (query(ind * 2, lo, mid, qs, qe) + query(ind * 2 + 1, mid + 1, hi, qs, qe)) % mod;
    }
} pf0, pf1, sf0, sf1;

void solve() {
    string s;
    cin >> s;
    s = '0' + s;
    int n = s.size() - 1;

    pf0.build(1, 1, n);
    sf0.build(1, 1, n);
    pf1.build(1, 1, n);
    sf1.build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        int lval = modPow(2, i - 1), rval = modPow(2, n - i);
        if (s[i] == '0') {
            pf0.update(1, 1, n, i, lval);
            sf0.update(1, 1, n, i, rval);
        } else {
            pf1.update(1, 1, n, i, lval);
            sf1.update(1, 1, n, i, rval);
        }
    }

    int ans = (modPow(2, n) - 1 + mod) % mod;

    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            ans = (ans + modPow(2, i - 1) * sf1.query(1, 1, n, i + 1, n)) % mod;
        } else {
            ans = (ans + modPow(2, i - 1) * sf0.query(1, 1, n, i + 1, n)) % mod;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int lval = modPow(2, x - 1), rval = modPow(2, n - x);

        if (s[x] == '0') {
            ans = (ans - lval * sf1.query(1, 1, n, x + 1, n) + lval * sf0.query(1, 1, n, x + 1, n)) % mod;
            ans = (ans - rval * pf1.query(1, 1, n, 1, x - 1) + rval * pf0.query(1, 1, n, 1, x - 1)) % mod;

            s[x] = '1';
            pf0.update(1, 1, n, x, 0);
            pf1.update(1, 1, n, x, lval);
            sf0.update(1, 1, n, x, 0);
            sf1.update(1, 1, n, x, rval);
        } else {
            ans = (ans + lval * sf1.query(1, 1, n, x + 1, n) - lval * sf0.query(1, 1, n, x + 1, n)) % mod;
            ans = (ans + rval * pf1.query(1, 1, n, 1, x - 1) - rval * pf0.query(1, 1, n, 1, x - 1)) % mod;

            s[x] = '0';
            pf1.update(1, 1, n, x, 0);
            pf0.update(1, 1, n, x, lval);
            sf1.update(1, 1, n, x, 0);
            sf0.update(1, 1, n, x, rval);
        }
        cout << (ans + mod) % mod << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
