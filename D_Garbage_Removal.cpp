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
    int w,h,n; cin>>w>>h>>n;
    map <int,int> mpx , mpy;
    for (int i=0;i<n ;i++) {
        int x,y;cin>>x>>y;
        mpx[x]++; mpy[y]++;
    }
    for (auto it:mpx) cerr << it.ff <<" " <<it.ss<<"\n";
    int q; cin>>q;
    
    while (q--) {
        int ty ,xx; cin>>ty>>xx;
        if (ty==1) {
            if (mpx[xx]) {
                cout << mpx[xx] <<"\n";
                mpx[xx]=0;
            } else {
                cout << 0 <<"\n";
            }       
        } else {
        if (ty==1) {
            if (mpy[xx]) {
                cout << mpy[xx] <<"\n";
                mpy[xx]=0;
            } else {
                cout << 0 <<"\n";
            }
        }       
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