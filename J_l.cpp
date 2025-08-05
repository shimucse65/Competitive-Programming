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
  
    int n , lim ; cin >>n >> lim;
    map <int ,int>mp;
    vector < pii >v;
    for (int i=1 ; i<=lim ; i++) {
        int tmp= i;
        for (int i=0 ; i< 32; i++) {
            if (tmp & (1<<i)) {
                mp[(1<<i)] = tmp;
                v.push_back ({(1<<i), tmp}); break;
            }
        }
    }
    sort (v.rbegin () , v.rend ());
    //for (auto it :v) cerr << it.ff <<" " << it.ss <<"\n";

    int sm=0 ;
    for (auto it:v) sm += it.ff;

    if (n > sm) {
        cout << -1 <<"\n"; return;
    }
     sm=n ;
    vector < int>ans;
    for (auto it :v) {
        if (sm==0) break;
        if (it.ff <= sm) {
            sm -= it.ff;
            ans.push_back (it.ss);
        }      
    }
    if (sm >0) {
        cout << -1 <<"\n"; return;
    }
    cout << ans.size () <<"\n";
    for (auto it :ans) cout << it <<" " ; cout <<"\n";
    
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