#include <iostream>
#include <vector>
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int xx = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    if (xx > 0) return 0; // ccw 
    else if (xx < 0) return 1; // cw
    return 2;
}
bool onSeg(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (orientation(x1, y1, x2, y2, x3, y3) != 2) return false;
    if (min(x1, x2) <= x3 && max(x1, x2) >= x3 && min(y1, y2) <= y3 && max(y1, y2) >= y3)
    return true;
    return false;
}
bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
       bool xx = onSeg(x1,y1,x2,y2,x3,y3);
       bool yy=  onSeg(x1,y1,x2,y2,x4,y4);
       bool zz = onSeg(x3,y3, x4,y4,x1,y1);
       bool aa = onSeg(x3,y3,x4,y4,x2,y2);

    if (xx|| yy || zz || aa){
        return true;
    }

    int f1 = orientation(x1, y1, x2, y2, x3, y3);
    int f2 = orientation(x1, y1, x2, y2, x4, y4);
    int f3 = orientation(x3, y3, x4, y4, x1, y1);
    int f4 = orientation(x3, y3, x4, y4, x2, y2);

    if ((f1 ^ f2) && (f3 ^ f4)) return true;
    return false;
}

void solve() {
    int x1,y1 ,x2 ,y2, tx ,ty, bx ,by;
    cin >> x1>>y1 >>x2 >>y2 >>tx >>ty>>bx>>by;

    vector <pii >v;
    
    v.push_back ({tx,ty});
    v.push_back ({bx,by});
    v.push_back ({min (tx,bx), min (ty,by)});
    v.push_back ({max (tx,bx), max (ty,by)});

   // sort (v.begin (), v.end (), cmp);

    for (int i = 0 ; i < 4 ;i++) {
        int x3= v[i].ff , y3= v[i].ss;
        int x4= v[(i + 1) % 4].ff, y4= v[(i + 1) % 4].ss;
        if (intersect (x1,y1,x2,y2,x3,y3,x4,y4)) {
            cout <<"T" <<"\n"; return;
        }
    }

    cout << "F" <<"\n";    
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