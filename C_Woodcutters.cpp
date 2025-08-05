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
    int  n ;cin>>n ;
    vector< pii>v ;
    for (int i=0;i<n;i++) {
        int l,r ;cin>>l>>r ;
        v.push_back ({l,r}) ;
    }
    int ans= min (n ,2ll) ;
    int pv= v[0].ff ;
    for (int i=1 ;i<n-1 ;i++) {
          int nxt= v[i+1].ff ;
        if (v[i].ff- v[i].ss >pv) {
            ans++ ;
            pv= v[i].ff ;
        } else {
            pv= v[i].ff ;
            if (v[i].ff+ v[i].ss <nxt) {
                ans++ ;
                pv= v[i].ff+ v[i].ss;
            }
        }

    }
    cout <<ans <<"\n" ;

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