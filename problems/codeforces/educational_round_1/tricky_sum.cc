#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;

        long long sum = (n + 1) * n / 2;
        long p = floor(log2(n)) + 1;

        p = pow(2, p) - 1;
        p *= 2;

        sum -= p;
        cout << sum << endl;
    }
}
