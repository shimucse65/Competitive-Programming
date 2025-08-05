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

int ori(int x1, int y1, int x2, int y2, int x3, int y3) {
    int xx =  (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
   // cerr << x1 <<" " << y1 <<" " <<x2<<" " <<y2 <<" " <<x3 <<" " <<y3 <<" "<<"\n";
    if (xx > 0) return 1; // ccw 
    else if (xx < 0) return -1; // cw
    return 0;
}
bool onSeg(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (ori(x1, y1, x2, y2, x3, y3) != 0) return false;
    if (min(x1, x2) <= x3 && max(x1, x2) >= x3 && min(y1, y2) <= y3 && max(y1, y2) >= y3)
    return true;
    return false;
}


void solve() {
    int n; cin >>n;
    vector <pii > v;
    for (int i=0 ;i<n ;i++) {
        int x,y; cin >> x >> y;
        v.push_back ({x,y});
    }
    int q; cin >>q ;
    while (q--) {
        int x, y ; cin >> x >> y;
        int o = ori (v[0].ff , v[0].ss , v[1].ff , v[1].ss, x,y);
       // cerr << x <<" " << y <<" " << o <<"\n";
        if (o > 0) cout << "OUT\n";
        else if (o==0 && onSeg (v[0].ff , v[0].ss , v[1].ff , v[1].ss, x,y)) cout << "ON\n";
        else {
            o= ori (v[0].ff , v[0].ss , v.back().ff , v.back().ss, x,y);
            if (o > 0) cout << "OUT\n";
            else if (o==0 && onSeg (v[0].ff , v[0].ss , v[1].ff , v[1].ss, x,y)) cout << "ON\n";
            else {
                int l= 0 , r= v.size()-1;
                int ans=0;
                while (l <= r) {
                    int mid = l + (r-l)/2;
                    if (ori (v[0].ff , v[0].ss, x,y,v[mid].ff, v[mid].ss) > 0) {
                        ans = mid;
                        l= mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                int xx= ori (v[ans].ff , v[ans].ss, v[(ans+1)%n].ff , v[(ans+1)%n].ss,x,y);
                if (xx < 1) cout << "IN" <<"\n";
                else if (xx == 0) cout <<"ON\n";
                else cout <<"OUT\n"; 
            }
        } 
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