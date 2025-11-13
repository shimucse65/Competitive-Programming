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

struct Point {
    int x,y;
};


int ori(Point A, Point B, Point C) {
    int val = (B.x - A.x )* (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

bool onSegment(Point A, Point B, Point C) {
    if (ori(A, B, C) != 0) return false;
    if (min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) &&
        min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y))
        return true;
    return false;
}

int check (Point pp , vector <Point> &v) {
    int n = v.size ();
    int o1 = ori (v[0] ,v[1] ,pp);
    int o2 = ori (v[0] ,v[n-1], pp);

   
    if (o1 == 0 && onSegment (v[0], v[1], pp)) return 0;
    else if (o2 == 0 && onSegment (v[0], v[n-1], pp)) return 0;
    else if (o1 < 0 || o2 > 0) return 1;

    int l = 0 , r= n-1 ;
    int ans = 1;
    while (l <= r) {
        int mid = l + (r - l)/2;
        int o = ori (v[0] , v[mid] ,pp);
        if (o  >  0) {
            ans = mid; l = mid + 1;
        } else  {
            r = mid -1;
        }
    }
    int oo = ori (v[ans] , v[(ans + 1 ) % n] , pp);

    if ( oo > 0) return -1;
    else if ( oo == 0 && onSegment (v[ans] , v[(ans + 1 ) % n] , pp)) return 0;
    return 1;
}

void solve() {
    int n; cin >> n;
    vector <Point> v(n);

    for (auto &[x,y] :v) cin >> x >> y;

    int q; cin >>q;
    while (q--) {
        Point pp;
        cin >> pp.x >> pp.y;
        int xx = check ( pp ,v);
        if (xx == 0 ) cout <<"ON\n";
        else if ( xx == 1) cout << "OUT\n";
        else cout <<"IN\n";
    }   
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