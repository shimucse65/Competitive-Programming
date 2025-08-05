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
    int n,m;cin>>n>>m;
    vector <int > a (n) , b(m);

    for (int i=0 ;i<n ;i++) cin >>a[i];
    for (int i=0 ;i<m ;i++) cin >> b[i];

    sort (a.rbegin () , a.rend ());
    sort (b.rbegin () , b.rend ());

    int cnt=0 ;
    int mn= min (a.size () , b.size());
    vector <int>v;
    for (int i=0 ;i<mn ;i++) {
        if (a[i] > 0 && b[i] < 0) cnt += a[i];
        else if (a[i] > 0 && b[i] > 0) {
            cnt += (a[i]+b[i]);
        } else if (a[i] < 0 && b[i] >0) {
            if (a[i]+ b[i] > 0) cnt += (a[i]+b[i]);
        }
    }
    if (a.size () > b.size ()) {
        for (int i= mn ;i<a.size () ;i++) {
            if (a[i] > 0) cnt+= a[i];
        }
    }
    for (auto it :v) cnt += it;
    cout << cnt <<"\n";
   
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
