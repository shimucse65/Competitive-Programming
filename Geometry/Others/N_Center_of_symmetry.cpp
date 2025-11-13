#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<double, double>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >>n ;
    map <pii ,int > mp;
    vector <pii > v;
    double xx=0 ,yy=0;
    for (int i=0 ; i<n ;i++) {
        int x,y; cin >> x>>y;
        xx += x, yy+=y;
        v.push_back ({x,y});
        mp[{x,y}]=1 ;
    }
     double midx = (xx/n*1.0);
     double midy = (yy/ n*1.0);

    for (int i=0 ; i<n ;i++) {
        double p= 2*midx- v[i].ff;
        double q= 2*midy- v[i].ss;
        if (!mp.count ({p,q})) {
            cout <<"no\n"; return;
        }
    }
    cout <<"yes\n";   
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