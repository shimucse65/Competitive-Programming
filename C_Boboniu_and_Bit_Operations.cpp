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
    int n,m;cin>>n>>m;
    int a[n] ,b[m];
    for (int i=0 ;i<n ;i++) cin>>a[i];
    for (int i=0 ;i<m ;i++) cin>>b[i];

    int dp[n][m];

    for (int i=0 ;i <n ;i++) {
        for (int j=0 ;j<m ;j++) {
            dp[i][j] = (a[i] & b[j]);
        }
    }

    // for (int i=0 ;i<n ;i++ ) {
    //     for (int j=0 ;j<m ;j++) cerr << dp[i][j] <<" ";
    //     cerr <<"\n";
    // }

    for (int ans=0 ; ans < 512 ; ans++) {
        int cnt=0;
        for (int i=0 ;i<n ;i++) {
            for (int j=0 ; j<m ;j++) {
                if ((dp[i][j] | ans)==ans) {
                    cnt++ ; break;
                }
            }
        }
        if (cnt==n) {
            cout << ans <<"\n"; return;
        }
    }
    
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