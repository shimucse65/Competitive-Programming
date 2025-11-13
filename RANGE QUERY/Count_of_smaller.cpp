class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size () ;
        vector <int>ans (n,0) ;
        vector <pair <int,int>>v ;
        for (int i=0;i<n;i++){
            v.push_back ({nums[i] ,i}) ;
        }
        sort (nums.begin () ,nums.end ()) ;

        for (auto it :v){
            int val= it.first ;
            int ind= it.second ;
            ind++ ;
            ans[val] = qur (n-1)- qur (ind) ;
        }
        return ans ;
    }
};