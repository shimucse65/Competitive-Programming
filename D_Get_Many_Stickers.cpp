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


bool cmp (pii & a, pii & b) {
    if (a.ss != b.ss) return a.ss > b.ss;
    return a.ff < b.ff;
}

void solve() {

    int n, m; cin >> n >> m;
    vector<pii >v;
    for(int i=0 ; i < m ;i++) {
        int x,y ; cin >> x >> y;
        v.push_back ({x, y});
    }
    sort(v.begin(), v.end(), cmp);

    int cnt  = 1;
    for(int i = 0; i < m ;i++) {
        int l = 1 , r = v[i].ff;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r -l)/2;
            if ( (n - mid * (v[i].ff - v[i].ss) + 1) >= v[i].ff) {
                ans = mid ; l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        cnt += ans;
        n -= ans * (v[i].ff - v[i].ss);
    }
    cout << cnt << "\n";
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