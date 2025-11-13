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

pii p0;

int ori(pii& a, pii& b, pii& c) {
    int o = (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff);
    if(!o) return 0;
    return o > 0 ? +1 : -1;
}

int dist(pii& a, pii& b) {
    int dx = a.ff - b.ff, dy = a.ss - b.ss;
    return dx * dx + dy * dy;
}

bool cmp1(pii& a, pii& b) {
    if(a.ss ^ b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

bool cmp2(pii& a, pii& b) {
    int o = ori(p0, a, b);
    if(!o) return dist(p0, a) < dist(p0, b);
    return o > 0;
}

vector<pii> hull(vector<pii>& v) {
    sort(v.begin(), v.end(), cmp1);
    p0 = v[0];

    
    sort(v.begin(), v.end(), cmp2);

    int id = v.size() - 1;
    while(id >= 0 && !ori(p0, v.back(), v[id])) --id;
    reverse(v.begin() + id + 1, v.end());

    vector<pii> ans;
    for(auto &it : v) {
        while(ans.size() > 1 && ori(ans.end()[-2], ans.end()[-1], it) < 0) ans.pop_back();
        ans.push_back(it);
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<pii> v(n);
    for(auto &[x, y] : v) cin >> x >> y;

    auto ans = hull(v);
    cout << ans.size() << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;
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