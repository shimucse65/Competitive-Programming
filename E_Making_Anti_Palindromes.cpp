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
    int n ; cin >>n ;
    string s; cin >>s;
    map < char , int>mp;
    for (auto it :s) mp[it]++ ;

    if (n & 1) {
        cout << -1 <<"\n"; return;
    }

    for (auto it : mp) {
        if (it.ss *2 > n) {
            cout << -1 <<"\n"; return;
        }
    }
    int pr=0 ;
    mp.clear () ;
    for (int i=0 ; i * 2 < n ;i++) {
        if (s[i]==s[n-i-1]) {
            pr++ ;
            mp[s[i]]++;
        }
    }
    for (auto it : mp) {
        if (it.ss * 2 > pr) {
            cout << it.ss <<"\n"; return;
        }
    }
    cout << (pr + 1 )/2 <<"\n";
    
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
