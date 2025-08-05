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
    int a[n], b[n];
    for (int i=0;i<n ;i++) cin >> a[i];
    for (int i=0 ;i<n ;i++) cin >>b[i];

    vector <int>v ,vv;
    int cnt=0;
    for(int i=0;i<n ;i++) {
        if(a[i] > 0) {
            cnt++;
        } else {
            v.push_back (cnt); cnt=0;
        }
    }
    v.push_back (cnt);
    sort (v.rbegin () , v.rend ());

    cnt=0;
    for(int i=0;i<n ;i++) {
        if(b[i] > 0) {
            cnt++;
        } else {
            vv.push_back (cnt); cnt=0;
        }
    }
    vv.push_back (cnt);
    sort (vv.rbegin () , vv.rend ());

    if (v[0] > vv[0]) cout <<"Om" <<"\n";
    else if (v[0] < vv[0] ) cout <<"Addy" <<"\n";
    else cout << "Draw" <<"\n";    
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