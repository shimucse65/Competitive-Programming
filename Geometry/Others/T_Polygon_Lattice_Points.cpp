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
    int n= v.size ();
    int cnt=0;
    for (int i=0 ;i<v.size ();i++) {
        int x1= v[i].ff ,y1 = v[i].ss;
        int x2= v[(i+1)%n].ff , y2= v[(i+1)%n].ss;
        cnt += x1*y2- x2*y1;
    }
    return abs(cnt);
}
int bound (vector <pii> &v) {
    int n= v.size ();
    int cnt=0;
    for (int i=0 ;i<v.size ();i++) {
        int x1= v[i].ff ,y1 = v[i].ss;
        int x2= v[(i+1)%n].ff , y2= v[(i+1)%n].ss;
        cnt += __gcd (abs (x1-x2) , abs (y1-y2));
    }
    return cnt;
}
void solve() {
    int n;cin>>n ;
    vector <pii> v(n);
    for (int i=0;i<n ;i++) {
        int x,y;cin >>x>>y;
        v[i]= {x,y};
    }
    int  aa= area (v);
    int  bb= bound(v);
    cout <<( aa-bb+2)/2 <<" " <<bb <<"\n";   
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