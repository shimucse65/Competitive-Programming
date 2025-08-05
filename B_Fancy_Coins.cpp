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
int m,k,a1,ak;

int check (int x) {
    int one = m - (k*x) ;
    return  max (0ll , one -a1) + max (0ll , x- ak);
}

void solve() {
    cin >> m >>k>>a1>>ak;
    int l=0 , r= m/k ;

    while (r-l > 2) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if (check (m1) < check (m2)) {
            r = m2;
        } else l = m1;
    }
    int ans=inf ;
    for (int i=l ; i<=r ;i++) {
        ans = min (ans , check (i));
    }
    cout << ans <<"\n";

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