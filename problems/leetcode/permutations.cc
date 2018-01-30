#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        out.push_back(nums); 
        while(next_permutation(nums.begin(), nums.end())){
            out.push_back(nums); 
        }
        return out;*/

        vector<vector<int>> out;
        if(nums.size() == 0) {
            return out;
        }
        if(nums.size() == 1) {
            out.push_back(nums);
            return out;
        }

        for(int i = 0; i<nums.size(); i++){
            vector<int> next;
            for(int j = 0; j<nums.size(); j++){
                if(j == i) continue;
                next.push_back(nums[j]); 
            }
            auto tmp = permute(next);
            for(int k = 0; k<tmp.size(); k++){
                tmp[k].push_back(nums[i]);
                out.push_back(tmp[k]);
            }
        }
        return out;
    }
};
