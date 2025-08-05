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

int dx[]= {0, 0 ,-1, 1};
int dy[] = {1,-1, 0, 0};

bool isvalid (int i,int j) {
    if ( i >=0 && i < 3 && j >=0 && j < 3) return true;
    return false;
}
void solve() {
    int a[3][3];
    for (int i=0;i <3 ;i++) {
        for (int j=0 ; j<3 ;j++) cin>> a[i][j];
    }
    map <pii, int >mp;
    for (int i=0 ; i<3 ;i++) {
        for (int j=0 ; j<3;j++) {
            mp[{i,j}] += a[i][j];

            for (int k=0 ; k<4 ;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isvalid (nx , ny)) mp[{nx, ny}] += a[i][j];
            }
            
        }
    }
    for (int i=0; i<3 ;i++) {
        for (int j=0 ; j<3 ;j++) {
           // cerr << mp[{i,j}] <<" ";
            if (mp[{i,j}] & 1) cout <<0;
            else cout <<1;
        }
        cout <<"\n";
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