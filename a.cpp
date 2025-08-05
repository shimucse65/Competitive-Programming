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

vector <int>divi (int n) {
    vector <int>res ;
    for (int i=1 ;i*i <=n ;i++) {
        if (n%i==0) {
            res.push_back (i) ;
            if(i*i !=n) {
                res.push_back (n/i) ;
            }
        }
    }
    sort (res.begin () , res.end ()) ;
    return res ;
}
void solve() {
     
    for (int i = 2 ; i <= 500 ; i++) {
        for(int j = 2; j <= 500; j++) {
            if (i == j) continue;

            vector<int> xx = divi(i); 
            vector <int> yy = divi(j);
            vector <int> zz = divi(gcd(i, j));

            set <int > st;
            vector <int> aa = divi(i * j);

            if (aa.size() != ( xx.size() * yy.size() - zz.size())) {
                cout << i << " " << j << "\n";
                cout << "NO\n"; return;
            }          
        }
    }
    cout << "YES\n";
    
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