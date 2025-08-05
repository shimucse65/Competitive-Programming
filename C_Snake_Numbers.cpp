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
int dp[20][10][2];

int magic (int pos , int mx , bool tight ,string &s) {

    if (pos==s.size()) return 1;
    int &ans = dp[pos][mx][tight];
    if (~ans) return ans;

    ans=0;
    int up= tight?s[pos]-'0':9 ;

    for (int i=0 ;i<=up && i<mx ;i++) {
        int nmx= (mx==10 && i!=0)?i:mx ;
        ans += magic (pos+1 ,nmx , tight & (i==up),s);
    }
    return ans;
}
void solve () {

    int l,r ;cin>>l>>r;
    l--;
    string lf= to_string (l);
    string ri= to_string (r);

    memset (dp,-1,sizeof dp);
    int res1= magic (0,10,1,lf);
   // cerr << res1 <<"\n";

    memset (dp,-1,sizeof dp);
    int res2= magic (0,10,1,ri);

    cout << res2-res1 <<"\n";
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