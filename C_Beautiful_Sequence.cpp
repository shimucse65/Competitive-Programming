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
int dp[N][5];
int n;
int a[N];
int f (int ind , int paisi) {
    if (ind == n) return paisi == 3;
    int &ans = dp[ind][paisi];
    if (~ans) return ans;

    int ans1 =0 , ans2 =0 ;
    if (paisi == 0) {
       if (a[ind] == 1) ans1 += f (ind + 1,1);
       ans1 %= mod;
    } else if (paisi == 1) {
       if (a[ind] == 2) ans1 += f (ind + 1, 2);
       ans1 %= mod;
    } else if (paisi == 2) {
        if (a[ind] == 2) ans1 += f (ind + 1, 2);
        ans1 %= mod;
        if (a[ind] == 3) ans1 += f (ind + 1, 3);
        ans1 %= mod;
    }
    ans2 += f (ind + 1, paisi);
    ans2 %= mod;

    ans = (ans1 + ans2) % mod;
    return ans;
}
void solve() {
    cin >>n ;
    for (int i = 0 ;i < n ;i++) cin >>a[i];
    int ans =0 ;
    for (int i = 0;i < n ;i++) {
        for (int j = 0 ;j < 5 ;j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << f (0 ,0) <<"\n";   
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