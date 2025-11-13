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
    int p,q , x1,y1,x2,y2; cin >> p>>q>>x1>>y1>>x2>>y2;
    int a= y1-y2;
    int b= x2-x1;
    int c= -a*x1 - b*y1;

    cout << setprecision (10) << fixed <<(a*p+b*q+c)/ (sqrt (a*a+b*b)*1.0)<<"\n";

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("distance2.in", "r", stdin);   
    freopen("distance2.out", "w", stdout); 

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}