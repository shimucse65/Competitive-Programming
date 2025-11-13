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
 int n,k;

 pii f (int n) {
    if (n < k) return {0,0};
    auto ch = f (n/2);
    int  ch_sm = ch.ff;
    int  ch_cnt = ch.ss;
    if (n&1) {
        int mid = (n+1)/2;
        int sm = mid + (ch_sm*2) + (mid*ch_cnt);
        int cnt= (ch_cnt*2 + 1);
        return {sm ,cnt};
    }
    int mid = n/2;
    int sm = (ch_sm*2) + (mid*ch_cnt);
    int cnt= ch_cnt*2 ;
    return {sm ,cnt};
 }

void solve() {
   cin>>n>>k;
   cout << f (n).ff <<"\n";    
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