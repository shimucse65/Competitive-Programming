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
    int a[n] ;
    for (int i=0 ;i<n;i++) cin>>a[i] ;
    int sm= 0 ;
    for (int i=0 ;i<n;i++) sm+= a[i];
    if (sm%n) {
        cout <<"NO\n" ; return ;
    }
    int p= sm/n , odd_sm=0 ,ev_sm=0 ,cnt1=0 ,cnt2=0 ;

    for (int i=0;i<n;i++) {
        if (i&1) {
            cnt1++ ; odd_sm+= a[i] ;
        } else {
            cnt2++ ; ev_sm+= a[i] ;
        }
    }

    if (odd_sm % cnt1==0 && ev_sm %cnt2==0 && odd_sm/cnt1==p && ev_sm /cnt2==p) {
        cout <<"YES\n" ;
    } else {
        cout <<"NO\n" ;
    }

   
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