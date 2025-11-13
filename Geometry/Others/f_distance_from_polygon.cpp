#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define double long double
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
    double x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    double aa = a * x + b * y + c;
    double bb = sqrt(a * a + b * b);
    cout << setprecision(10) << fixed << aa / bb * 1.0;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("distance1.in", "r")) {
        freopen("distance1.in", "r", stdin);   
        freopen("distance1.out", "w", stdout);
    }

    int t = 1, c = 1;// cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}