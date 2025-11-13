
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
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &v) {
       
        int n=v.size () ;
         DisjointSet ds (n);
        unordered_map <string ,int>mp ;
        for (int i=0;i<n;i++) {
            for (int j=0;j<v[i].size() ;j++) {
                string s= v[i][j] ;
                if (mp.find (s)==mp.end ()) {
                    mp[s]=i ;
                }
                else {
                   ds.unionBySize (i ,mp[s]) ; 
                }
            }
        }
        
        vector <string >g[n] ;
        
        for (auto it :mp) {
            
            string mail=it.first ;
            int id= ds.findUPar (it.second );
            g[id].push_back (mail) ;
            
        }
        
       vector <vector <string >>ans ;
       
       for (int i=0;i<n;i++) {
           if (g[i].size()==0) continue ;
           sort (g[i].begin () ,g[i].end ()) ;
           vector <string>tmp ;
           tmp.push_back (v[i][0]) ;
           
           for (auto it : g[i]) {
               tmp.push_back (it) ;
           }
           ans.push_back (tmp);
       }
     return ans ;  
    
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

       
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}