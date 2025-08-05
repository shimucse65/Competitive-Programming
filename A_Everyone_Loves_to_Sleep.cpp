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
    int n,h,m; cin >>n >> h >>m;
    int tot1 = h*60 + m;    
    vector <pii > v;
    int mn = inf;
    while (n--) {
        int x,y; cin >> x>>y;
        int tot2 = x*60 + y;
        if (tot1 <= tot2 ) {
            mn = min (mn , tot2- tot1);
        } 
        else {
            int ex = (23*60 + 60) - tot1;
            mn = min ( tot2 + ex, mn);
        }      
    }
    cout << mn / 60 <<" " << mn % 60 <<"\n";

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