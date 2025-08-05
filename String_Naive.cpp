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

vector <int>Naive (string s ,string t) {
    vector<int>res ;
    int n= s.size () ,m= t.size() ;
    for (int i=0 ;i<= n-m ;i++) {
        bool f=1;
        for( int j=0 ;j<m ;j++) {
            
            if (s[i+j] != t[j]) {
                f=0 ;break;
            }
        }
        if (f) res.push_back (i);
    }
    return res ;
}
void solve() {
    string s,t ;cin>>s>>t ;
    vector <int>res= Naive (s,t) ;
    if (res.size()==0) {
        cout <<"Not found"<<"\n" ; return ;
    }
    cout <<res.size () <<"\n" ;
    for (auto it :res) cout <<it <<" " ;
    cout <<"\n" ;
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