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

string uni;
void build () {
    for (int i=1 ;i<=700 ;i++) {
        uni.push_back ('R');
        uni.push_back ('G');
        uni.push_back ('B');
    }
}
void solve() {
    int n ,k; cin>>n>>k ;
    string s;cin>>s;
    int mn= inf;

    string s2= uni.substr (0,k);
    string s3= uni.substr (1,k);
    string s4= uni.substr (2,k); 

    for (int i=0 ; i<= n-k ;i++) {
        string s1= s.substr (i,k);

         int cnt=0 ;
        for (int j=0 ; j<k ;j++) {
            if (s1[j] != s2[j] ) cnt++ ;
        }
        mn= min (mn , cnt);

         cnt=0 ;
        for (int j=0 ; j<k ;j++) {
            if (s1[j] != s3[j] ) cnt++ ;
        }
        mn= min (mn , cnt);

        cnt=0 ;
        for (int j=0 ; j<k ;j++) {
            if (s1[j] != s4[j] ) cnt++ ;
        }
        mn= min (mn , cnt);     
    }
    cout << mn <<"\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    build ();
    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}