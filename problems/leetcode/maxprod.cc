#define INF 1e9 
#include <map>
class Solution {
public:

    const int lim  = 1e8;
    vector<int> gdp;
    vector<int> fdp;

    int f(vector<int>& a, int k){
        if(fdp[k] != -INF) return fdp[k]; 
        if(k >= a.size()) return 0; 
        if(k + 1 == a.size()) return a[k];
        return fdp[k] = max(a[k],  max(a[k] * f(a, k+1), a[k] * g(a, k+1))); 
    }
    int g(vector<int>& a, int k){
        if(gdp[k] != -INF) return gdp[k]; 
        if(k >= a.size()) return 0; 
        if(k + 1 == a.size()) return a[k];
        return gdp[k] = min(a[k],  min(a[k] * g(a, k+1), a[k] * f(a, k+1))); 
    }
    int maxProduct(vector<int>& nums) {
        gdp.empty();
        fdp.empty(); 
        gdp.resize(nums.size());
        fdp.resize(nums.size());
        for(int i = 0; i<nums.size(); i++){
            gdp[i] = -INF; 
            fdp[i] = -INF; 
        }

        int maxp = -INF;
        for(int i = 0; i<nums.size(); i++){
            maxp = max(f(nums, i), maxp); 
        }
        return maxp;
    }
};
