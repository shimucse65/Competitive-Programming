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

int area (vector <pii >v){
    int aa=0;
    int n= v.size();
    for (int i=0 ;i<n;i++){
        int x1= v[i].ff , y1= v[i].ss;
        int x2= v[(i+1)%n].ff , y2= v[(i+1)%n].ss;
        aa += (x1*y2- x2*y1);
    }
    return abs(aa);
}
void solve() {
    int n; cin >>n;
    vector < pii > v;
    for (int i=0;i<n ;i++){
        int x,y; cin >>x>>y;
        v.push_back ({x,y});
    }
    int bb=0;
    for (int i=0;i<v.size();i++) {
        int xx = abs(v[(i+1)%n].ff- v[i].ff);
        int yy= abs(v[(i+1)%n].ss- v[i].ss);
        bb +=  (__gcd (xx,yy));
    }

    int aa= area (v)/2;
    
    int inside = aa- (bb/2)+1;
    cout << inside <<" " << bb <<"\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;// cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}