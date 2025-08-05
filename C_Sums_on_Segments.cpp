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

int kadanes (vector<int> &arr)
{
    if (!arr.size()) return 0ll;
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return max(res, 0ll);
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
    vector <int> tmpl ,tmpll , tmpr , tmprr;
    for (int i=ind-1 ;i>=0 ;i--) {
        sm+=a[i];
        lmn= min (lmn ,sm);
        lmx= max (lmx ,sm);
        tmpl.push_back (a[i]);
        tmpll.push_back (-a[i]);
    }
    sm=0 ;
    for (int i=ind+1 ;i<n ;i++) {
        sm+= a[i];
        rmx= max (rmx ,sm);
        rmn = min (rmn , sm);
        tmpr.push_back (a[i]);
        tmprr.push_back (-a[i]);
    }
   
    set <int>st;
    int mx1= kadanes (tmpl) ;
    int mn1= kadanes (tmpll)*-1;

    int mx2= kadanes (tmpr);
    int mn2= kadanes (tmprr)*-1;

    for (int i=mn1 ;i<= mx1 ;i++) st.insert (i);
    for (int i=mn2 ;i <= mx2;i++) st.insert (i);

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