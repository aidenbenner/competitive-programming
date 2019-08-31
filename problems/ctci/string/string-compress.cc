#include <string>
#include <iostream>

using namespace std;

string compress(string s) {
    if (s.size() <= 1) return s;

    char curr = s[0];
    int count = 1;

    string out;
    out.reserve(s.size());

    for (int i = 1; i<s.size(); i++) {
        if (curr != s[i]) {
            out.push_back(curr);
            out += to_string(count);
            count = 1;
            curr = s[i];
        }
        else {
            count++;
        }
    }
    out.push_back(curr);
    out += to_string(count);

    if (out.size() < s.size())
        return out;
    return s;
}


int main() {
    cout << compress("aabcccccaaa") << endl;

}
