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

    int l,r,g;cin>>l>>r>>g;
    int l1= (l+g-1)/g;
    int r1= r/g;
    int mx=0 , aa=0 ,bb=0 ,f=0;

    for (int i=l1 ;i<=min(l1+200,r1);i++) {
        for (int j= r1 ; j>= max (l1 ,i);j--) {
            if (gcd (i,j)==1) {
                if (mx < j-i+1) {
                    mx= j-i+1 ;
                    aa=i; bb=j;
                    f=1;
                }
                break;
            }
        }
    }
    
    if (!f) cout << -1 <<" " <<-1 <<"\n";
    else  cout << g*aa <<" " << g*bb <<"\n";  
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