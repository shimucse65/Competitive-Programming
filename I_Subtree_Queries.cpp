#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10 ;
vector <int>g[N] ;
int val[N] ,ar[N];
int st[N*4] ;
int pos[N] ,timer=1 ,sz[N] ;

void dfs (int node ,int par) {
    pos[node]= timer++ ;
    ar[pos[node]]= val[node] ;
    sz[node]=1 ;
    for (auto it :g[node]) {
        if (it==par) continue ;
        dfs (it ,node) ;
        sz[node]+= sz[it] ;     
    }   
}
void build(int si , int ss , int se)
{
	if(ss == se){
		st[si] = ar[ss];
		return;
	}
	int mid = (ss + se) >> 1;
	build(2*si , ss , mid);
	build(2*si + 1 , mid+1 , se);
	
	st[si] = st[2*si] + st[2*si + 1];
}

 
void update(int si , int ss , int se , int qi , int  dx)
{
	if(ss > qi || se < qi) return;
	if(ss == se)
	{
		st[si] += dx;
		return;
	}
	int mid = (ss + se) >> 1;
	update(2*si , ss , mid , qi , dx);
	update(2*si + 1 , mid+1 , se , qi , dx);
	
	st[si] = st[2*si] + st[2*si + 1];
}
 
int  query(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si];
	
	int mid = (ss + se) >> 1;
	int L = query(2*si , ss , mid , qs , qe);
	int  R = query(2*si + 1 , mid+1 , se , qs , qe);
	
	return L + R;
}
 
void solve() { 
    
    int n,q;cin>>n>>q ;
    for (int i=1 ;i<=n;i++) cin>>val[i] ;
    for (int i=0 ;i<n-1 ;i++) {
        int u,v;cin>>u>>v ;
        g[u].push_back (v) ;
        g[v].push_back (u) ;
    }
    dfs (1,-1) ;
  //  for (int i=1 ;i<=n ;i++) cerr <<pos[i] <<" " ; cerr <<"\n" ;
    build (1,1,n) ;
    while (q--) {
      int x;cin>>x ;
      if (x==1) {
          int x,y;cin>>x>>y ;
          update (1,1,n ,pos[x] , -ar[pos[x]]+y) ;
          ar[pos[x]]= y ;
          
      } 
      else {
          int x;cin>>x ;
          cout << query (1,1,n , pos[x] , pos[x]+ sz[x]-1) <<"\n";
      }
  }
   
}
// void solve () {
//     int n,q ;cin>>n>>q ;
//     for (int i=1 ;i<=n;i++) cin>>val[i] ;
//     for (int i=0 ;i<n-1; i++) {
//         int x,y ;cin>>x>>y ;
//         g[x].push_back (y) ;
//         g[y].push_back (x) ;
//     }
//     dfs (1,-1) ;
//     build (1,1,n) ;
//     while (q--) {
//         int l;cin>>l;
//         if (l==1) {
//             int y ;cin>>y ;
//             update (1,1,n , pos[l] , -ar[pos[l]]+y) ;
// //             ar[pos[l]]= y ;
//         } else {
//             int r ;cin>>r ;
//             query (1,1,n , pos[l] , pos[l]+ sz[l]-1) ;
//         }
//     }
// }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    {
        solve(); 
    }
    return 0;
}
