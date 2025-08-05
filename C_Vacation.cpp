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
int n , a[N] ,b[N] ,c[N] ;
int dp[N][4] ;

int magic (int ind ,int last) {
    if (ind==n) return 0 ;
    if (dp[ind][last] !=-1) return dp[ind][last] ;

    int mx=0 ;
    if (last!=0) mx= max (mx , magic (ind+1 ,0)+ a[ind]) ;
    if (last !=1) mx= max (mx ,magic (ind+1,1)+ b[ind]) ;
    if (last !=2) mx= max (mx , magic (ind+1,2) + c[ind]) ;

    return dp[ind][last]= mx ;
}

void solve() {
    cin>>n ;
    for (int i=0;i<n;i++) cin>>a[i] >>b[i]>>c[i] ;
    memset (dp ,-1 ,sizeof dp) ;
    cout << magic (0, 3) ;
    
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