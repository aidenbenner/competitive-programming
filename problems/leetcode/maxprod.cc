#define INF 1e9 
class Solution {
public:
    int f(vector<int>& a, int k){
        if(k >= a.size()) return 0; 
        return max(a[k],  a[k] * f(a, k+1)); 
    }
    int maxProduct(vector<int>& nums) {
        int maxp = -INF;
        for(int i = 0; i<nums.size(); i++){
            maxp = max(f(nums, i), maxp); 
        }
        return maxp;
    }
};
