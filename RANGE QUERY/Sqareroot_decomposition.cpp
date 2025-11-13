#include "bits/stdc++.h"
using namespace std;
#define ll long long
 
class sqrtDecomposition {
    private:
        int blockSize;
        vector<ll> values, blocks;
    
    public:
        sqrtDecomposition(vector<int>& input) {
            int n = input.size();
            blockSize = ceil(sqrt(n));
            int blockIndex = -1;
            
            values.resize(n);
            blocks.resize(blockSize);
            
            for(int i = 0; i < n; ++i) {
                values[i] = input[i];
                if(i % blockSize == 0) blockIndex++;
                blocks[blockIndex] += input[i];
            }
        }
    
        void pointUpdate(int k, int newValue) {
            int block = k / blockSize;
            blocks[block] += newValue - values[k]; 
            values[k] = newValue;
        }
        
        ll rangeSumQuery(int left, int right) {
            ll sum = 0;
         
            while (left < right and (left % blockSize != 0) and left != 0) {
                sum += values[left];
                left++;
            }
            
            while (left + blockSize - 1 <= right) {
                sum += blocks[left / blockSize];
                left += blockSize; 
            }
            
            while (left <= right) {
                sum += values[left];
                left++;
            }
            
            return sum;
        }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
 
    sqrtDecomposition obj(arr);
    int a, b, k, u;
    int type;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> k >> u;
            k--;
            obj.pointUpdate(k, u);
        }
        else {
            cin >> a >> b;
            a--, b--;
            cout << obj.rangeSumQuery(a, b) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}