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
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }

    vector<int> cnt(30);

    for (int x : a) {
        for(int i = 0; i < 30; i++) if(x >> i & 1) {
            cnt[i]++;
        }
    }
    
    int mx = -inf, mxVal = -1;

    for(int x : a) {
        int cur = 0;
        for(int i = 0; i < 30; i++) {
            if(x >> i & 1) {
                cur -= (1LL << i) * cnt[i];
                cur += (1LL << i) * (n - cnt[i]);
            } else {
                cur += (1LL << i) * cnt[i];
                cur -= (1LL << i) * (n - cnt[i]);
            }
        }
        if(cur > mx) mx = cur, mxVal = x;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] ^ mxVal);
    }

    cout << max(sum, ans) << "\n";
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