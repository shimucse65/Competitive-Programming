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

    int n,k;cin>>n>>k ;
    string s; cin>>s ;
    int a[n];
    for (int i = 0 ;i < n ;i++) a[i]= s[i]-'a';

    int dp[k][26];
    memset (dp ,0 ,sizeof dp);

    for (int i = 0 ;i < n ;i++) {
        int x= i % k;
        dp[x][a[i]]++;
    }
    int ans=0;
    for (int i = 0 ;i < k/2 ; i++) {
        int cnt = 0 , mx = 0;
        for (int j = 0;j < 26; j++) {
            int tmp = dp[i][j] + dp[ k - 1- i][j];
            cnt+= tmp;
            mx= max (mx , tmp);
        }
        ans+= cnt - mx;
    }
    if (k & 1) {
        int tmp=( k+1)/2;
        int tt=0 ,mx=0;
        for (int j=0 ;j<26 ;j++) {
            tt+= dp[tmp][j];
            mx= max (mx , dp[tmp][j]);
        }
        ans+= tt- mx;
    }
    cout << ans <<"\n";    
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