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
const int mod = 998244353;
const int N = 3010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[N][N] ;
int a[N] ;
int n ,sm ;

int f (int ind , int sm) {
    if (sm==0) return n-ind+1 ;
    if (ind>=n) return 0ll ;

    if (dp[ind][sm]!=-1) return dp[ind][sm] ;

    int ans= f (ind+1 ,sm) ;
    if (sm-a[ind]>=0 ) {
        ans+= f (ind+1 ,sm- a[ind]);
    }
    return dp[ind][sm]= ans ;

}
void solve() {

    cin>>n>>sm ;
    memset (dp ,-1 ,sizeof dp) ;
    for (int i=0;i<n;i++) cin>>a[i] ;
    int ans=0 ;
    for (int i=0 ;i<n;i++) {
        ans= (ans+ f (i,sm)) %mod;     
    }
    cout << ans <<"\n" ;
    
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