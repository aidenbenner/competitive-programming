#include <algorithm>
using namespace std;

class Solution {
public:

    int distributeCandies(vector<int>& candies) {
        int x = candies.size() / 2; 

        map<int, int> mp;
        for(int i = 0; i<candies.size(); i++){
            if(mp.find(candies[i]) == mp.end()){
                mp.insert(make_pair(candies[i], 0)); 
            }
            mp[candies[i]]++; 
        }

        int dist = mp.size(); 

        vector<int> z;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            z.push_back(itr->second);
        }

        for(int i = 0; i<z.size(); i++){
            if(z[i] != 1){
                x -= z[i] - 1; 
            }
            z[i] = 1;
        }
        if(x <= 0){
            return dist;
        }
        return dist - x; 
    }
};
