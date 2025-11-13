

#include <bits/stdc++.h>
using namespace std;

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
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
       int row=0 ,col=0 ;
       
       for (auto it :stones) {
           row= max (row ,it[0]) ;
           col= max (col ,it[1]) ;
       }
       DisjointSet ds (row+ col+1) ;
       
         map <int ,int >mp ; //(row ,col) ,markVis
         
       for (auto it :stones) {
           int newr= it[0] ;
           int newc= it[1]+ row+1 ;
           ds.unionBySize (newr ,newc) ;
           mp[newr]=1 ;
           mp[newc]=1 ;
       }
       
     int cnt=0 ;
     for (auto it :mp) {
         
        if (ds.findUPar (it.first)==it.first) cnt++ ; 
     }
       
     return  n- cnt ;   
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
