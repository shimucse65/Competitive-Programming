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

int orient (int x1 ,int y1 , int x2, int y2 , int x3 ,int y3) {
    int xx= (y3-y2)* (x2-x1) - (y2-y1)*(x3-x2);
    if (xx > 0) return 1;
    else if (xx < 0) return 2;
    return 3;
}
bool intersect (int x1 ,int y1 , int x2 ,int y2 , int x3 ,int y3,int x4,int y4){
    int f1 = orient (x1 ,y1 ,x2 ,y2 ,x3,y3);
    int f2=  orient (x1 ,y1 ,x2 ,y2 ,x4,y4);

    int f3 = orient (x3 ,y3, x4 ,y4 , x1,y1);
    int f4 = orient (x3 ,y3, x4 ,y4 , x2,y2);

    if ((f1 + f2 == 3) && ( f3+f4 == 3)) return true;
    return false;
}
void solve() {
    int a,b,c,d;cin >>a>>b>>c>>d;
    vector <pii>v(4);
    v[0]= {a,b};
    v[1]= {c,b};
    v[2]= {c,d};
    v[3]= {a,d};

    int q;cin >>q;
    int x2= INT_MAX , y2= INT_MAX + 1;
    while (q--) {
        int x1,y1; cin >>x1>>y1;
        int cnt=0;
        for (int i = 0 ; i < 4 ;i++) {
            int x3 = v[i].ff , y3= v[i].ss;
            int x4 = v[(i+1)%4].ff , y4= v[(i+1)%4].ss;
            if (intersect (x1,y1,x2,y2 ,x3,y3,x4,y4)) cnt++;
        }
        if (cnt & 1) cout << "Yes\n";
        else cout <<"No\n";
    }    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": \n";
        solve();
    }
}