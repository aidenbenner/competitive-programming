#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define PI 3.141592653579323

#define double long double

struct A {
    double angle;
    long long x;
    long long y;
    int num;
    double mag;
};

bool operator<(const A& a, const A& b) {
    return a.angle < b.angle;
}

int main() {
    int n;
    cin >> n;

    vector<A> angles; 

    int i = 0;
    while(n--) {
        i++;
        int x, y;
        cin >> x >> y;
        A a;
        a.angle = atan2(y,x) + PI;
        a.x = x;
        a.y = y;
        a.num = i;
        a.mag = sqrt(x * x + y * y);
        angles.push_back(a);
    }

    double minAng = 2 * PI;
    int minInd = 0;
    int minIndB = 0;
    sort(angles.begin(), angles.end());
    for (int i = 0; i<=angles.size(); i++) {
        A a = angles[i % angles.size()];
        A b = angles[(i - 1) % angles.size()];
        long long dot = a.x * b.x + a.y * b.y;
        double ang = fabs(acos((double)dot / (a.mag * b.mag)));
        if (ang < minAng) {
            minAng = ang;
            minInd = a.num;
            minIndB = b.num;
        }
    }

    cout << minInd << " " << minIndB << endl;

}
