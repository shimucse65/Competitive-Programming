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
    int  x1,y1 ,x2,y2,x3,y3; cin >>x1>>y1>>x2>>y2>>x3>>y3;

    // int m1 = (y2-y1)/ (x2-x1);
    // int m2 = (y3-y2)/ (x3-x2);

    int xx= (y3-y2)* (x2-x1)- (y2-y1)*(x3-x2);
    if (xx==0) cout <<"TOUCH" <<"\n";
    else if (xx < 0) cout <<"RIGHT" <<"\n";
    else cout <<"LEFT" <<"\n";
    
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