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
    int n ;cin>>n ;
    int a[n+1] ;
    vector <int>g[n+1] ;
    vector <int> ans (n+1) , in (n+1) ;
    int sm=0 ;
    for (int i=1 ;i<=n ;i++) cin>>a[i],sm+=a[i] ;
    for (int i=0;i<n-1 ;i++) {
        int u,v;cin>>u>>v ;
        g[u].push_back (v) ;
        g[v].push_back (u) ;
        in[u]++ ; in[v]++ ;
    }
    priority_queue <int>pq ;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < in[i] - 1; j++) pq.push(a[i]);
    }
 
    ans[1]= sm ;
    for (int i=2 ;i<=n-1 ;i++) {
        if (!pq.empty()) sm+= pq.top () , pq.pop () ;
        ans[i]= sm ;
    }
    for (int i=1 ;i<=n-1 ;i++) cout <<ans[i] <<" " ; cout <<"\n" ;
    
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
