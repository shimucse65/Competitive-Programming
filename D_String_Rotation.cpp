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
    int n ; cin >> n;
    string s; cin >> s;
    int ind = -1;
    for (int i=1 ; i< n ;i++){
        if (s[i] < s[i-1]) {
            ind = i-1; break;
        }
    }
    int ind2 = -1;
    char c = s[ind];
    for (int i = ind + 1; i< n ;i++) {
        if (s[i] > c){
            ind2 = i ; break;
        }
    }
   // cerr << ind <<" " << ind2 <<"\n";
    if (ind == -1) {
        cout << s <<"\n"; return;
    }
    if (ind2 == -1) ind2 = n;
    for (int i = 0 ; i < ind ;i++) cout << s[i];
    for (int i= ind + 1 ; i < ind2 ; i++) cout << s[i];
    cout << s[ind] ;
    for (int i= ind2 ; i< n ;i++) cout << s[i];
    cout <<"\n";

    
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