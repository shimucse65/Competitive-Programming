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
const int mod = 1000000007;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n ; cin>>n ;
    int a[n];
    for (int i=0;i<n ;i++) cin>>a[i];
    int sf[n];
    sf[n-1]= a[n-1];

    for (int i= n-2 ; i>=0 ;i--) 
     {
        sf[i]= sf[i+1]+ a[i];
        sf[i] %= mod;
     }

    int sm=0;

    for (int i=0;i<n-1 ;i++) {
        int tmp= sf[i+1];
        sm += (a[i]*1ll*tmp)%mod;
        sm %= mod;
    }
    cout << sm % mod <<"\n";
    
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
