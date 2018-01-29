#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        left.resize(nums.size()); 
        right.resize(nums.size()); 

        left[0] = nums[0]; 
        for(int i = 1; i<nums.size(); i++){
            left[i] = nums[i] * left[i - 1]; 
        }

        right[nums.size() - 1] = nums[nums.size() - 1]; 
        for(int i = 1; i<nums.size(); i++){
            int ind = nums.size() - 1 - i; 
            right[ind] = nums[ind] * right[ind + 1]; 
        }


        vector<int> out;
        for(int i = 0; i<nums.size(); i++){
            if(i - 1 < 0) {
                out.push_back(right[i + 1]); 
            }
            else if(i + 1 >= nums.size()) {
                out.push_back(left[i - 1]); 
            }
            else {
                out.push_back(right[i + 1] * left[i - 1]); 
            }
        }
        return out;
    }
};

int main() {
    Solution s;
    vector<int> x;
    x.push_back(1);
    x.push_back(0);
    auto out = s.productExceptSelf(x);

    for(int i = 0; i<out.size() ;i++){
        cout << out[i] << endl;
    }

}
