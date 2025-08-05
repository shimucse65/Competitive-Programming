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
    int n,m ;cin >>n>>m ;
    int a[n][m] , sm[n];
    vector < pii>v;
    for (int i=0; i<n ;i++) {
        int cur=0;
        for (int j=0 ;j<m ;j++) {
            cin >> a[i][j];
            cur += a[i][j];
        }
        sm[i]= cur;
        v.push_back ({sm[i] ,i});
    }
    sort(v.rbegin () , v.rend ());
    // for (auto it :v) cerr << it.ff <<" " << it.ss <<"\n";

    int cur= n*m;
    int res=0;
    for (auto [sm, i] : v) {
        for (int j=0;j<m ;j++) {
            res += a[i][j] * cur; cur--;
        }
    }
    cout << res <<"\n";    
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