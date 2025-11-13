
#include <bits/stdc++.h>
using namespace std;
vector<int> rank, parent, size; 
class DisjointSet {
    
public: 
    vector<int> rank, parent, size; 
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
        return  (x>=0 && x<n && y>=0 && y<n) ;
    }
    
   public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        //connect 1's for making component
        int n= grid.size () ;
        DisjointSet ds(n*n) ;
        
        for (int i=0 ;i<n;i++) {
            for (int j=0;j<n;j++) {
                
                if (grid[i][j]==0) continue ;
                
                int dx[]= {-1 ,1,0,0 } ;
                int dy[]= {0 ,0 ,-1 ,1 } ;
                
                for (int ind=0 ;ind <4 ;ind++) {
                    int newr= i+ dx[ind] ;
                    int newc= j+ dy[ind] ;
                    
                    if (isValid (newr ,newc ,n,n) && grid [newr][newc]==1) {
                        int curNode= i*n+ j ;  vector<int> rank, parent, size; 
                        int newNode= newr*n+ newc ;
                        ds.unionBySize (curNode ,newNode) ;
                    }
                }
            }
        }
        
        //try to convert zeros into one 
         int mx=0 ;
        for (int i=0;i<n;i++) {
          
            for (int j=0;j<n;j++) {
                
                
                if (grid [i][j]==1) continue ;
            
            
                int dx[]= {-1 ,1,0,0 } ;                                                       
                int dy[]= {0 ,0 ,-1 ,1 } ;
                set <int>st ;
                for (int ind=0 ;ind <4 ;ind++) {
                    int newr= i+ dx[ind] ;
                    int newc= j+ dy[ind] ;
                    
                    if (isValid (newr ,newc ,n,n) && grid [newr][newc]==1) {
                        int curNode= i*n+ j ;
                        int newNode= newr*n+ newc ;
                       st.insert (ds.findUPar (newNode)) ;
                    }
                }
             int cnt=0 ;
             for(auto it :st) cnt+= ds.size[it] ;
             mx= max (mx ,cnt+1) ;
             
            }
        }
        
      return mx ;
        
        
        
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

