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
    int n ,k;cin>>n>>k ;
    int a[n];
    map <int ,int>mp;
    for (int i=0;i<n;i++) {
        cin>>a[i] ;
        mp[a[i]]++ ;
    }
    vector <int>v ;
    for (auto it :mp) v.push_back (it.ss) ;
    sort (v.begin () ,v.end ()) ;
    int sz= v.size () ;
    int pf[sz] ;
    pf[0]= v[0] ;
    for (int i=1 ;i<sz;i++) pf[i]= pf[i-1]+ v[i] ;
    int it= upper_bound (pf ,pf+sz,k)- pf ;
    int ans= max (1ll , sz-it) ;
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
