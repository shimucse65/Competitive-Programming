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

    int n,q ;cin>>n>>q ;
    int a[n] ;
    for (int i=0 ;i<n;i++) cin>>a[i] ;

    while (q--) {
        int l,r ;cin>>l>>r ;
        int f=1 ;
        if (r-l>1000) {
            f=0 ;
        }
        int mn ;
        if (f==1)
      {

        vector <int>v ;
        for (int i=l ;i<=r ;i++)v.push_back (a[i]);
        sort (v.begin (),v.end ());
    
         mn= inf ;
        for (int i=1 ;i<v.size ();i++) {
            mn= min (mn ,abs(v[i]- v[i-1]));
        }
      }
        if (!f) cout<<0 <<"\n" ;
        else cout <<mn <<"\n" ;
    }   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
         cout<<"Case "<<c++<<": \n";
        solve();
    }
}