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

bool ccw (int x1 ,int y1 , int x2 , int y2 , int x3 , int y3) {
    int xx= (y3-y2)* (x2-x1)- (y2-y1)* (x3-x2);
    return xx >0;
}
void solve() {
    int n; cin>>n;
    vector <pii> v;
    for (int i=0;i<n;i++){
        int x,y; cin >>x>>y;
        v.push_back ({x,y});
    }
    int cnt =0;
    for (int i=0;i<n ;i++) {
        cnt += ccw (v[i].ff , v[i].ss , v[(i+1)%n].ff, v[(i+1)%n].ss, v[(i+2)%n].ff , v[(i+2)%n].ss);
    }
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