#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
const int mod=1e9+7 ;

    

void solve() {
   int n;cin>>n ;
   vector <pair <int,int> >v1,v2 ;
   map <int ,int>zero ,one ;
   
   for (int i=0;i<n ;i++) {
       int x,y;cin>>x>>y ;
       if (y==1)
        {
            v1.push_back ({x,y}) ;
            one[x]=1 ;
        } 
        else {
            v2.push_back ({x,y}) ;
            zero[x]=1 ;
        }
   }
   
   int ans=0 ;
   for (auto it :v1) {
       int x=it.first ;
       if (zero[x]==1) ans+= (n-2) ;
       if (zero[x-1]==1 && zero[x+1]==1) ans++ ;
   }
   
   for (auto it :v2){
       int x=it.first ;
       if (one[x-1]==1 && one[x+1]==1) ans++ ;
   }
   
  cout <<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin>>t ;
    while (t--){
        solve ();
    }
    return 0;
}
