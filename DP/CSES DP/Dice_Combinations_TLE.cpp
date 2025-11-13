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
const int N = 1e6 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[N] ;
int magic (int n) {
    
    if (n==0 ) return 1 ;
    if (~dp[n]) return dp[n] ;

    int ans=0 ;
    for (int i=1 ;i<=6 ;i++) {
        if (n-i >=0) {
            ans= ans+ magic (n-i) ;
            ans%= mod ;
        }
    }
    return ans ;
}
void solve() {
    int n ;cin>>n ;
    memset (dp ,-1 ,sizeof dp) ;
    cout << magic (n) <<"\n" ;    
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