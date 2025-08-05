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
    int a[n];
    multiset<int> st;
    for(int i =0; i < n ;i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    sort(a, a + n);
    int mx = 0;
    for(int i= 0; i < n ;i++) {
        for (int j = 0 ; j < n ; j++) {

            if (i == j) continue;
            int sm = a[i] + a[j];
            st.erase(st.find(a[i]));
            st.erase(st.find (a[j]));

            auto it  = st.lower_bound(sm);
            if (it != st.begin()) {
                it -- ;
                mx = max (mx, *it);
            }

            auto it2 = st.upper_bound(sm);
            if(it2 != st.end()) {
                 mx = max (mx, (*it2) % sm);
            }
            st.insert(a[i]);
            st.insert(a[j]);
        }
    }
    cout << mx << "\n";   
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