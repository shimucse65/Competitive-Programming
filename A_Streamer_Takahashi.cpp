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
    int n , l1 , r1 ; cin >> n >> l1 >> r1;
    int cnt = 0;
    set<int> st;
    for (int i = l1; i <= r1; i++) st.insert(i);
    for (int i =0 ; i < n ;i++) {
        int l2, r2; cin >> l2 >> r2;
        int f = 0;
        for (int j = l2 ; j <= r2; j++) {
            if (st.count(j)) f++ ;
        }
        if (f >= st.size()) cnt++;      
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