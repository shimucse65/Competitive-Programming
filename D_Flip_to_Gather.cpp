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
const int N = 1e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
string s;
int dp[N][3];

int magic (int ind, int f) {
    if (ind == n) return 0;
    int &ans = dp[ind][f];
    if (~ans) return ans;

    ans = inf;
    if (f == 0) {
        ans = min (ans, (s[ind] == '1') + magic(ind + 1, f));
        ans = min (ans, (s[ind] == '0') + magic(ind + 1, f + 1));
    } else if (f == 1) {
        ans = min (ans, (s[ind] == '0') + magic(ind + 1, f));
        ans = min (ans, (s[ind] == '1') + magic(ind + 1, f + 1));
    } else {
        ans = min (ans, (s[ind] == '1') + magic(ind + 1, f));
    }
    return ans;
}

void solve() {
    cin >> n >> s;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) dp[i][j] = -1;
    }
    cout << magic(0, 0) << "\n";
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