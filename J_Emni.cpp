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
const int mod = 1e9 + 9;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[N];
int fact[N];

void calc()
{
    fact[1] = 1;
    for(int i = 2; i < N; i ++) {
        fact[i] = (fact[i - 1] * 2  + i);
        fact[i] %= mod;
    }
}

void solve() {
    int n; cin >> n;
    cout << fact[n] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc();
    //for (int i = 1 ; i <= 5 ; i++) cerr << fact[i] << " "; cerr << "\n";
    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}