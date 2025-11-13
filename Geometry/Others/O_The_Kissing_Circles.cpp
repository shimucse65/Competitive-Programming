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
#define pi acos(-1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    double R,n; 
    cout << setprecision (10) << fixed;
    while (cin >> R>>n) {
        if (n==1) {
            cout << R <<" " << 0.0<<" " << 0.0 <<"\n";
            continue;
        }
        double ang = pi/n;
        double r = R*sin(ang)/ (1 + sin(ang));

        double tot= (R*R*ang)/2;
        double height= r/tan(ang);
        double tri=( r * height)/2;
        double ang2= ang + pi/2;
        double aa= (r*r*ang2)/2;

        double ans =( tot- tri-aa)* 2*n;
        //cout << ans <<"\n";
        cout << r <<" " << pi*R*R-ans-n*pi*r*r <<" " << ans<<"\n";
    }
    
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