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
    int n, m; cin >>n>>m ;
    char a[n][m];

    for (int i=0;i<n ;i++) {
        for (int j=0 ;j<m ;j++) cin >> a[i][j];
    }
    int cnt1=0 ;

    for (int i=0 ;i<n ;i++) {
        int zero=0 ,one=0;
        for (int j=0; j < m ;j++) {
            if (a[i][j]=='0') zero++ ;
            else one ++;
        }
        if (one & 1) cnt1++;
    }
    int cnt2=0;
    for (int j=0 ;j<m ;j++) {
        int one=0 , zero=0;
        for (int i=0 ;i<n ;i++) {
            if (a[i][j]=='0') zero++ ;
            else one ++;
        }
        if (one & 1) cnt2++;
    }
    cout << max (cnt1 , cnt2 )<<"\n";    
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