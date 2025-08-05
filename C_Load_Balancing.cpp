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
    int n;cin>>n ;
    int a[n] ;
    for (int i=0;i<n;i++) cin>>a[i] ;
    int sm= accumulate (a,a+n ,0ll) ;
   
    int l= sm/n, cnt1=0 ;
    int r= (sm+n-1)/n ,cnt2=0 ;
    for (int i=0 ;i<n;i++) {
        if (a[i] <l) cnt1+= (l-a[i]) ;
        else if (a[i]>r) cnt2+= (a[i]-r) ; 
    }
    cout <<max (cnt1 ,cnt2) <<"\n" ;
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