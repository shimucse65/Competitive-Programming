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
    int z=0 ;
    for (int i=0 ;i<n;i++) {
        cin>>a[i] ;
       if (a[i]==0) z++;
    }
    int ind1=0 , ind2=n-1;
    for (int i=0 ;i<n;i++) {
        if (a[i]!=0) {
            ind1=i ; break ;
        }
    }
    for (int i=n-1 ;i>=0 ;i--) {
        if (a[i]!=0) {
            ind2=i ; break ;
        }
    }
    vector <int>v ;
    for (int i=ind1 ; i<=ind2 ;i++) v.push_back (a[i]) ;
    int f=0 ;
    for (auto it :v) {
        if (it==0) f=1;
    }
    if (z==n) cout <<0 <<"\n" ;
    else if (z==0) cout <<1 <<"\n" ;
    else if (f==0) cout <<1 <<"\n" ;
    else cout <<2 <<"\n" ;    
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