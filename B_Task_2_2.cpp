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
    int n,h,w ; cin >>n>>h>>w;

    for (int i=1;i<=n ;i++) {
        char mn ,ev; cin >> mn >>ev;
        bool f=0;
        if (mn=='Y') cout <<"Y" <<" " , f=1;
        else {
            if (w==0) cout <<"Y" <<" " , f=1;
            else cout  << "N" <<" ";
        }
        if (f) {
            w++ ; h--;
        }
        f=0;
        if (ev=='Y') cout <<"Y" <<"\n" , f=1;
        else {
            if (h==0) cout <<"Y" <<"\n" , f=1;
            else cout  << "N" << "\n";
        }
        if (f) {
            h++ ; w--;
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; 
    //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}