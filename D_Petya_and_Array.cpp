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
    vector<int>a(n);
    for(auto &x : a) cin >> x;

    vector<int>pf(n, 0);
    o_set<pii>st;

    for(int i = 0; i < n ; i++) {
        if (i == 0) pf[i] = a[i];
        else pf[i] = pf[i - 1] + a[i];
        st.insert({pf[i], i});
    }
    for(auto it : st) cerr << it.ff << " " << it.ss <<"\n";
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x = 0;
        if (i == 0) x = k;
        else x = k + pf[i - 1];
        st.erase({pf[i], i});
        int tmp = st.order_of_key({x, 0});
        cerr << tmp << "\n";
        cnt += tmp;
    }
   cout << cnt << "\n";    
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