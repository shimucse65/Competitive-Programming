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
    
    int n;cin >>n ;
    int a[n+1];
    for (int i= 1;i<=n ;i++) cin >> a[i];

    int mx = -1 , mi=-1;
    for (int i=1 ;i<=n ;i++) {
        if (a[i] > mx) {
            mx = a[i] ; mi=i;
        } else if (a[i] == mx) {
            mx = a[i];
            if (mi % 2==0) mi = i;
        }
    }
    if (mi % 2==0) {
        int ans = mx + (n-3)/2;
        cout << ans <<"\n"; return;
    }
    cout << mx + (n-1)/2 <<"\n";
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
