#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using std::string;

class Solution {
public:
    string compress(const string& s) {
        static std::map<string, string> memo;
        if (memo.count(s)) {
            return memo[s];
        }

        std::map<char, char> letMap;
        char curr = 'a';

        string cpr_str;
        cpr_str.reserve(s.length());
        char last = '0';
        for (int i = 0; i<s.length(); i++) {
            if (s[i] != last) {
                if (!letMap.count(s[i])) {
                    letMap[s[i]] = curr;
                    curr++;
                }
                cpr_str.push_back(letMap[s[i]]);
                last = s[i];
            }
        }
        return memo[s] = cpr_str;
    }

    int strangePrinter(string s) {
        std::map<string, int> memo;
        return f(compress(s), memo);
    }

    int f(const string &s, std::map<string, int> &memo) {
        // find all possible last moves
        // means convert all to one of the neighbours
        // equiv to removing it.
        if (s == "") { return 0; }
        if (memo.count(s)) return memo[s];
        string curr = s;
        curr.pop_back();

        int removeInd = s.length() - 1;
        int bestCost = 1 + f(compress(curr), memo);
        while (removeInd > 0) {
            curr[removeInd - 1] = s[removeInd];
            bestCost = std::min(1 + f(compress(curr), memo), bestCost);
            removeInd--;
        }

        return memo[s] = bestCost;
    }
};


int main() {
    Solution s;
    std::cout << s.strangePrinter("abcdefghijmnopqrstuvwxyzabcdefghijmnopqrstuvwxyz") << std::endl;
}
