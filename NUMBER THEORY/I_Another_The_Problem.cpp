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
const int N = 1000010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int spf[N];
// vector<int> primeFactors(int n) 
// { 
//    vector<int>ans;
//     while (n % 2 == 0) 
//     { 
//        ans.push_back (2);
//        n = n/2; 
//     }   
//     for (int i = 3; i <= sqrt(n); i = i + 2) 
//     {       
//         while (n % i == 0) 
//         { 
//            ans.push_back (i);
//             n = n/i; 
//         } 
//     }     
//     if (n > 2)  ans.push_back (n);
//     return ans;        
// }

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
vector <int> generate (int n)
 {
    vector <int>ans;
    while (n!=1)
     {
        ans.push_back (spf[n]);
        n/=spf[n];
     }
     return ans;
 }
 
void solve() {
    int a,b,c,d,e,f ; cin >>a >>b >>c >>d >>e>>f;
    if (a==0 || c==0 || e==0) {
        cout <<1 <<"\n" ; return;
    }
    // a,b    
    int two=0 , five=0;
    vector < int>aa= generate (a);
    int tmp1 =0 , tmp2=0;
    for (auto it :aa) {
       if (it==2) tmp1++ ;
       else if (it==5) tmp2++;
    }
    two += tmp1*b;
    five += tmp2*b ;
    
    //c,d 
    vector < int>cc= generate (c);
     tmp1 =0 , tmp2=0;
    for (auto it :cc) {
       if (it==2) tmp1++ ;
       else if (it==5) tmp2++;
    }
    two+= tmp1*d;
    five+= tmp2*d ;


    //e,f 
    vector < int>ee= generate (e);
     tmp1 =0 , tmp2=0;
    for (auto it :ee) {
       if (it==2) tmp1++ ;
       else if (it==5) tmp2++;
    }
    two+= tmp1*f;
    five+= tmp2*f ;

    cout << min (two , five) <<"\n";
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive () ;
    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<":"<<" ";
        solve();
    }
}