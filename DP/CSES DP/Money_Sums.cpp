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
    int a[n] ;
    int sm=0;
    for (int i=0 ;i<n ;i++) cin>>a[i],sm+=a[i] ;
    vector < vector <int>> dp (n , vector <int> (sm+1 ,0));
    // int dp[n][sm+1];
    // for (int i=0 ;i<n ;i++) {
    //     for (int j=0 ; j<=sm ;j++) dp[i][j]=0 ;
    // }

    for (int i=0 ;i<n ;i++) dp[i][0]=1 ;
    if (sm- a[0] >=0) dp[0][a[0]] = 1 ;

    for (int i=1 ;i<n ;i++) {
        for (int target=1 ;target<=sm ;target++) {
            int pick=0 ;
            if (target-a[i]>=0) pick= dp[i-1][target-a[i]] ;
            int not_pick= dp[i-1][target];

            dp[i][target]= pick|not_pick ;
        }
    }

    vector<int>ans ;
    for (int i=1 ;i<=sm ;i++) {
        if (dp[n-1][i]==1) ans.push_back(i) ;
    }
    cout << ans.size () <<"\n" ;
    for (auto it :ans) cout <<it <<" " ; cout <<"\n" ;
    
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