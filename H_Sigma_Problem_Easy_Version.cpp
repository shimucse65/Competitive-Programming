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
    int n,q;cin>>n>>q;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    int l,r;cin>>l>>r;l--;r--;
    int ans=a[r];
    int pv=1;
    vector <int>v;
    v.push_back (ans);
    for (int i=r-1 ; i>=l ;i--) {
        ans= (ans*a[i])%mod;
        ans = (ans + a[i]) % mod;
        v.push_back (ans);
    }
   // for (auto it :v) cerr << it <<" "; cerr <<"\n";
   int sm=0 ;
   for (auto it :v) {
    sm+= it;
    sm %= mod;
   }
   cout << sm <<"\n";

    
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