#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <locale>
#include <cmath>

#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cmap[26];
        fill(cmap, cmap + 26, 0); 
        for(int i = 0; i<licensePlate.size(); i++){
            if(isalpha(licensePlate[i])){
                licensePlate[i] = tolower(licensePlate[i]);
                cmap[licensePlate[i] - 'a']++; 
            }
        }

        int m = INF;
        string out = "";
        for(int i = 0; i<words.size(); i++){
            bool good = true;
            int tmp[26];
            for(int k = 0; k<26; k++){
                tmp[k] = cmap[k];
            }
            for(int k = 0; k<words[i].size(); k++){
                tmp[words[i][k] - 'a']--; 
            }
            for(int k = 0; k<26; k++){
                if(tmp[k] > 0) good = false;
            }
            

            if(good){
                if(words[i].size() < m){
                    m = words[i].size(); 
                    out = words[i];
                }
            }
        }
        return out;
    }
};

int main(){
    Solution s;
    vector<string> v;
    v.push_back("test"); 
    cout << s.shortestCompletingWord("test", v) << endl;
}
