#include <iostream>
using namespace std;
class Solution {
public:
    int f(string &s, int k, int j){
        if(k + j >= s.size()) return 0; 
        if(k - j < 0) return 0; 
        cout << k << endl;
        if(s[k + j] == s[k - j]){
            return 1 + f(s, k, j + 1); 
        }
        return 0; 
    }
    int e(string &s, int k, int j){
        if(k + 1 + j >= s.size()) return 0; 
        if(k - j < 0) return 0; 
        if(s[k + 1 + j] == s[k - j]){
            return 1 + e(s, k, j + 1); 
        }
        return 0; 

    }

    int countSubstrings(string s) {
        int sum = 0; 
        for(int i = 0; i<s.size(); i++){
            sum += f(s, i, 0) + e(s,i,0);
        }
        return sum;
    }
};

