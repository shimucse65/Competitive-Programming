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

vector <int> divi (int n) {
    vector <int>res ;
    for (int i=1 ;i*i <= n ;i++) {
        if (n%i==0) {
            res.push_back (i) ;
            if (i*i!=n) {
                res.push_back (n/i) ;
            }
        }
    }
    return res ;
}

void solve() {
    int n ,gg,ll ;cin>>n>>gg>>ll ;
    int a[n] ;
    int f1=0 ,f2=0 ;
    for (int i=0;i<n;i++) {
        cin>>a[i] ;
    }
    if (ll %gg !=0) {
        cout<<-1 <<"\n" ; return ;
    }
    vector <int>v= divi (ll) ;
  //  for (auto it :v) cerr <<it <<" " ; cerr <<"\n" ;

    set <int>st ;
    for (auto it :v) st.insert (it) ;

    int cur=gg ;
    set <int>st2 ;
    if (cur==1) {
        for (int i=0 ;i<n ;i++) st2.insert (a[i]) ;
    }
    else 
     {   
         while (cur <=ll) {
         st2.insert (cur) ;
         cur*= gg ;
         }
     }
    //for (auto it :st2) cerr <<it <<" " ;cerr <<"\n" ;
    int cnt=0 ;
    int ch=0 ;
    for (int i=0 ;i<n ;i++) {
        if (!st.count (a[i])  ||  ! st2.count (a[i])) {
            cnt++ ;
        } else ch++ ;
    }
    
    cout <<cnt <<"\n" ;

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