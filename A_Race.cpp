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
    int a,x,y; cin >>a >>x>>y;
    int c1= abs (a-x), c2= abs (a-y);

    int ans1 = y+c2-1 , ans2= y-c2-1 , ans3= x+ c1-1 , ans4= x-c1-1;

    if (abs (ans1-y) < c2 && abs (ans1-x) < c1){
        cout <<"YES\n"; return;
    }
    if (abs (ans2-y) < c2 && abs (ans2-x) < c1){
        cout <<"YES\n"; return;
    }
    if (abs (ans3-y) < c2 && abs (ans3-x) < c1){
        cout <<"YES\n"; return;
    }
    if (abs (ans4-y) < c2 && abs (ans4-x) < c1){
        cout <<"YES\n"; return;
    }
    cout <<"NO\n";
    
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