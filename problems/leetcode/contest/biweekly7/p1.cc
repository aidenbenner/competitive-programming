#include <cmath>
#include <string>
using namespace std;

class Solution {
    public:
        int calculateTime(string keyboard, string word) {
            int currLetterInd = 0;
            int cost = 0;
            for(int i = 0; i<word.length(); i++) {
                char letter = word[i];
                // find letter in keyboard
                for (int k = 0; k<keyboard.length(); k++) {
                    if (keyboard[k] == letter) {
                        cost += abs(k - currLetterInd);
                        currLetterInd = k;
                        break;
                    }
                }
            }
            return cost;
        }
};
