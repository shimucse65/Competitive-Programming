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
    string a, b;cin>>a>>b ;
    int n= a.size () ;
    int m= b.size () ;

    vector <vector <int>>dp (n+1 , vector <int> (m+1 ,inf)) ;

    for (int i = 0;i < n ;i++) dp[i][0] = i ;
    for (int j = 0 ;j < m ;j++) dp[0][j] = j ;

    for (int i = 1 ;i <= n ;i++) {
        for (int j = 1 ;j <= m ;j++) {
            if (a[i-1] == b[j-1]) dp[i][j]= dp[i-1][j-1];
            else {
                dp[i][j]= min (dp[i][j] , dp[i][j-1]+1) ;
                dp[i][j]= min (dp[i][j] , dp[i-1][j]+1);
                dp[i][j]= min (dp[i][j] , dp[i-1][j-1]+1);
            }
        }
    }
    cout << dp[n][m] <<"\n" ;
    
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