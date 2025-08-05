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
    int n ;cin>>n ;
    string s;cin>>s ;
    int cnt=0 ;
    for(int i=0 ;i+7<=n ;i++) {
        if (s.substr (i ,7)=="abacaba") cnt++ ;
    }
   
    if (cnt==1) {
        cout <<"Yes\n" ;
        for (int i=0;i<n ;i++) {
            if (s[i]=='?') s[i]='d' ; cout <<s[i] ;
        }
        cout <<"\n" ; return ;
    }
    if (cnt >1) {
        cout <<"No\n" ; return ;
    }
    string m="abacaba" ;
    int i=0 ,j=0,f=0;
    string tmp=s ;

    for (int ii=0 ;ii+6<=n ;ii++) {
        i=ii,j=0 ;
        for (int k=i ; k <i+7 ;k++) {
            if (s[k]==m[j])  j++ ;
            else if (s[k]=='?') {
               // cerr <<"*" <<" "<<s[j] <<"\n" ;
                s[k]=m[j] ;  j++ ;
            }
            else break ;
        }
       if (j==7) { 
        for (int i=0;i<n ;i++) {
            if (s[i]=='?') s[i]='d' ;      
        }
        int c=0 ;
        for (int i=0;i+6<n ;i++) {
            if (s.substr (i ,7)=="abacaba") c++ ;
        }
        //cerr <<c <<" "<<s<<"\n" ;
       if (c==1)
         {
             cout <<"Yes\n" ;
            for (auto it :s) cout <<it; cout <<"\n" ; return ;
         }
      }
      s=tmp ;
    
    }
    cout <<"No\n" ;
    
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