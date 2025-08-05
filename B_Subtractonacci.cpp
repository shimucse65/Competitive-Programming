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
    int n,a,b; cin >>n>>a>>b;
    vector <int> v;
    v.push_back (a);
    v.push_back (b);
    for (int i = 2 ;i < 6 ; i++) {
        int x = (v[i-1] - v[i-2] + mod ) % mod;
        v.push_back (x);
    }
    int sm = 0;
    for (auto it :v) {
        sm += it;
        sm %= mod;     
    }
    int ans = 0;
    int tmp = n/6 ;
    ans += (tmp * sm);
    ans %= mod ;
    
    int baki= n- (tmp*6);

    for (int i = 0 ;i < baki; i++) {
        ans += v[i];
        ans %= mod;
    }
    if (ans < 0) ans = (ans + mod) % mod;
    cout << ans <<"\n";    
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