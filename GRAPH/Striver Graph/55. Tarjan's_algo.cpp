class Solution {
    int timer=1 ;
    private :
    void dfs (int node ,int parent, vector <int>g[] ,vector <int>&vis , vector <vector<int> >& bridge ,int low[] ,int in[] ) {
        
        vis[node]= 1 ;
        low[node]=in[node]=timer ; timer++ ;
        
        for (auto it :g[node]) {
            
            if (it==parent) continue ;
            if (vis[it]==0) {
                
                dfs (it ,node, g,vis ,bridge,low ,in) ;
                low[node]=min (low[node] ,low[it]) ;
                
                if (low[it]> in[node]) {
                    bridge.push_back ( {it ,node}) ;
                }
            } 
            else {
                low[node]=min (low[node] ,low[it]) ;
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector <int>g[n] ; 
        for (auto it :connections) {
              g[it[0]].push_back (it[1]) ;
              g[it[1]].push_back (it[0]) ;
        }
        
        vector <int>vis(n ,0)  ;
        
        int low[n] ,in[n] ;
        
        
        //store the bridges 
        vector <vector<int> > bridge ;
        dfs (0 ,-1, g,vis ,bridge,low ,in) ;
        return bridge ;
    
    } 
};