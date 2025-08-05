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
    for (int i = 0 ; i < n ;i++) cin >> a[i];
    
    int mn[n]; 
    mn[0] = a[0];
    int sm = 0;
    sm += a[0];
    for(int i = 1; i < n; i++) {
        mn[i] = min (mn[i - 1], a[i]);
        sm += mn[i];
    }
    
    int pf [n]; pf[0] = a[0];
    for(int i = 1; i < n; i++) {
        pf [i] = pf[i - 1] + mn[i];
    }
    
    int ans = sm ;
    for (int i = 1 ; i < n ;i++) {
       if ( i == 1) {
         ans = min (ans, a[0] + a[1]);
       }  else {
            int nn = pf[i - 2] + min (mn[i - 2], a[i] + a[i - 1]);
            ans = min(ans, nn);            
       }
    }
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