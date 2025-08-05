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
    int a[n];
    for (int i=0;i<n ;i++) cin >> a[i];

     vector <int >v;
     int p= a[0];    
     for (int i=0;i<n ;i++) {
        if (a[i]==p) v.push_back (i);
     }

     if (v.size ()==1) {
        cout << 1 <<"\n"; return;
     }
   
     int cnt=0;
     set < int > pv , nw , need;

     for (int i = 0 ; i < v.size () -1 ; i++) {
        int st=v[i] , en=v[i+1];
        
       // cerr << st <<" " << en <<"\n";

        for (int j= st+1 ; j <= en-1 ;j++) {
        
            //cerr << j <<"\n";
            if (pv.count (a[j])) {
                pv.erase (a[j]);
                nw.insert (a[j]);
            } else nw.insert (a[j]);
        }

        if (pv.size ()==0) cnt++ ;
        if (i== v.size ()-2) need = pv;
        
       pv= nw;
        
     
     }
     if (pv.size()==0) {
        cout << cnt+1 <<"\n"; return;
     }
     for (int i= v.back ()+1 ; i < n ;i++) {
        if (pv.count (a[i])) {
            pv.erase (a[i]);
        }
     }
     if (pv.size ()==0) cnt++;

     cout << cnt+1 <<"\n";  
     
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