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

int bigmod(int a, int b)
{
    if(b == 0) return 1;
    int x = bigmod(a, b / 2);
    x = (x * x) % mod;
    if(b & 1) x = (x * a) % mod;
    return x;
}

int inv(int a, int m)
{
    return bigmod(a, mod - 2);
}
 

void solve() {

    int n ;cin>>n ;
    int sm= n*(n+1)/2 ;
    if (sm&1) {
        cout <<0 <<"\n" ; return ;
    }
    vector < vector <int>> dp (n+1 , vector <int> (sm+1,0));
    dp[0][0]=1;
    sm/=2 ;

    for (int i = 1  ;i <= n; i++) {
        for (int j = 0; j <= sm; j++) {
            dp[i][j] =dp[i-1][j];
            if (j>=i) dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;        
        }
    }
    cout << (dp[n][sm]* inv (2,mod) ) % mod <<"\n" ;
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