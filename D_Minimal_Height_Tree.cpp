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
    vector <int>v ;
    for (int i = 0; i < n; i++) {
        int x;cin>>x;
        v.push_back (x);
    }
    int cnt=1;
    vector <int>tmp ;
    for (int i = 2; i < n ; i++) {
        if (v[i] > v[i-1]) {
            cnt++;
        }
        else {
            tmp.push_back (cnt); cnt=1 ;
        }
    }
    tmp.push_back (cnt);
    vector <int>ans ;
    ans.push_back (tmp[0]);
    int cur= tmp[0];

    for (int i = 1 ; i < tmp.size() ;i++) {
        int it=0 ;
        int sm=0 ;
        while (it <cur && i < tmp.size()) {
            it++ ;
            sm+= tmp[i] ; 
             i++ ;
        }
        i--;
        ans.push_back (sm);
        cur= sm ;
    }
     cout <<ans.size () <<"\n";
    
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