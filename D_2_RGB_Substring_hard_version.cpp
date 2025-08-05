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
int dp[3][N];

void solve() {
    int n ,k ; cin>>n>>k;
    string s;cin>>s;
    string tmp="RGB";

    dp[0][0]= dp[1][0]= dp[2][0]=0;

    for (int i=0 ;i<3 ;i++) {

        for (int j=1 ; j<=n ;j++) {
            
            if (s[j-1] != tmp[(i+j-1)%3] ) dp[i][j]= dp[i][j-1] + 1 ;
            else dp[i][j]= dp[i] [j-1];
        }
    }

    int mn= inf ;

    for (int i=0 ; i<3 ;i++) {
        for (int j=k ; j<=n ;j++) {
            mn= min (mn , dp[i][j]- dp[i][j-k]);
        }
    }

    cout <<mn <<"\n";   
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