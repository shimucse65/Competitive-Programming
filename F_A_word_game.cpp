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
int dp[50];

int grundy (int n) {
    if (~ dp[n]) return dp[n] ;
    set <int>st;
    st.insert (grundy (max (0ll , n-1)));
    st.insert (grundy (max (0ll , n-2)));
    st.insert (grundy (0));

    int mex=0;
    for (auto it :st) {
        if (it !=mex) break;
        mex++;
    }
    return dp[n]= mex ;
}
void solve() {

    string s;cin>>s;
    map < char ,int >mp;
    for (int i=0;i<s.size () ;i++) {
        mp[s[i]]++;
    }
    int xr=0;
    memset (dp , -1 , sizeof dp);
    dp[0]=0;
    for (auto it :mp) {
        if (it.ss > 0) {
            xr^= (grundy (it.ss));
        }
    }
    if (xr) cout <<"Alice\n";
    else cout <<"Bob\n";
    
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