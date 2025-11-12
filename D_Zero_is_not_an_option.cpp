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

    int n,m; cin >> n>>m ;
    int a[n][m];
    for(int i=0; i <n ;i++) {
        for(int j=0; j < m ;j++) cin >> a[i][j];
    }
   
    vector<int> row;

    for(int i= 0 ; i < n ; i++) {
        int tmp = 0;
        for(int j = 0; j < m ; j++) {
            tmp |= a[i][j];
        }
        row.push_back(tmp);
    }

    int tmp = (1 << 63) - 1;
    for(int i = 0; i < row.size(); i++) {
        tmp &= row[i];
    }
    if (tmp > 0) cout << "YES\n";
    else cout << "NO\n";
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