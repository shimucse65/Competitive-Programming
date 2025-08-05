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

int distance (pii a, pii b) {
    return (a.ff - b.ff)* (a.ff - b.ff) + (a.ss - b.ss)* (a.ss - b.ss);
}
void solve() {
    int n; cin >> n;
    vector<array<int,3>> v;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y, i});
    }
    sort(v.begin(), v.end());
    pii ans = {-inf, -inf};
    set<array<int,3>> st;
    int dis = inf;
    int j = 0;
    for (auto [x, y, i] : v) {
        while (j < n && v[j][0] < x - sqrt(dis)) {
            st.erase ({v[j][1], v[j][0], v[j][2]});
            j++;
        }
        auto id1 = st.lower_bound({y - dis, -inf, -inf});
        auto id2 = st.upper_bound({y + dis, inf, inf});

        for (auto k = id1; k != id2; k++) {
            pii a = {x,y};
            pii b = {(*k)[1], (*k)[0]};
            if (distance (a,b) < dis) {
                dis = distance (a,b);
                ans.ff = (*k)[2];
                ans.ss = i;
            }
        }
    }
    cout << fixed << setprecision(6);
    cout << ans.ff << " " << ans.ss << " " << sqrt(dis) << "\n";   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}