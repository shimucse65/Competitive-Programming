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
    int x,y;cin >> x>>y;

    set < pii >st ;

    for (int i=1 ; i<=6 ;i++){
        for (int j=1 ; j<=6 ;j++){
            if (i+j >= x) {
                st.insert ({i,j});
            } else if (abs (i-j) >= y) st.insert ({i,j});
        }
    }
    //cerr << st.size () <<"\n";
    cout << setprecision (10) << fixed <<" " << (st.size ()/ (36*1.0)) <<"\n";
    
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