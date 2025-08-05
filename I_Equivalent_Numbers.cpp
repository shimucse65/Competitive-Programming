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
const int N = 1e6 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int spf [N];
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
    int a,b ; cin >> a>>b;
   
    vector < int >aa=  generate (a);
    vector <int > bb=  generate (b);

    // for (auto it :aa) cerr << it <<" "; cerr <<"\n";
    // for (auto it :bb) cerr << it <<" " ; cerr <<"\n";

    map < int ,int >mpa , mpb;

    for (auto it :aa) mpa[it]++;
    for (auto it :bb) mpb[it]++;

    if (mpa.size () != mpb.size ()) {
        cout << "NO\n"; return;
    }
    set < int > sta , stb;
    for (auto it :aa) sta.insert (it);
    for (auto it :bb) stb.insert (it);

    if (sta!= stb) {
        cout <<"NO\n"; return;
    }
   
    float  xx= (mpa [aa[0]]*1.0/ mpb[aa[0]])*1.0;
    //cerr <<xx <<"\n";
    for (auto it :aa) {
        float yy= (mpa [it]*1.0/ mpb[it])*1.0;
        if (xx!=yy) {
            cout << "NO\n"; return;
        }
    }
    cout <<"YES\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     seive();
    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}