#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    o_set <int> st;
    for(int i = 1; i <=n ; i++) st.insert(i);
    
    vector <int>mp (n + 1, 0);
    for(int i = n - 1 ;  i >= 0; i--) {
        mp[v[i]] = i + 1;
    }

    int cur = -1;
    while(q--) {
        int x  ; cin >> x;
        int pp = mp[x];
        int pos = st.order_of_key(pp) + 1;
        cout << pos << "\n";
        
        st.erase(st.find (pp));
        mp[x] = cur;
        st.insert(cur); cur--;
    }
    cout << "\n"; 
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
