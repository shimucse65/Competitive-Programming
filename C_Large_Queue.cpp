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

    int q ; cin >> q;
    deque < pii > v;

    while (q--) {

        int ty; cin >> ty;
        if (ty == 1) {
            int x,y; cin >> x >> y;
            v.push_back ({x, y});
        } 
        else {
            int sm = 0;
            int k ; cin >>k;

           while (k > 0) {
            auto [cc, vv] = v.front();
            if (cc <= k) {
                k -= cc;
                sm += cc*vv;
                v.pop_front();
            } else {
                sm += k*vv;
                v.front().ff -= k;
                k = 0;
            }
           }
         cout << sm <<"\n";
        }
    }
    
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