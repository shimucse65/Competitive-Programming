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

bool orient (int x1 , int y1 , int x2 ,int y2 , int x3 , int y3) {
    int xx = (y3-y2)*(x2-x1)- (y2-y1)*(x3-x2);
    return xx==0;
}
vector < double >coff (int x1 , int y1 , int x2 , int y2) {
    vector <double > ans(3);
    ans[0]= x1-x2;
    ans[1]= y1-y2;
    ans[2]= (x1*x1+ y1*y1 - x2*x2- y2*y2)/2.0;
    return ans;
}
void solve() {
    int x1 ,y1 , x2 ,y2, x3,y3;
    while ( cin >>x1>> y1 >> x2>>y2 >>x3>>y3) {
       
        vector <double >res1= coff (x1,y1,x2,y2);
        vector <double >res2= coff (x2,y2,x3,y3);

        double a1 = res1[0] , b1=res1[1] ,  c1= res1[2];
        double a2=  res2[0] ,  b2 =res2[1] ,c2 =res2[2];
        
        if (orient (x1,y1,x2,y2 ,x3,y3)) cout <<"Impossible"<<"\n";
        else {
            cout << setprecision (10) << fixed ;
            cout <<( b2*c1- b1*c2 )/ (a1*b2- a2*b1) <<" ";
            cout <<( a1*c2- a2*c1 )/(a1*b2- a2*b1);
            cout <<"\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;// cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}