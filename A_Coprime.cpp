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
const int N = 1e6+10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int spf[N] ;

void  seive () 
 {
     for (int i=2;i<N;i++) spf[i]=i;
     for (int i=2;i<N;i+=2)
      {
        spf[i]=2;
      }
       for (int i=3;i*i<N;i++)
        {
            if (spf[i]==i)
             {
                for (int j=i*i;j<N;j+=i)
                 {
                    if (spf[j]==j)
                     {
                       spf[j]=i; 
                     }
                 }
             }
        }
     
 }
// vector <int> generate (int n)
//  {
//     vector <int>ans;
//     while (n!=1)
//      {
//         ans.push_back (spf[n]);
//         n/=spf[n];
//      }
//      return ans;
//  }

void solve() {

    int n ;cin>>n ;
    int a[n] ;
    for (int i=0 ;i<n;i++) cin>>a[i] ;
    int gg=0 ;
    for (int i=0 ;i<n;i++) {
        gg= __gcd (gg, a[i]) ;     
    }
    bool setwise=0 , notco=0 ;
    if (gg==1) {
        setwise=1 ;
    }
    set <int>st ;

    for (int i=0 ;i< n ;i++) {
        int tmp= a[i] ;
        int tmp2= a[i] ;
        set <int > divisors ;

            while (tmp!=1)
       {
         divisors.insert (spf[tmp]);
         tmp/=spf[tmp];
       }
     // for (auto it :divisors) cerr <<it <<" " ; cerr <<"\n" ;

        for (auto it :divisors) {
            if (!st.count (it)) {
                st.insert (it) ;
            } else {
                if (it!=1) {
                   // cerr << tmp2 <<" " << it <<"\n" ;
                    notco=1 ;
                }
            }
        }   
    }
   // cerr << notco <<" " <<setwise <<"\n" ;
    if (notco==0 && setwise==1) {
        cout << "pairwise coprime"<<"\n" ; 
    }
    else if (notco==1 && setwise==1) {
        cout <<"setwise coprime" <<"\n" ; 
    }
    else cout <<"not coprime" <<"\n" ;
    
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive () ;
    // for (int i=1;i<N;i++)
    //  {
    //     for (int j=i;j<N;j+=i)
    //      divisors[j].push_back (i);

    //  }
    //build () ;

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}