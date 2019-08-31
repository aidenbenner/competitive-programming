#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

bool checkRep(string a, string b) {
    int errcount = 0;
    for (int i = 0; i<a.size(); i++) {
        if (a[i] != b[i]) {
            errcount++;   
            if (errcount > 1) return false;
        }
    }
    return true;
}

bool checkAdd(string a, string b) {
    if (a.size() < b.size())
        return checkAdd(b,a);
    int err = 0;
    for (int i  = 0; i<b.size(); i++) {
        if (a[i + err] != b[i]) {
            if (err >= 1) return false;
            err = 1;
        }
    }
    return true;
}

bool solve(string a, string b) {
    if (a.size() == b.size())
        return checkRep(a,b);
    if (abs((int)a.size() - (int)b.size()) == 1)
        return checkAdd(a,b);
    return false;
}

int main() {
    assert(solve("a",""));
    assert(solve("bbb","bbbb"));
    assert(solve("abc","acbc"));
    assert(solve("abc","abbc"));
    assert(solve("abc","adc"));
    assert(!solve("zbc","pdc"));
}
