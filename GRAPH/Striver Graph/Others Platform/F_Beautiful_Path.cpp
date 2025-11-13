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
const double eps = 1e-10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<array<int, 3>> g[N];
double dp[N];

bool f(double x) {
    for(int i = 0; i <= n; i++) dp[i] = -1e18;
    dp[1] = 0;
    for(int u = 1; u < n; u++) {
        for(auto [v, b, c] : g[u]) {
            dp[v] = max(dp[v], dp[u] + b - x * c);
        }
    }
    return dp[n] >= 0;
}

void solve() {
    cin>>n>>m;
    while(m--) {
        int u, v, b, c; cin>>u>>v>>b>>c;
        g[u].push_back({v, b, c});
        g[v].push_back({u, b, c});
    }

    double l = 0, r = 1e18, best = 0;

    while(r - l >= eps) {
        double mid = (l + r) / 2;
        if(f(mid)) {
            best = mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    cout<<fixed<<setprecision(10)<<best<<endl;
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