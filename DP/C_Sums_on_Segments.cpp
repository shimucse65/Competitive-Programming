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


pair <int ,int>kadanes (vector <int>&v) {
   
    int mx=0 ,cur=0;
    for (auto it :v) {
        cur= max (0ll , cur+it);
        mx= max (mx, cur);
    } 
    for (int i=0 ;i<v.size();i++) v[i]= -1*v[i];
     int mx2=0 ;
     cur=0;
    for (auto it :v) {
        cur= max (0ll , cur+it);
        mx2= max (mx2, cur);
    }
    return {mx ,mx1};  
}
void solve() {

    int n;cin>>n ;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    int ind=-1;
    for (int i=0 ;i<n ;i++) {
        if (a[i]!=-1 && a[i] !=1) {ind=i ;break;}
    }
    int lmn= 0 , lmx=0 , rmn= 0 ,rmx=0;
    int sm=0;
    for (int i=ind-1 ;i>=0 ;i--) {
        sm+=a[i];
        lmn= min (lmn ,sm);
        lmx= max (lmx ,sm);
    }
    sm=0 ;
    for (int i=ind+1 ;i<n ;i++) {
        sm+= a[i];
        rmx= max (rmx ,sm);
        rmn = min (rmn , sm);
    }
     
    set <int>st;

    vector <int>tmpl ,tmpr ;
    for (int i = ind + 1 ;i < n ;i++) tmpr.push_back (a[i]);
    for (int i = 0 ;  i < ind-1 ;i++) tmpl.push_back (a[i]);

    pair <int ,int>pp= kadanes (tmpl);
    pair <int ,int>qq= kadanes (tmpr);

    //cerr <<pp.ff <<" " << pp.ss <<" " << qq.ff <<" " <<qq.ss <<"\n";
    for (int i=pp.ff ;i<= pp.ss;i++)  st.insert (i);
    for (int i=qq.ff ;i<= qq.ss ;i++) st.insert (i);

    if (ind==-1) {
        cout << st.size () <<"\n";
        for (auto it :st) cout << it <<" " ; cout <<"\n" ;
        return;
    } 

    int mnn= lmn+ rmn ;
    int mxx= lmx+ rmx;
    for (int i= a[ind]+mnn ;i <= a[ind]+mxx ;i++) st.insert(i);
    cout <<st.size() <<"\n";
    for (auto it :st) cout << it <<" "; cout <<"\n";

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