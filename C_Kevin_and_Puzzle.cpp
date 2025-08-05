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
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n ;
int a[N];
int dp[N][2];

int f (int ind , int tr , int cnt) {
    if (ind== n) return 1;
    if (dp[ind][tr] !=-1) return dp[ind][tr]; 

    int ans=0;
    if (tr) {
          if (cnt== a[ind]) ans +=  f (ind+1 , 1 ,cnt), ans %= mod;
          ans+= f (ind+1 , 0 ,cnt + 1), ans %= mod;
    } 
    else {
        if (cnt== a[ind]) ans +=  f (ind+1 , 1 ,cnt), ans %= mod;
    }
    return dp[ind][tr]= ans;

}

void solve() {
    cin>>n;
    for (int i=0 ;i<n ;i++) cin>> a[i];
    memset (dp , -1 ,sizeof dp);
    cout << f (0 ,1 ,0) <<"\n"; 
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