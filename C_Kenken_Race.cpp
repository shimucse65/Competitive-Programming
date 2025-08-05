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
string s;
int n ;
int dp1[N];
int dp2[N];
int a,b,c,d;
bool isvalid1 (int ind) {
    return ind < n && s[ind] !='#' && ind!= b && ind!=d ;
}
bool isvalid2 (int ind) {
    return ind < n && s[ind] !='#' && ind!= a && ind!=c ;
}

bool f1 (int ind ,int c , bool ok) {  
    if (ind==n) {
        if (ok) return true;
        return false ;
    }
    if (dp1[ind]!=-1) return dp1[ind];
    int one=0 ,two=0;
    if ((isvalid1 (ind+1))) one=  f1 (ind+1 , c ,ok | (ind+1==c));
    if ( (isvalid1 (ind+2))) two=  f1 (ind+2 , c, ok |  (ind+2==c));
    return dp1[ind]=  one | two;
}
bool f2 (int ind ,int c , bool ok) {  
    if (ind==n) {
        if (ok) return true;
        return false ;
    }
    if (dp2[ind]!=-1) return dp2[ind];
    int one=0 ,two=0;
    if ((isvalid2 (ind+1))) one=  f1 (ind+1 , c ,ok | (ind+1==c));
    if ( (isvalid2 (ind+2))) two=  f1 (ind+2 , c, ok |  (ind+2==c));
    return dp2[ind]=  one | two;
}
void solve() {
    cin >>n>>a>>b>>c>>d;
    cin >>s;
    s='#'+s;
    memset (dp1 ,-1 ,sizeof dp1);
    memset (dp2 ,-1 ,sizeof dp2);
    if (f1(a,c,0)  && f2 (b,d,0)) cout <<"Yes\n";
    else cout <<"No\n";    
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