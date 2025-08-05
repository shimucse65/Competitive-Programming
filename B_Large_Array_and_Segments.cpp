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

    int n,k,x; cin >>n>>k>>x ;
    int a[n];
    int sm =0;
    for (int i=0 ;i<n ;i++) {
        cin >> a[i] ;
        sm += a[i];
    }
    int fulr = x / sm;
    int baki = x  %  sm;

    int ind = -1 ;
    int cur = 0;
    if (baki==0) {
        cout << max( 0ll ,n*k - n* fulr + 1)<<"\n"; return;
    }
    
    for (int  i= n-1 ; i >= 0 ;i--) {
        cur += a[i];
        if (cur >= baki) {
            ind = i+1; break;
        }
    }

    int tot = n*k - fulr*n ;
    tot = tot- (max (0ll , n-ind));
    cout << max (0ll ,tot) <<"\n";
    
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