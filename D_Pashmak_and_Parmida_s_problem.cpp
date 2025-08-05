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

    int n; cin >> n;
    vector<int>a(n);
    int mx = -1;
    for(int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
    o_set<pii> st;
    int pf[n], sf[n];

    vector<int>mp(mx + 1, 0);
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
        pf[i] = mp[a[i]];
    }

    vector<int>mpb(mx + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        mpb[a[i]]++;
        sf[i] = mpb[a[i]];
        st.insert({sf[i], i});
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        st.erase({sf[i], i});
        cnt += st.order_of_key({pf[i], 0});      
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