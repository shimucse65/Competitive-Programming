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

double area (vector <pii > &v) {
 int res=0 ;
 int n= v.size();
 for (int i=0 ; i<n;i++) {
    int x1= v[i].ff, y1= v[i].ss;
    int x2= v[(i+1)%n].ff , y2= v[(i+1)%n].ss;
    res += (x1*y2- x2*y1);
    //cerr << res <<"\n";
 }
 return abs (res)/2.0;
}
void solve() {
   // int n; cin >>n ;
    vector <pii> v;
    for (int i=0;i<3 ;i++) {
        int x,y; cin >>x >>y;
        v.push_back ({x,y});
    }
    double ans= area (v);
    cout << ans*1.0 <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("area1.in", "r", stdin);   
    freopen("area1.out","w", stdout); 

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}