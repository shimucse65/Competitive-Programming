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
#define eps 1e-6 
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {

    double x,y,c; cin >> x>>y>>c;
    double l=0 , r = min (x,y);
    for (int i=0 ;i<100000 ;i++) {
        double d = l + (r-l)/2.0 ;
        double lx = sqrt (x*x-d*d);
        double ly=  sqrt (y*y-d*d);

       
        double cc =( lx*ly )/ (lx+ly);

        if (cc > c) l = d ;
        else r = d;
    }
    cout << setprecision(10) << fixed <<l <<"\n";
    
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