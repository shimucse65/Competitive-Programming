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

int digit_sum (string s) {
    int res=0 ;
    for (auto it:s) res+= (it-'0') ;
    return res ;
}
string addStrings (string num1 ,string num2) {

       reverse (num1.begin () ,num1.end ()) ;
       reverse (num2.begin () ,num2.end ()) ;

     int mx= max (num1.size () ,num2.size ()) ;
     string res="" ; int crr=0,sm=0 ;

    for (int i=0;i<mx ;i++) {
        int dig1= (i>=num1.size ()? 0: num1[i]-'0') ;
        int dig2 = (i>=num2.size () ?0:num2[i]-'0') ;
        sm= dig1+dig2+crr ;
        res+= (sm%10)+'0';
        crr=sm/10 ;
    }
    if (crr>0) res+=crr+'0' ;
    reverse (res.begin () ,res.end ()) ;
    return res ;

}


void solve() {
    string n,s;cin>>n>>s ;
    int sm=0 ;
    for (int i=0;i<n.size();i++) sm+= n[i]-'0' ;
    int sm2= stoll (s) ;
    if (sm <=sm2) {
        cout <<0<<"\n" ; return ;
    }
    int ans=0  ; 
    int sz= n.size () ;
    string nn= n ;

    for (int i=sz-1 ;i>=0;i--) {


        string res="" ;
        for (int j=i ;j<sz;j++) res+=nn[j] ;
       

        string b="1" ;
        int z=res.size() ;
        for (int i=0;i<z;i++) b+="0" ;
       

        int add= stoll (b)-stoll (res) ;
        nn= addStrings (nn ,to_string (add)) ; ans+= add ;
        if (digit_sum (nn)<=sm2) break;
      

    }
    cout <<ans<<"\n" ; 
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