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
#define pdd pair <double,double>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double eps = 1e-9;


bool onSegment(pdd A, pdd B, pdd P) {
    return min(A.first, B.first) - eps <= P.first && P.first <= max(A.first, B.first) + eps &&
    min(A.second, B.second) - eps <= P.second && P.second <= max(A.second, B.second) + eps;
}


pdd intersectingPoint(pdd A, pdd B, pdd C, pdd D )
{
    
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);

    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);

    double determinant = a1*b2 - a2*b1;

    if (fabs (determinant) < eps)
    {
       return {inf,inf};
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return {x,y};
    }
}

void solve() {
    double x,y,r,c,px,py; cin >> x>>y>>r>>c>>px>>py;
    vector <pii>v(4);
    v[0]= {x,y};
    v[1]= {x+c ,y};
    v[2]= {x+c,y+r};
    v[3]= {x,y+r};

    double cx= x + c/2.0 , cy= y+r/2.0;
    vector <pdd > ans;

    for (int i=0 ; i< 4 ;i++){
        int x1 = v[i].ff , y1= v[i].ss;
        int x2= v[(i+1)%4].ff , y2= v[(i+1)%4].ss;

        pdd A = {x1,y1}, B= {x2,y2},C= {px,py}, D= {cx,cy};
        pdd xx= intersectingPoint (A,B,C,D);
        if (xx.ff != inf & xx.ss!=inf && onSegment(A,B,xx))
        ans.push_back (xx);       
    }
    sort (ans.begin () , ans.end ());
    cout << setprecision(10) << fixed << ans[0].ff <<" ";
    cout << setprecision(10) << fixed << ans[0].ss <<" ";
    cout << setprecision(10) << fixed << ans[1].ff <<" ";
    cout << setprecision(10) << fixed << ans[1].ss <<" ";     
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