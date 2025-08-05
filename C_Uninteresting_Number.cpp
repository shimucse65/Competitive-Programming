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
    string s;cin>>s ;
    int tw=0 ,th=0 ,sm=0 ;
    for (int i=0 ;i<s.size () ;i++) {
        if (s[i]=='2') tw++ ;
        else if (s[i]=='3') th++ ;
        sm+= (s[i]-'0') ;
    }
   // cerr <<sm <<"\n" ;
    int tmp= sm ;
    for (int i=0 ; i<= min (9ll ,tw) ;i++) {
        for (int j=0 ;j <= min (9ll ,th);j++) {
            sm+= (i*2+j*6) ;
            if (sm%9==0) {
                cout <<"YES\n" ; return ;
            }
            sm= tmp;
        }
    }
    cout <<"NO\n" ;   
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