#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl '\n'
#define lc (ind << 1)
#define rc (ind << 1 | 1)

using namespace std;
const int N = 4e5 + 10;
int seg[4 * N];
int n, q;
string s;

void build(int ind, int lo, int hi) {
    if (lo == hi) {
        seg[ind] = (1LL << (s[lo - 1] - 'a')); 
    } else {
        int mid = (lo + hi) / 2;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        seg[ind] = seg[lc] | seg[rc];
    }
}

void update(int ind, int lo, int hi, int pos, int val) {
    if (lo == hi) {
        seg[ind] = val;
        return;
    }
    int mid = (lo + hi) / 2;
    if (pos <= mid) update(lc, lo, mid, pos, val);
    else update(rc, mid + 1, hi, pos, val);
    seg[ind] = seg[lc] | seg[rc];
}

int query(int ind, int lo, int hi, int l, int r) {
    if (hi < l || lo > r) return 0;
    if (l <= lo && hi <= r) return seg[ind];
    int mid = (lo + hi) / 2;
    return query(lc, lo, mid, l, r) | query(rc, mid + 1, hi, l, r);
}

void solve() {
    cin >> n >> s >> q;
    build(1, 1, n); 

    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int id; char c;
            cin >> id >> c;
            update(1, 1, n, id, (1LL << (c - 'a'))); 
        } else {
            int l, r;
            cin >> l >> r;
            int result = query(1, 1, n, l, r);
            cout << __builtin_popcountll(result) << endl; 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
