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
const int N = 2010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[N][N];

void solve() {

    int n ; cin >>n ;
    int a[n];
    for (int i=0;i<n;i++) cin >>a[i];

    for (int i=0;i<n;i++){
        for (int j=0;j<n ;j++) dp[i][j]=0;
    }

    for (int j=0 ;j<=n ;j++) {
        map <int ,int>mp;
        for (int i=0 ; i<n ;i++) {
            dp[i][j]= a[i] ; mp[a[i]]++;
        }
        for (int i=0 ;i<n ;i++) a[i]= mp[a[i]];
    }
    int q; cin >>q ;
    while (q--) {
        int ind , stp ; cin >> ind >> stp ; ind--;
        if (stp > n) cout << dp[ind][n] <<"\n";
        else cout << dp[ind][stp] <<"\n";
    }
    
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