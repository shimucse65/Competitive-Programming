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
    int n,m,k;cin>>n>>m >>k; 
    int a[m] ;
    for (int i=0 ;i<m ;i++) cin>>a[i] ;
    int c[k] ;
    for (int i=0 ;i< k;i++) cin>>c[i] ;

    set <int>st1 , st2 ;
    for (int i=0 ;i<m;i++)  st1.insert (a[i]) ;
    for (int i=0;i<k ;i++) st2.insert (c[i]) ;
    if (st1==st2) {
        for (int i=1 ; i<=m ;i++) cout <<1 ;
        cout <<"\n" ; return ;
    }
    for (int i=1 ;i<=n ;i++) {
        if (!st1.count (i)&& !st2.count (i)) {
            for (int i=1 ;i<=m ;i++) cout<<0; 
            cout <<"\n" ; return ;
        }
    }
    int nai= n- st2.size () ;
    if (nai>=2) {
        for (int i=1 ;i<=m ;i++) cout<<0; 
            cout <<"\n" ; return ;
    }
     nai=0 ;
    for (int i=1 ;i<=n ;i++) {
        if (!st2.count (i)) {
            nai= i ;
        }
    }
    int ans[m] ;
    for (int i=1 ;i<=m ;i++) {
        if (i==nai) ans[i]=1 ;
        else ans[i]=0;
    }
    for (int i=1 ;i<=m ;i++) cout <<ans[i] ; cout <<"\n" ;
    
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