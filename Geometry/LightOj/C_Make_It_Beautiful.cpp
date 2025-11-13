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

int next(int x) {
    for (int i = 1; i < 32; ++i) {
        int val = (1 << i) - 1;
        if (val >= x) return val;
    }
    return -1; 
}

void solve() {
    int n; cin >>n ;
    int k;cin >>k;
    int a[n];
    for (int i=0;i<n ;i++) cin >> a[i];
    sort (a , a+n);

    vector <pii> dif;
    for (int i=0 ; i< n ;i++) {
        int tmp = next (a[i]);
        dif.push_back ({tmp - a[i] , a[i]});
    }
    sort (dif.begin () , dif.end ());
    int vv[n];
    for (int i=0 ; i< dif.size () ;i++) {
        if ( k < dif[i].ff) {
            vv[i]= a[i];
        }
        vv[i] = next (dif[i].ss);
        k -= dif[i].ff ;
    }
    for (int i=0 ; i< n ;i++) cerr << vv[i] <<" " ;cerr <<"\n";

    
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