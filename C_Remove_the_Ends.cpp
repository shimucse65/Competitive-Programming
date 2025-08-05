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
    int n ; cin >>n ;
    int a[n];
    int sm1=0 , sm2=0;

    for (int i=0;i<n ;i++) {
        cin >> a[i];
        if (a[i] < 0) sm2+= abs( a[i]);
        else sm1+= a[i];
    }
    int mx= max (sm1 , sm2);
    //cerr << mx <<"\n";

    int pf[n] , sf[n];

    a[0] >= 0 ? pf[0]= a[0] : pf[0]=0;
    for (int i=1 ; i<n ;i++) {
        if (a[i] >= 0) {
            pf[i]= pf[i-1] + a[i];
        } else {
            pf[i]= pf[i-1];
        }
    }
    a[n-1] < 0 ? sf[n-1]= abs(a[n-1]) :sf[n-1]= 0;
    //cerr << sf[n-1] <<"\n";
    for (int i=n-2 ; i>=0 ;i--) {
        if (a[i] < 0) {
            sf[i] = sf[i+1] + abs(a[i]);
        } else {
            sf[i] = sf[i+1];
        }
    }
    // for (int i=0 ;i<n ;i++) cerr << pf[i] <<" "; cerr <<"\n";
    // for (int i=0 ;i<n ;i++) cerr << sf[i] <<" "; cerr <<"\n";

    for (int i=0 ; i < n-1; i++) {
        if (a[i] < 0) continue;
        mx= max (mx ,pf[i] + sf [i+1]);
    }
    cout << mx <<"\n";    
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
