#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {

public:
    int integerBreak(int n) {
      if(n == 2){
        return 1;
      }
      if(n == 1){
        return 1; 
      }

      int cur = 0; 
      for(int i = 2; i<n; i++){
        int num = n / i;
        int rem = n % i;
        cur = max(cur, (int) (pow(num,i-1) * (num + rem))); 

        rem = num + rem;
        while(rem >= 1){
          num += 1;
          rem -= i-1;
          cur = max(cur, (int) (pow(num,i-1) * (rem))); 
        }
      }
      return cur; 
    }
};

