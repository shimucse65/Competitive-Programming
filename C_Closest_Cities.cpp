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
    int n;cin >>n ;
    int a[n+1];
    for (int i=1 ; i<=n ;i++) cin >> a[i];

    
    int aa[n+1] , bb[n+1] ;
    aa[1]=0 , aa[2]=1;
    
    for (int i=3 ;i<=n ;i++) {
       if (abs (a[i-2]-a[i-1]) < abs (a[i-1]-a[i])) {
         aa[i]= abs (a[i-1]-a[i]);
       } else aa[i] = 1;
    }

    //for (int i=1 ;i<=n;i++) cout << aa[i] <<" "; cout <<"\n";
    bb[n]=0 ; bb[n-1]=1;
    for (int i = n-2 ; i >= 1 ;i--) {
        if (abs (a[i]-a[i+1]) < abs (a[i+1]- a[i+2])) bb[i] = 1;
        else bb[i]= abs (a[i]-a[i+1]);
    }

    // for (int i = 1 ;i <= n;i++) cout << bb[i] <<" "; cout <<"\n";

    int pf[n+1]; pf[1]=0 ;
    for (int i = 2; i <= n;i++) pf[i] = pf[i-1]+aa[i];

    //for (int i=1 ;i<=n ;i++) cout << pf[i] <<" "; cout <<"\n";
    int sf[n+1];
    sf[n]=0;
    for (int i= n-1 ;i>=1 ;i--) sf[i]= sf[i+1] + bb[i];

    //for (int i = 1 ;i <= n ;i++) cerr << sf[i] <<" "; cerr <<"\n";

    int q;cin>>q ;
    while (q--) {
        int l,r ;cin >>l >>r ;
        if (l<r ) cout << pf[r]- pf[l] <<"\n";
        else {
            //cerr << l <<" " << r <<" "<<sf[l] <<" " <<sf[r] <<"\n";
            cout << sf[r]- sf[l] <<"\n";
        }
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