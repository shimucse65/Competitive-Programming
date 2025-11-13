#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>

using namespace std;
const int mod =  998244353;
const int inf = 1e18 + 10;


int bigmod(int a, int b) {
    if (b == 0) return 1;
    int x = bigmod(a, b / 2);
    x = (x * x) % mod;
    if (b & 1) x = (x * a) % mod;
    return x;
}

int inv(int a) {
    return bigmod (a, mod - 2);
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> va = a, vb = b; 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * min(a[i], b[i])) % mod;
    }

    cout << ans << " ";

    for (int i = 0; i < q; i++) {
        int ty, ind;
        cin >> ty >> ind;
        ind--;

        if (ty == 1) {
            int ii = upper_bound(a.begin(), a.end(), va[ind]) - a.begin() - 1;
            ans = (ans * inv(min(a[ii], b[ii]))) % mod;
            va[ind]++;
            a[ii]++;
            ans = (ans * min(a[ii], b[ii])) % mod;

        } else {
            int ii = upper_bound(b.begin(), b.end(), vb[ind]) - b.begin() - 1;
            ans = (ans * inv(min(a[ii], b[ii]))) % mod;
            vb[ind]++;
            b[ii]++;
            ans = (ans * min(a[ii], b[ii])) % mod;
        }
        cout << ans << " ";     
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
