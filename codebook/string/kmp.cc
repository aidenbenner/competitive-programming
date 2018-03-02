#include <string>
#include <cassert>
#include <iostream>
using namespace std;

// returns first index of sub in a or -1
int kmp(string a, string sub){
    // preprocess sub
    // lps[i] is the longest prefix from 0..i that is also a suffix from 0..i
    int lps[sub.size()];

    lps[0] = 0;
    for(int i = 1; i<sub.size(); i++){
        if(sub[i] == sub[0]) {
            lps[i] = lps[i - 1] + 1;
        }
        else lps[i] = 0;
    }

    int i = 0;
    int j = 0;
    while(i < a.size()){
        if(j == sub.size()) {
            return (i - 1) - sub.size() + 1;
        }
        if(sub[j] == a[i]){
            j++;
            i++;
        }
        else {
            if(j == 0) {
                i++;
                continue;
            }
            j = lps[j - 1];
        }
    }
    if(j == sub.size()) {
        return (i - 1) - sub.size() + 1;
    }
    return -1;
}


int main() {
    string a,b;
    cin >> a >> b;
    cout << kmp(a, b) << endl;
    //assert(kmp("baaaaa", "aa") == 1);
    //assert(kmp("aabbaaccaa", "aaccaa") == 4);
    //assert(kmp("test", "t") == 0);
    //assert(kmp("test", "test") == 0);
}
