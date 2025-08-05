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
    int n , k; cin>>n>>k ;
    int a[n];
    for (int i=0 ;i<n ;i++) cin>>a[i];

    map < int ,int> mp1 ,mp ,mp3;

    for (int i=0 ;i<n ;i++) mp1[a[i]]++ ;
    int mx=-inf ;
    for(auto it :mp1) {
        mx= max (mx , it.ss);
    }
    if (mx== mp1[k]) {
        cout << 0 <<"\n"; return ;
    }
     mx=-inf;
     for (int i=0 ;i<n ;i++) {
        if (a[i]==k) {
            mp[k]++ ;
            if (mp[k] >= mx) {
                cout << 1<<"\n"; return;
            }
             mx= max (mx , mp[a[i]]);
        } else {
            mp[a[i]]++ ;
            mx= max (mx , mp[a[i]]);
        }
     }
     mx=-1 ;
     for (int i=n-1 ;i>=0 ;i--) {
        if (a[i]==k) {
            mp3[k]++ ;
            if (mp3[k] >= mx) {
                cout << 1<<"\n"; return;
            }
             mx= max (mx , mp3[a[i]]);
        }

        else {
            mp3[a[i]]++ ;
            mx= max (mx , mp3[a[i]]);
        }

     }

     cout <<2 <<"\n";


    
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