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

void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    map<int, int> mp;
    set<int> st;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
        if (x == y) {
            mp[x]++;
            st.insert(x);
        }
    }

    vector<int> tmp(st.begin(), st.end());

    for (int i = 0; i < n; i++) {
        if (v[i].ff == v[i].ss) {
            if (mp[v[i].ff] >= 2) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            auto l = lower_bound(tmp.begin(), tmp.end(), v[i].ff);
            auto r = lower_bound(tmp.begin(), tmp.end(), v[i].ss + 1);
            int range = v[i].ss - v[i].ff + 1;
            if (range == distance(l, r)) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
