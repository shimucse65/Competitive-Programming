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

bool isprime (int n) {
    if (n < 2) return false ;
    for (int i = 2 ; i*i <= n ;i++) {
        if (n % i==0) return false;
    }
    return true;
}
void solve() {
    int n, k; cin >>n >> k;
    if (k == 1) {
        if (isprime (n)) cout << "YES\n";
        else cout <<"NO\n";
        return;
    }
    if (n == 1) {
        int x = n;
        for(int i = 0; i < k - 1; i++) x = 10 * x + 1;
        if (isprime (x)) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    cout <<"NO\n";
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