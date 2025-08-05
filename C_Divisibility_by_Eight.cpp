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
    string s ;cin>>s ;
    int n=s.size () ;

    for (int i=0;i<n ;i++) {
        if (s[i]=='0' ||s[i]=='8') {
            cout <<"YES\n" ;
            cout <<s[i] <<"\n" ;
            return ;
        }
    }
    for (int i=0;i<n ;i++) {
        for (int j=i+1 ;j<n;j++) {
            int b= (s[i]-'0')*10+ (s[j]-'0') ;
            if (b%8==0) {
                cout <<"YES\n" ;
                cout <<b <<"\n" ;
                return ;
            }
        }
    }

    for (int i=0 ;i<n ;i++) {
        for (int j=i+1 ;j<n ;j++) {
            for (int k=j+1 ;k<n ;k++) {
                int b= (s[i]-'0') *100+ (s[j]-'0')*10+ (s[k]-'0')*1;
               // cerr <<b <<"\n" ;
                if (b%8==0) {
                     cout <<"YES\n" ;
                     cout <<b <<"\n" ;
                     return ;
                }
            }
        }
    }
    cout <<"NO\n" ;
    
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