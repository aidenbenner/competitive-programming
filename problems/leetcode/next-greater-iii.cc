#include <string>
#include <algorithm>
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = std::to_string(n);
        for (int i = 0; i<s.size(); i++) {
            for (int k = i + 1; k<s.size(); k++) {
                int a = s[s.size() - 1 - i] - '0';
                int b = s[s.size() - 1 - k] - '0';

                if (a > b) {
                    std::swap(s[s.size() - 1 - i], s[s.size() - 1 - k]);
                    return stoi(s.c_str());
                }
            }
        }
        return -1;
    }
};
