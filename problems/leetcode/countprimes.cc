#include <vector>

class Solution {
public:
    int countPrimes(int n) {
      if(n == 0){
        return 0; 
      }
      if(n == 1){
        return 0; 
      }
      if(n == 2){
        return 0;
      }
      if(n == 3){
        return 1;
      }
      int * sieve = new int[n + 1]; 
      for(int i = 0; i<=n; i++){
        sieve[i] = 1; 
      }


    
      sieve[0] = 0;
      sieve[1] = 0;
      sieve[2] = 1; 
      sieve[3] = 1;
      for(int i = 2; i<=n/2 + 1; i++){
        for(int k = 2 * i; k<n; k += i){
          sieve[k] = 0; 
        }
      }

      int count = 0; 
      for(int i = 0; i<n; i++){
        if(sieve[i] == 1){
          count++; 
        }
      }
      delete sieve;
      return count;
    }
};
