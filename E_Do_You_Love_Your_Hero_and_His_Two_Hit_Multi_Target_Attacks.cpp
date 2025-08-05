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
    int k ; cin >> k;
    int cur= -1000000000;
    int tmp =1 ;

    if (k==0) {
        cout << 2 <<"\n";
        cout << 1 <<" " << 2 <<"\n";
        cout << 3 <<" " << 4 <<"\n";
        return;
    }
    vector <pii > v;
    while (k > 1) {
        int l=0 , r=k ,ans=0;
         while ( l <= r) {
            int mid = l + (r-l)/2 ;
            if ((mid * (mid-1)/2) <= k ) {
                ans = mid ; 
                l= mid +1 ;
            } else r= mid-1 ;
         }
         //cerr << ans  <<"\n";
         for  (int i=0 ; i < ans ;i++) {
            v.push_back ({tmp , cur++});
         }
         k -= (ans * (ans-1)) / 2;
         tmp++;
    }
    if (k==1) {
        v.push_back ( { tmp  , cur ++ });
        v.push_back ( { tmp  , cur ++});
    }
    cout << v.size () <<"\n";
    for (auto it :v) cout << it.ff <<" " << it.ss <<"\n";
    cout <<"\n";
    
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