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
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> v(n);
    v[0] = x;
    for(int i = 1; i <= n-1 ; i++) {
        v[i] = (v[i-1] * a + b) % c;
    }  
    int pf[n], sf[n];
    for (int i = 0; i < n; i++) {
        if (i % k == 0) pf[i] = v[i];
        else pf[i] = pf[i - 1] | v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i % k == k - 1 || i == n-1) {
            sf[i] = v[i];
        }
        else sf[i] = sf[i + 1] | v[i];
    }
    int xr = 0;
    for(int i = 0; i <= n - k; i++) {   
        int r = i + k - 1, l = i;
        int tmp = pf[r] | sf[l];
        xr ^= tmp;
    }
    cout << xr << "\n";
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