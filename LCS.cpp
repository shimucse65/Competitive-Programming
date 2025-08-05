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

int f (string s1 ,string s2 ,int ind1 ,int ind2,vector<vector<int>>&dp) {
    if (ind1 <0 || ind2 <0) return 0 ;
    if (dp[ind1][ind2]!=-1) return dp[ind1][ind2] ;

    if (s1[ind1]==s2[ind2]) dp[ind1][ind2]= f (s1 ,s2, ind1-1 ,ind2-1 ,dp)+1 ;
    else dp[ind1][ind2]= max (f (s1 ,s2,ind1-1 ,ind2 ,dp),f (s1 ,s2,ind1 ,ind2-1 ,dp));
    return dp[ind1][ind2] ;
}
void solve() {
    string s1 ,s2 ;cin>>s1>>s2 ;
    int n=s1.size() ,m=s2.size() ;
    vector <vector<int> >dp (n+1 ,vector <int>dp (m+1 ,-1));
    cout << f (s1 ,s2 ,n+1 ,m+1 ,dp) <<"\n" ;
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