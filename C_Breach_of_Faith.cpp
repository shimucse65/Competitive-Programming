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
    int n; cin >>n ;
    int a[n*2];
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort (a, a+2*n);
    vector < int> res;
    int sm=0;
    for (int i= 1 ;i < n ;i++) {
        res.push_back (a[i]);
        res.push_back (a[i + n-1]);
        sm += a[i+n-1] - a[i];
    }
    res.push_back (a[2*n - 1] + a[0] + sm);
    res.push_back (a[0]);

    cout << a[2*n-1] <<" ";
    for (auto it : res) cout << it <<" " ; cout <<"\n";


    
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