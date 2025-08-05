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
    int a[n+1][n+1];
    for (int i=1 ;i<=n ;i++) {
        for (int j=1 ;j<=n ;j++) cin>>a[i][j];
    }

    int q;cin>>q;
    while (q--) {
        int aa,bb,cc ;cin>>aa>>bb>>cc;
        int ans=0;
        for (int i=1;i<=n ;i++) {
            for (int j=i+1;j<=n ;j++) {
                int op1= a[i][aa]+ cc+ a[bb][j];
                int op2= a[i][bb]+ cc + a[aa][j];
                a[i][j]= a[j][i]= min (a[i][j] , min (op1 ,op2));
                ans+= a[i][j];
            }
        }
        cout <<ans <<" ";
    }
    
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