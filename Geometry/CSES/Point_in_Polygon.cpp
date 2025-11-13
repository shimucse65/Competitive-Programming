#include <bits/stdc++.h>
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

    int f1 = orientation(x1, y1, x2, y2, x3, y3);
    int f2 = orientation(x1, y1, x2, y2, x4, y4);
    int f3 = orientation(x3, y3, x4, y4, x1, y1);
    int f4 = orientation(x3, y3, x4, y4, x2, y2);

    if ((f1 ^ f2) && (f3 ^ f4)) return true;
    return false;
}
int RayCast (vector <pii>&v , int x1, int y1) {

        int n= v.size();
        int x2 = INT_MAX, y2 = INT_MAX + 1;
        int cnt = 0, f = 0;

        for (int i = 0; i < v.size(); i++) {
            int x3 = v[i].ff, y3 = v[i].ss;
            int x4 = v[(i + 1) % n].ff, y4 = v[(i + 1) % n].ss;

            int res = intersect(x3, y3, x4, y4, x1, y1, x2, y2);

            if (onSeg(x3,y3 ,x4,y4 ,x1,y1)) {
                f = 1;
                break;
            } else if (res) {
                cnt++;
            }
        }
        if (f) return 1;
        else if (cnt & 1) return 2;
        return 3;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<pii> v;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    while (q--) {
        int x1, y1;
        cin >> x1 >> y1;
        int x2 = INT_MAX, y2 = INT_MAX + 1;

        int res= RayCast (v,x1,y1);

        if (res==1) cout <<"BOUNDARY"<<"\n";
        else if (res==2) cout << "INSIDE"<<"\n";
        else cout <<"OUTSIDE"<<"\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}
