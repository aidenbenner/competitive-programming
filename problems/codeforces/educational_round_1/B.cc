#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while(n--) {
        int l, r, k;
        cin >> l >> r >> k;
        l -= 1;
        r -= 1;
        int diff = r - l;

        string cp;
        for (int i = 0; i <= diff; i++) {
            cp += s[l + i];
        }

        k %= (diff + 1);
        for (int i = 0; i <= diff; i++) {
            s[l + i] = cp[((i - k + (diff + 1)) % (diff + 1))];
        }
    }
    cout << s << endl;
}
