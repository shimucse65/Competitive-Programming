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

    int n ;cin >>n ;
    vector < int> a(n);
    for (int i=0 ;i<n ;i++) {
        cin >> a[i];
    }
    int q; cin >>q ;
    while (q--) {
        string s; cin >>s ;
        int f=1;
        if (s.size () != n) {
            cout <<"NO\n"; continue;
        } 
        map < char ,int > mp;
        for (int i = 0 ; i < n ;i++) {
           if (!mp.count (s[i])) {
                mp[s[i]] = a[i];
           } else {
                if (mp[s[i]] != a[i]) {
                    f=0 ; break;
                }
           }
        }
        map < int , char > mp2;
        for (int i=0 ; i < n ;i++) {
            if (!mp2.count (a[i])) {
                mp2[a[i]] = s[i];
            } else {
                if (mp2[a[i]] != s[i]) {
                    f=0; break;
                }
            }
        } 
        if (f) cout <<"YES\n";
        else cout <<"NO\n";
        mp.clear () ;
        mp2.clear ();  
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