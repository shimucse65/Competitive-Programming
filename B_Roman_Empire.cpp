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
    int n; cin >> n;
   vector <int> v  = {1, 4, 5, 9, 10, 40, 50, 90,100,400 ,500,900,1000};
    map <int, string>mp;
    mp[1] = "I";
    mp[4] = "IV";
    mp[5] = "V";
    mp[9] = "IX";
    mp[10] = "X";
    mp[40] = "XL";
    mp[50] = "L";
    mp[90] = "XC";
    mp[100] = "C";
    mp[400] = "CD" ;
    mp[500] = "D";
    mp[900] = "CM";
    mp[1000] = "M";

    vector<string> ans;

    while (n > 0) {
        int id = upper_bound(v.begin(), v.end(), n) - v.begin();
        if(id != 0) id--;

        ans.push_back (mp[v[id]]);
        n -= v[id];
    }
    for(auto it : ans) cout << it; cout << "\n";     
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