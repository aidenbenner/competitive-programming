#include<string>
class Solution {
public:
    //() left, () right, contain
    vector<string> k(int j, int n) {
        vector<string> out; 
        if(n == 0) {
            out.push_back(""); 
            return out;
        }
        if(n == 2) {
            out.push_back("()"); 
            return out;
        }

        set<string>  mp;
        string s = ""; 
        for(int i = 0; i<=n - 2; i += 2){
            auto a = k(0, n - 2 - i);
            auto b = k(0, i);
            for(int k = 0; k<a.size(); k++){
                for(int j = 0; j<b.size(); j++){
                    mp.insert(a[k] + "()" + b[j]);
                }
            }
            a = k(0, n - 2);
            for(int k = 0; k<a.size(); k++)
                mp.insert(s + "(" + a[k] + ")");
        }

        vector<string> next; 
        for(auto itr = mp.begin(); itr!=mp.end(); itr++){
            next.push_back(*itr); 
        }
        return next; 
    }

    vector<string> generateParenthesis(int n) {
        n *= 2;
        if(n & 1 || n == 0) return vector<string>(); 

        vector<string> tmp;
        tmp = k(0, n); 
        return tmp;
    }
};


// ( A ) 
// A -> ( A ) 
// () -> A
// A -> AA
