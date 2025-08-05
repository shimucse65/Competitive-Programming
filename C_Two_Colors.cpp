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
    int n,m; cin >>n >>m ;
    int a[m];
    for (int i=0 ;i < m ;i++) {
        cin >>a[i];
        a[i] = min (a[i] , n-1);
    }
    sort (a,a + m);
    int sf[m] ; sf[m-1]= a[m-1];
    for (int i = m - 2 ;i >= 0 ;i--) sf[i] = a[i] + sf[i+1];
   
    int ans=0;
    for (int i = 0 ;i < m - 1 ; i++) {
        int l = i + 1 , r = m ;
        int id = m ;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (a[i] + a[mid] >= n) {
                id = mid ; r = mid - 1;
            } else l = mid + 1;
        }
        if (id == m) ans += 0ll;
        else ans += ( a[i] - n + 1) * (m - id) + sf[id];

    }
    cout << max (0ll ,ans * 2) <<"\n";    
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