

#include <bits/stdc++.h>
using namespace std;

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

class Solution { 
    private :
    bool isValid (int x,int y ,int n ,int m) {
        return  x >=0 && x<n && y>=0 && y<m ;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &v) {
       
       DisjointSet ds (n*m) ;
       int vis[n][m] ;
       memset (vis ,0,sizeof vis) ;
       
       int cnt=0 ;
       vector<int>ans ;
       
       for (auto it :v) {
           int row= it[0] ;
           int col= it[1] ;
           if (vis[row][col]) {
               ans.push_back (cnt) ; continue ;
           }
           vis[row][col]=1 ; cnt++ ;
           
           int dx[4]= {-1 ,1,0,0 } ;
           int dy[4]= {0 ,0 ,1,-1 } ;
           
           for (int ind=0 ;ind <4 ;ind++) {
               
               int adjr= row+dx[ind] ;
               int adjc= row+dy[ind] ;
               if (isValid (adjr ,adjc,n,m)) {
                   
                   if (vis [adjr][adjc]) {
                       int curNode= row*m+ col ;
                       int adjNode = adjr *m+ adjc;
                       if (ds.findUPar (curNode) != ds.findUPar (adjNode) ) {
                           ds.unionBySize (curNode,adjNode); cnt-- ;
                       }
                   }
               }
               
           }
           ans.push_back (cnt) ; 
       } 
      return ans ;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
    
}  
    
    
    
    
    
    
    
    
    
    