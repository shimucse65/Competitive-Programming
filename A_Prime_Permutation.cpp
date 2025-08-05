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
const int N = 1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int vis[1010];
int vv [1010];
vector <int> g[N];

void solve() {
    string s; cin>>s;
    int n= s.size ();
    if (n<=3) {
        cout<< "YES\n"; 
        cout << s <<"\n"; return;
    }
    vector < int> pm ;
    for (int i=2 ; i<=n ;i++) {
        if (vis[i]==0) {
            for (int j=i*i ;j <=n ;j+=i) vis[j]=1;
        }
    }
    for (int i=2 ;i<=n ;i++) {
        if (vis[i]==0) pm.push_back (i);
    }
    
    map <int ,int> mp;
    for (auto it :pm) {       
        int f=0;
        int xx=0;
        for (int i= it ; i<=n ;i+=it) {
           if (vv[i]) {
              xx= mp[i];
              f=1 ; break;
           }
        }
        if (f) {
           for(int i= it ; i<=n ;i += it) {
            mp[i]=xx;
           } 
        } else {
            for(int i= it ; i<=n ;i += it) {
            mp[i]=it;
            vv[i] =1;
           } 
        }
    }
   // for (auto it :mp) cerr << it.ff <<" " << it.ss <<"\n";

   vector <int>nn;
   map <int,int> mp2 ;
   for (auto it :mp) {
    mp2[it.ss]++;
   }
  //for (auto it :mp2) cerr << it.ff <<" " << it.ss <<"\n";
  for (auto it :mp2) nn.push_back (it.ss);
  sort (nn.begin () ,nn.end () , greater <int>());
  //for (auto it :nn) cerr << it <<" ";

   map <char,int> mp3 ;
   for (auto it :s) {
     mp3[it]++;
   }
   priority_queue <int> pq ;
   for (auto it :mp3) pq.push(it.ss);

   for (auto it :mp2) {
    if (  pq.empty()  || it.ss > pq.top () ) {
        cout << "NO\n"; return;
    }
      int pp= pq.top () ;
      pp -= it.ss;
      pq.pop ();
      if (pp!=0) pq.push(pp);
   }


cout <<"YES\n";
map < int ,char > mp5;
for (auto it:mp3) {
    mp5 [it.ss] = it.ff;
}


stack < char > st;
for (auto it :mp5) {
    for (int i=0 ;i<it.ff ;i++) st.push (it.ss);
}

 vector <pii > mm;
 for (auto it :mp2) {
    mm.push_back ({it.ss, it.ff});
 }
 
 sort (mm.rbegin () ,mm.rend () );
 //for (auto it :mm) cerr << it.ff <<" " << it.ss <<"\n";
  vector <char>ans(n+1,'*');

   for (auto it :mp) {
      // cerr << it.ff <<" " << it.ss <<"\n";
        g[it.ss].push_back (it.ff);
   }
   for (auto it :mp2) {
    int zz= it.ff;
     for (auto it2 : g[zz])  {
        ans[it2] = st.top () ; st.pop ();
     }
   }

  for (int i=1 ;i<=n ;i++) {
    if (ans[i]=='*') {
        ans[i]= st.top (); st.pop ();
    }
  }
  for (int i=1 ;i<=n ;i++) cout << ans[i];
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}