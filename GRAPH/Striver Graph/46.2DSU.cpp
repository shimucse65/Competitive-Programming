#include <bits/stdc++.h>
using namespace std ;
#define int long long 
const int N=2e5+10 ;
int par[N] ,size[N];

void make (int u) {
  par[u]=u ;
  size[u]=1 ;
}

int find (int u) {
    if (par[u]==u) return u ;
    else return par[u]= find (par[u]) ;
}

void merge (int a ,int b) {
    int upa= find (a) ;
    int upb= find (b) ;
    if (upa==upb) return ;
   
    if (size [upa] <size[upb]) {
        size[upa]+= size[upb] ;
        par[upa]= upb ;
    }
    else {
        size[upb]+= size[upa] ;
        par[upb]= upa ;
   }
}

void solve () {
    int n;cin>>n ;
    for (int i=1 ;i<=n;i++) make (i) ;

    merge (3,5) ;

    if (find (3)==find (5)) cout <<"same ";
    else cout <<"different ";

}
signed main () {
    solve () ;
}