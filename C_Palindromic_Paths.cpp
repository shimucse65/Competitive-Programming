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

    int n,m;cin>>n>>m ;
    int sz= n+m-1 ;
    int a[sz][2] ,b[sz][2];
    memset (a ,0 ,sizeof a);
    memset (b ,0, sizeof b);

    for (int i=0 ;i<n ;i++) {
        for (int j=0 ;j<m ;j++) {
            int x ;cin>>x ;
            int gp= i+j;
            a[gp][x]++;
        }
    }
    
    int ans=0;
    int tot = sz/2 ;
    for (int i=0 ;i< tot ;i++) {
        ans += min (a[i][0] + a[n+m-2-i][0] , a[i][1] + a[n+m-2-i][1]);
    }
    cout << ans <<"\n";   
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