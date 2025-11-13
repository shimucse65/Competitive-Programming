#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10 ;
vector <int>g[N] ;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }



    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
int main() {
    int n;cin>>n;
    DisjointSet ds (n) ;
    
    int a[n][n] ;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j] ;
            if (a[i][j]==1) {
                ds.unionBySize (i,j) ;
            }
        }

    }
    set <int>st ;
    for (int i=0;i<n;i++) {
        st.insert (ds.findUPar (i)) ;
    }
  cout <<st.size () <<"\n";

}

//not working properly









