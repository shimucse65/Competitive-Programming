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
    int n,k; cin >> n>> k;
    int a[n] , b[n];
    int mx = -inf, mn= inf;
    for (int i=0 ; i<n ;i++) {
        cin >> a[i];
        mx = max (mx, a[i]);
        mn = min (mn, a[i]);
    }
    int cnt =0;
    for (int i=0 ; i < n ;i++) {
        cin >> b[i];
        if (b[i] == -1) cnt++;
    }

    set <int> st;
    int sm = 0;
    for (int i = 0; i < n;i++) {
        if (b[i] == -1) continue;
        st.insert (a[i] + b[i]);
        sm = a[i] + b[i];
    }
    if (st.size() > 1) {
        cout << 0 <<"\n"; return;
    }
    for (int i = 0; i < n; i++){
        if (sm - a[i] > k ) {
            cout << 0 <<"\n"; return;
        }
    }
    if (cnt < n) {
        for (int i=0 ; i < n ;i++) {
            if (sm < a[i]) {
                cout << 0 <<"\n"; return;
            }
        }
        cout << 1 <<"\n";
        return;
    }

    cout << mn + k - mx + 1 <<"\n";   
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