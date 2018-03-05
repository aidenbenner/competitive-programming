#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string> 

using namespace std;

const int MAX_MOD = 100007;
int hashc(char s, int old) {
    return ((int)s + old * 256) % MAX_MOD;
}

int hashstr(string s) {
    int old = 0;
    for(int i = 0; i<s.size(); i++){
        old = hashc(s[i], old);
    }
    return old;
}

int rabinKarp(string& source, vector<string> pats) {
    string mp[MAX_MOD];
    std::fill(mp, mp + MAX_MOD, ""); 
    for(int i = 0; i<pats.size(); i++){
        mp[hashstr(pats[i])] = pats[i];
    }

    for(int i = 0; i<source.size(); i++){
        int hs = 0;
        for(int k = i; k<source.size(); k++){
            hs = hashc(source[k], hs);
            if(mp[hs] != ""){
                string z = source.substr(i, k - i + 1);
                if(z == mp[hs])
                    return i;
            }
        }
    }
    return -1; 
}

int n;
int main()
{
    string a,b;
    cin >> a >> b;
    vector<string> s; 
    s.push_back(b);
    cout << rabinKarp(a, s) << endl;
}
