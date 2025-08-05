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
int n ;

int MCM (int i ,int j,vector <int>&a ,vector <vector <int>>&dp) {
    if (i==j) return 0ll ;
    if (dp[i][j]!=-1) return dp[i][j] ;
    int mn=inf ;

    for (int k=i ;k <=j-1 ;k++) {
        int step= a[i-1]*a[k]*a[j] + MCM(i,k,a,dp)+ MCM (k+1 ,j,a,dp) ;
        if (step<mn) mn= step ;
    }
    return dp[i][j]= mn ;
}
void solve() {

    cin>>n ;
    vector <int>a(n) ;
    for (auto & it:a) cin>>it ;

    vector < vector <int>>dp (n ,vector<int> (n,-1));
    
    cout <<MCM (1 ,n-1,a ,dp) <<"\n" ;
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