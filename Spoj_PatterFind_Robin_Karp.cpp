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

vector <int>RobinKarp (string s ,string t) {
     vector <int>res ;
     int n= t.size() ;
     int pw=31 ;
     int ans= t[0]-'a'+1 ;
     int p= 31 ;

     for (int i=1; i<n; i++) {
            ans= (ans+ (t[i]-'a'+1)*pw) %mod ;
            pw=( pw*p)% mod ;
     }
  
     n= s.size() ;
     int dp[n] ,poww[n] ;
     dp[0]= s[0]-'a'+1 ;
     poww[0]=1 ;
     pw=p ;

     for (int i=1 ;i<n;i++) {
        dp[i]= (dp[i-1]+ (s[i]-'a'+1)*pw)%mod ;
        poww[i]=pw ;
        pw=( pw*p)%mod;
     }

     int l=0 ,r= t.size()-1 ;
     while (r<s.size()) {
        int win= dp[r] ;
        if (l>0) win=( win- (dp[l-1])+ mod) %mod ;
        int dhv=( ans*poww[l]) % mod;
        if (win==dhv) res.push_back (l+1) ;
        l++ ; r++ ;
     }
    return res ;
}

void solve() {
    string s,t;cin>>s>>t ;
    vector <int>res= RobinKarp (s,t) ;
    if (res.size()==0) {
        cout <<"Not Found"<<"\n";
        return ;
    }
    cout <<res.size ()<<"\n" ;
    for (auto it :res) cout <<it<<" " ;
    cout <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
        cout <<"\n" ;
    }
}