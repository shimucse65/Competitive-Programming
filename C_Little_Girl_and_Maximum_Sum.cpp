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
int arr[N] ;
int pf[N] ;
void solve() {
    int n,q;cin>>n>>q ;
    int a[n] ;
    for (int i=0;i<n;i++) cin>>a[i] ;
    sort (a,a+n , greater <int>()) ;

    for (int i=0;i<q;i++) {
        int l,r ;cin>>l>>r ;
        arr[l]++ ; arr[r+1]-- ;
    }
      
    pf[0]= arr[0] ;
    for (int i=1 ;i<=n;i++) {
        pf[i]= pf[i-1]+ arr[i] ; 
    }
    sort (pf, pf+n+1 , greater <int>()) ;
   
    int ans=0 ;
    for (int i=0;i<n;i++) {
        ans+= (a[i]*pf[i]) ;
    }
    cout <<ans <<"\n" ;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;// cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}