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
   int a,b,c;cin>>a>>b>>c ;
   
   if (a==0 && b==0) {
    for (int i=0 ;i<c+1 ;i++) cout <<1;
    cout <<"\n" ;
    return ;
   } 
   if (a==0 && c==0) {
    b++ ;
    int cur=0 ;
    for (int i=0;i<b;i++) {
        cout <<cur ; cur^=1 ;
    }
    cout<<"\n" ; return ;

   }
   if (b==0 && c==0) {
     for (int i=0 ;i<a+1 ;i++) cout <<0 ;
     cout <<"\n" ;
     return ;
   } 
   vector <int>bb;
   b= max (0ll ,b-1) ;
   int cur=1 ;
   for (int i=0;i<b ;i++) {
    bb.push_back (cur) ; cur^=1 ;
   }
   reverse (bb.begin () ,bb.end ()) ;
   for (auto it :bb) cout <<it ;
   a++ ;
   for (int i=0 ;i<a;i++ ) cout<<"0" ;
   c++ ;
   for (int i=0;i<c;i++) cout <<"1" ;
   cout <<"\n" ;   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}