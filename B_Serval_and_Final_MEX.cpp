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
    int n ;cin >>n ;
    int a[n];
    int zero=0 , one=0;
    for (int i=0 ;i<n ;i++) {
        cin >> a[i];
        if (a[i] ==0) zero++ ;
        else one ++;
    }
    if (zero==0) {
        cout << 1 <<"\n";
        cout << 1 <<" " << n <<"\n"; return;
    }
    if (one==0) {
        cout << 3 <<"\n";
        cout << 1 <<" " <<2 <<"\n";
        cout << 2 <<" " << n - 1 <<"\n";
        cout << 1 <<" " <<2 <<"\n";
        return;
    }
    int ind1=0 , ind2=0;

    if (zero == 1) {
        cout << 2 << "\n";
        int ind =0;
        for (int i=0 ;i<n ;i++) {
            if (a[i] == 0) {
                ind =i; break;
            }
        }
        if (ind==0) {
            cout << 1 <<" " << 2 <<"\n";
            cout << 1 <<" " << n-1 <<"\n";
        }
        else if (ind == n-1) {
            cout << n-1 <<" " << n <<"\n";
            cout << 1 <<" " << n-1 <<"\n";
        } else {
            cout << ind  <<" " << ind+1 <<"\n";
            cout << 1 <<" " << n-1 <<"\n";
        }
        return;
    }
    if (a[0]==0 && a[n-1]==0) {
        cout <<3 <<"\n";
        cout << 1 <<" " <<2 <<"\n";
        cout << 2 <<" " << n-1 <<"\n";
        cout << 1 <<" " <<2 <<"\n";
        return;
    }
    cout <<2 <<"\n";
    for (int i=0 ;i<n ;i++) {
        if (a[i] ==0) {
            ind1=i ; break;
        }
    }
    for (int i= n-1 ;i>=0 ;i--) {
        if (a[i]==0) {
            ind2 = i ; break;
        }
    }
    cout << ind1+ 1 <<" " << ind2 + 1 <<"\n";
    cout << 1 <<" " << n-ind2+ind1 <<"\n";
    
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