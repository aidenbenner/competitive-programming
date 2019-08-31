#include <iostream>
using namespace std;

void eval(int x, int y, int dir, int n) {
    if (n == 0) {
        cout << x << " " << y << endl;
        return;
    }

    if (dir == 0) {
        eval(x, -y + 1, 1, n - 1);
    }
    if (dir == 1) {
        eval((-x + 1), y, 2, n - 1);
    }
    if (dir == 2) {
        eval(x, -y, 3, n - 1);
    }
    if (dir == 3) {
        eval(-x, y, 0, n - 1);
    }
}

int main() {
    eval(0, 0, 0, 2018);
}
