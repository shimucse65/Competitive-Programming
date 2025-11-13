#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int inf=1e15 + 10 ;
const int mod=1e9+7 ;
#define ff first 
#define ss second 

int fen[N] ;
int n,q;
void add (int pos ,int val) {
    
    for (int i=pos ;i<=n ;i += i&-i ) fen[i]+=val ;
}

int sum (int ind){
    int res=0 ;
    for ( int i=ind;i>=1 ;i-= i&-i) res+= fen[i] ;
    return res ;
}

int qur (int l ,int r){
    if (l>r) return 0ll ;
    return sum (r)- sum (l-1) ;
}

void solve() {
    
    cin>>n>>q ;
    int a[n+1] ;
    for (int i=1 ;i<=n;i++) cin>>a[i] ;
    
    for (int i=1;i<=n;i++) add (i ,a[i]);
    
    while (q--) {
        int ty;cin>>ty ;
        if (ty==1){
           int pos ,val; cin>>pos >>val ;
           add (pos ,-a[pos] +val) ;
           a[pos]=val ;
        } else {
            int l,r ;cin>>l>>r ;
            cout <<qur (l,r )<<"\n" ;
        }
    }
}

signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;
    // while (t--)
    {
        solve () ;
    }
   
}
    
 
 

