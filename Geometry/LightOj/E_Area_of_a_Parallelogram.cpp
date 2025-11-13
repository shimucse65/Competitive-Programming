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

int area (vector <pii> &v) {
    int sm =0 ;
    for (int i = 0 ; i < 4 ; i++) {
        int ax = v[i].ff , ay= v[i].ss;
        int bx = v[(i+1)%4].ff , by= v[(i+1)%4].ss;
        sm += ax*by - bx*ay;
    }
    sm = abs (sm);
    return sm*0.5;
}
void solve() {
    int ax , ay , bx , by , cx, cy;
    cin >>ax >>ay >> bx >> by >> cx >> cy;

    int  dx= (ax+cx) -bx;
    int  dy= (ay+cy) -by;

    vector <pii>v (4);
    v[0] = {ax,ay};
    v[1]=  {bx, by};
    v[2]=  {cx ,cy};
    v[3] = {dx,dy}; 

    int ans = area (v);

    cout << dx <<" " <<dy <<" " << ans <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}