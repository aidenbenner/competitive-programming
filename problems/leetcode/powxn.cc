#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, long n) {
      if(n == 1) return x;
      if(n == 0) return 1; 
      if(x == 1) return 1;

      if(n < 0) {
        return 1 / myPow(x, -1 * n);
      }

      if(n % 2 == 1){
        return x * myPow(x, n - 1);
      }
      return myPow(x * x, n / 2);
    }
};

int main(){
  Solution s;
  cout << s.myPow(5,-2) << endl;
}
