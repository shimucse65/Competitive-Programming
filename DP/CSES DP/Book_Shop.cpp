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
    int n, k;
    cin >> n >> k;
    vector<int> price(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++) cin >> price[i];
    for (int i = 1; i <= n; i++) cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int op1 = dp[i - 1][j];
            int op2 = (j >= price[i]) ? dp[i - 1][j - price[i]] + val[i] : 0;
            dp[i][j] = max(op1, op2);
        }
    }

    cout << dp[n][k] << "\n";
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