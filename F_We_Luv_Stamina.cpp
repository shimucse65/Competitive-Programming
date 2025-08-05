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
    int n;cin>>n;
    int a[n][4];

    for (int i=0 ;i<n ;i++) {
        string s;cin >>s;
       // cerr << s <<"\n";
        for (int j=0 ; j<4 ;j++) {
            int xx = s[j]-'0';
            a[i][j]= xx;
        }
    }
    for (int i= n-1 ; i>=1 ;i--) {
        int x= a[i][0];
        int y= a[i][1];
        int xx = a[i-1][0];
        int yy= a[i-1][1];

        int f=0 ;
        if ((x==1 ||  y==1) && (xx==1 || yy==1)) f=1;
        if (f) {
            if (xx==1) {
                a[i-1][0]=0 ; a[i][0]=1;
            } else if (yy==1) {
                a[i-1][1]=0 ; a[i][1]=1;
            }
        }


         x= a[i][2];
         y= a[i][3];
         xx = a[i-1][2];
         yy= a[i-1][3];

         f=0 ;
        if ((x==1 ||  y==1) && (xx==1 || yy==1)) f=1;
        if (f) {
            if (xx==1) {
                a[i-1][2]=0 ; a[i][2]=1;
            } else if (yy==1) {
                a[i-1][3]=0 ; a[i][3]=1;
            }
        }

    }

    for (int i=0;i<n ;i++) {
        for (int j=0;j<4 ;j++) cout << a[i][j];
        cout <<"\n";
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