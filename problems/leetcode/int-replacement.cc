
#include <map>
class Solution {
public:
    int integerReplacement(long n) {
      map<long, long> mp;
      return solve(mp, n); 
    }

    long solve(map<long, long>& DP, long n){
      if(n <= 0) return 1e9+2; 
      if(n == 1) return 0; 
      if(DP.find(n) != DP.end()) return DP[n]; 

      if(n % 2 == 0){
        DP.insert(make_pair(n,1 + solve(DP, n / 2)));
        return DP[n]; 
      }
      else{
        long out = 1 + solve(DP, n + 1); 
        out = min(out, 1 + solve(DP, n - 1));
        DP.insert(make_pair(n,out));
        return DP[n];
      }
    }
};

