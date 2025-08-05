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
    int n,m,k; cin >>n>>m>>k;
    map <int,int>mp;
    int mx =-1;
    int ff=0;
    while (m--) {
        
        int x,y; cin>>x >>y;
        mx = max ((max (mx ,x)),y);
        mp[x]++ ; mp[y]++ ;
        int f=1;
        int cnt=0;
        for (int i=1 ; i<=mx ;i++){
           if (mp[i] >=k) cnt++;
           else {
            f=0; break;
           }
        }
        if (f==0 && ff==0) cout << 0 <<"\n";
        else {
            cout << cnt <<"\n"; ff=1;
        }
    }
    
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