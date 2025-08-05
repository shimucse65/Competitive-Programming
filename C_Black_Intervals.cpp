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
    int n; cin >>n ;
    int a[n+1];
    for (int i=1 ; i<=n ;i++) a[i]=0;

    if (n==1) {
        int q;cin >>q ;
        int x=1 ;
        while (q--) {
            cout << x <<"\n";
            x^=1; 
        }
        return;
    }

    int q; cin >>q ;
    int ans=0;
    while (q--) {
        int x; cin >>x ;
        if (x==1) {
            if (a[x]==0) {
                 a[x]=1;
                 if (a[x+1]==0 ) ans++;
                 cout << ans <<"\n"; 
            } else {
                 a[x]=0;
                 if (a[x+1]==0 ) ans--;
                 cout << ans <<"\n"; 
            }

        } else if (x==n) {
            if (a[x]==0) {
                 a[x]=1;
                 if (a[x-1]==0 ) ans++;
                 cout << ans <<"\n"; 
            } else {
                 a[x]=0;
                 if (a[x-1]==0 ) ans--;
                 cout << ans <<"\n"; 
            }

        } else if (a[x]==1) {
            a[x]=0;
            if (a[x-1]==0 && a[x+1]==0) ans--;
            else if (a[x-1]==1 && a[x+1]==1)ans++;
            cout << ans <<"\n"; 

        }else if (a[x]==0) {
            a[x]=1;
            if (a[x-1]==0 && a[x+1]==0) ans++;
            else if (a[x-1]==1 && a[x+1]==1)ans--;
            cout << ans <<"\n"; 
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