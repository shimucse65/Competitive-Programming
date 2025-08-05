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

     string s1,s2; cin >>s1 >> s2;
     
     int h1=( s1[0]-'0')* 10+ (s1[1]-'0');
      int m1=( s1[3]-'0')* 10+ (s1[4]-'0');
       int h2=( s2[0]-'0')* 10+ (s2[1]-'0');
        int m2=( s2[3]-'0')* 10+ (s2[4]-'0');

        //cerr << h1 <<" " <<m1 <<" " << h2 <<" " << m2 <<"\n";
     int xx = h1*60+m1;
     int yy= h2*60 + m2;
     int dif= yy-xx;
     dif/=2;

    //  cerr << dif <<"\n";
    //  cerr <<(302/60) <<" " << (302%60) <<"\n";

     h1 += (dif/60);
     m1 += (dif% 60);

     int extra_min= m1/60;
     h1 +=  extra_min;
     m1-= 60* extra_min;

    
    int hr=h1 , min=m1;
    if (hr >=0 && hr <=9) cout <<0<<hr;
    else cout << hr;

    cout <<":";

    if (min >=0 && min <=9) cout <<0 <<min;
    else cout <<min <<"\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;
    // cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}