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

int cumi[N] ;
void calc () {
    cumi[0]=1 ;
    int cur=2 ;
    int i=1 ;
    while (cur <= N) {
        cumi[i]=cumi[i-1]+ cur ;
        cur++ ;
        i++ ;
    } 
}

void solve() {
   int a, b;cin>>a>>b ;
   // for (int i=0;i<50 ;i++) cout <<cumi[i] <<" " ; cout <<"\n" ;
   int dif= max (a,b)- min (a,b) ;
   if (dif==0) {
    cout <<0 <<"\n" ; return ;
   }
   int it= lower_bound (cumi, cumi+N , dif)- cumi ;
   if (cumi[it]==dif) {
    cout <<it+1 <<"\n" ; return ;
   }  else {
        it= max (0ll , it-1) ;
        dif-= cumi[it] ;
        cout << (it+1)+ dif*2 <<"\n" ;
   }
    
}

signed main() {
    calc () ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}