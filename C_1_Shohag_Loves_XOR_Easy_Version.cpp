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

//__lg->position of highest set bit 


void solve() {

    int x,m;cin>>x>>m ;
    int ans=0 ;
    for (int y=1 ;y<=m;y++) {
        if (__lg (y) >__lg (x)) break;
        int xr= (x^y) ;
        if (xr>=1 && xr <=m && (x!=y) && (y%xr==0 || x%xr==0) ) ans++ ;
    }

    cout <<ans <<"\n" ; 
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