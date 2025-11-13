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
    int n,k;cin>>n>>k ;
    vector <int> weight(n+1) ;
    vector <int>val (n+1) ;
    for (int i=1 ;i<=n ;i++) cin>>weight[i] ;
    for (int i=1 ;i<=n ;i++) cin>>val[i] ;

    vector <int> prev (k+1,0) ;

    for (int i=1 ;i<=n ;i++) {
        vector <int> cur (k+1 ,0) ;
        for (int j=k ;j>=0 ;j--) {
            int w= weight[i] ;
            int vv= val[i] ;

            int not_pick= prev[j] ;
            int pick= (j>=w ?prev[j-w]+ vv :0) ;
            cur[j] = max (pick , not_pick) ;
        }
        prev= cur ;
    }
    cout << prev[k] <<endl ;
    
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