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
const int N = 1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[N][N] ;
int n ;
char a[N][N] ;

void solve() {
    cin>>n ;
    for (int i=0 ;i<n ;i++) {
        for (int j=0 ;j<n ;j++) cin>>a[i][j] ;
    }
    if (a[0][0]!='*') dp[0][0]=1 ;

    for (int i=0 ;i<n ;i++) {
        for (int j=0 ;j<n ;j++) {
            if (a[i][j]=='*') continue ;
            if (i+1 <n && a[i+1][j]!='*') dp[i+1][j]= (dp[i+1][j]+ dp[i][j])%mod ;
            if (j+1 <n && a[i][j+1]!='*') dp[i][j+1]= (dp[i][j+1]+ dp[i][j])%mod ;
        }
    }
    cout << dp[n-1][n-1] <<"\n" ;
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