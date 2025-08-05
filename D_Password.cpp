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
const int N = 1e6 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[N] ,poww[N] ;

void preprocess (string s) {
    int p=31 ;
    dp[0]= s[0]-'a'+1 ;
    poww[0]=1 ;

    int pw=31 ;
    for (int i=1 ;i<s.size() ;i++) {
        dp[i]=( dp[i-1]+ (s[i]-'a'+1)*pw)% mod ;
        poww[i]= pw;
        pw= (pw*31)%mod ;  
    }
}

int qur (int l ,int r) {
    int res= dp[r] ;
    if (l>0) res= (res- dp[l-1]+ mod)%mod ;
    return res ;
}
void solve() {
    string s ;cin>>s ;
    int n=s.size();
    preprocess (s) ;
    int ans=0 ;
    for (int i=0 ;i<n;i++) {
        int pf= dp[i] ;
        int sf= qur (n-i-1 ,n-1) ;
        if ((pf* poww [n-i-1]) % mod==sf) {
            int j=1 ,k= i+1 ;
            while (k<n-1) {
                int mid= qur (j,k) ;
                        if ((pf* poww [j]) % mod==mid) {
                            ans=i+1;
                        }
                        j++ ;k++ ;
            }
        }

    }
    if (ans==0) cout <<"Just a legend" <<"\n" ;
    else cout << s.substr (0,ans) <<"\n" ;
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