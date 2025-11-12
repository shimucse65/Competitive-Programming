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
    string s; cin>> s;

    string nn = "";
    for(int i=0; i < 2; i++) nn += s[i];

    string nn2 ="";
    for(int i=3 ; i <= 4;i++) nn2 += s[i];


    int p = stoi(nn);
    int q = stoi(nn2);

    int tot = p * 60 + q;
   
    if (tot == 0) cout << "00:00" << "\n";
    else if (tot <= 11 * 60 + 11) cout << "11:11" << "\n";
    else if (tot <= 22 * 60 + 22) cout << "22:22" << "\n";
    else cout << "00:00" << "\n";   
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