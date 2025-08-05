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
    int n;cin>>n ;
    int a[n];
    vector < int>odd , ev;
    for (int i=0;i<n ;i++) {
        cin >>a[i];
        if (a[i] & 1) odd.push_back (a[i]);
        else ev.push_back (a[i]);
    }
    sort (odd.begin () ,odd.end ());
    sort (ev.begin () , ev.end ());

    if (odd.size () < 2 && ev.size () <2) cout << -1 <<"\n";
    else  {
        int sm1 =0 , sm2=0;
        if (odd.size () >= 2){
        int  ods= odd.size () ;
         sm1= odd[ods-1] + odd[ods-2] ; }
        else sm1= 0 ;
        
        if (ev.size () >=2) {
        int  evs= ev.size () ;
         sm2= ev[evs-1] + ev[evs-2] ; }
        else  sm2=0;

        cout << max ( sm1 , sm2) <<"\n";

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