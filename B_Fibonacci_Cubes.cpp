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
    int n,m; cin >>n>>m ;
    vector <int> v(n+1,0);
    v[1]=1;
    v[2]=2;
    for (int i=3 ;i<=10 ;i++) v[i]= v[i-1]+ v[i-2];

   // for (auto it :v) cerr << it <<" ";
    int sm=0 ;
    for (int i=1 ;i<=n ;i++) sm += v[i]*v[i]*v[i];
    while (m--) {
        int x,y,z; cin >> x>>y>>z;
        int aa= x*y*z ;
        if (aa >= sm) cout <<1;
        else cout << 0;
    }
    cout <<"\n";

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