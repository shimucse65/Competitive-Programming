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
    string s; cin >>s;
    int n = s.size ();
    if (s[0]=='(' && s[1]==')' && n==2) {
        cout <<"NO\n"; return;
    }
    string ans="";
    for (int i=0 ;i<n ;i++) ans += '(';
    for (int i=0 ;i<n ;i++) ans += ')';

    bool f=0;
    for (int i=0 ;i <= n ;i++) {
       // cerr << ans.substr (i ,n) <<"\n";
        if (ans.substr (i ,n) == s) {
            f=1 ; break;
        }
    }
   // cerr << f <<"\n";
    cout <<"YES\n";
    if (f==0) {
        for (int i=0 ;i<n ;i++) cout <<"(";
        for (int i=0 ;i<n ;i++) cout << ")";
        cout <<"\n";
    }  else {
        for (int i=0 ;i< n ;i++) {
            cout << '(';
            cout << ")";
        }
        cout <<"\n";
    }

    
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
