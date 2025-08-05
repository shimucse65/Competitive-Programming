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

// All about binary search (0 based)
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x: v) cin >> x;

    // kono number er cheye boro koto ta ache
    int id = upper_bound(v.begin(), v.end(), 5) - v.begin();
    cout << n - id << "\n";

    // jodi kew boro na thake tahole ki return korbe id ?
    // ans : ekdom last index er o porer iterator (n)
     id = upper_bound(v.begin(), v.end(), 12) - v.begin();
    cout << id << " " << n - id << "\n";

    // kono number er soman ba boro
    id = lower_bound(v.begin(), v.end(), 5) - v.begin();
    cout << n - id << "\n";

    // jodi soman ba boro kew na thake 
    // n return korbe
      id = lower_bound(v.begin(), v.end(), 13) - v.begin();
      cout << id << " " << n - id << "\n";

      // kono number er cheye choto koto ta ache ?
      // lower bound return kore soman ba boro, tar mane lower 
      //bound er age jara ache tara sobai choto
      cout << lower_bound(v.begin(), v.end(), 4) - v.begin() << "\n";
      cout << lower_bound(v.begin(), v.end(), 4) - v.begin() << "\n";

      // soman ba choto koyta ache 
      // upper bound return korbe boro tar index mane 
      // tar left e jara ache sobai soman ba choto
      cout << upper_bound (v.begin(), v.end(), 5) - v.begin() << "\n";

      // soman koto ta ache ?
      // total - boro - choto
      int tot = n;
      int choto = lower_bound (v.begin(), v.end(), 5) - v.begin();
      int boro = n - (upper_bound(v.begin(), v.end(),5)-v.begin());
      //cout << n << " " << choto << " " << boro << "\n";
      cout << n - choto - boro << "\n";
      
      // immidiate choto element
      id = lower_bound(v.begin(), v.end(), 5) - v.begin();
       if(id != 0) id -- ;
      cout << v[id] << "\n";
      // jodi choto keu na thake tahole id er value 0 return korbe
      // ejonno agey check kora better

      // immidiate boro element (upper bound)
      // na thakle id = n return korbe 

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