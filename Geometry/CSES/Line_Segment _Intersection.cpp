#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

int magic (int x1,int y1 , int x2 , int y2 , int x3 ,int y3) {
  
    int xx=  (y2-y1)*(x3-x2)- (y3- y2)*(x2-x1);

    if (xx > 0) return 0;//ccw
    else if (xx < 0) return 1; //cw
    return 2; //colli
}
bool onSeg (int x1 ,int y1 , int x2 ,int y2 ,int x3 ,int y3){
    if (magic (x1,y1,x2,y2, x3,y3)!=2) return false;
    if (min (x1,x2) <= x3 && max (x1,x2)>=x3 && min (y1,y2) <= y3 && max(y1,y2)>=y3)
    return true;
    return false;
}
void solve() {
    int x1,y1 , x2, y2 , x3 ,y3 , x4,y4;
    cin >> x1 >>y1 >>x2>>y2>>x3>>y3>>x4>>y4;

    int xx = onSeg(x1,y1,x2,y2,x3,y3);
    int yy=  onSeg(x1,y1,x2,y2,x4,y4);
    int zz = onSeg(x3,y3, x4,y4,x1,y1);
    int aa = onSeg(x3,y3,x4,y4,x2,y2);

    if (xx==1 || yy==1 || zz==1 || aa==1){
        cout <<"YES\n"; return;
    }

    bool f1 = magic (x1,y1,x2,y2,x3,y3);
    bool f2 = magic (x1,y1,x2,y2,x4,y4);

    bool f3= magic (x3,y3,x4,y4, x1,y1);
    bool f4= magic (x3,y3,x4,y4, x2,y2);

    if ((f1^f2) && (f3^f4)) cout <<"YES\n";
    else cout <<"NO\n";    
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