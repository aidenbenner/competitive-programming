

class Solution {
  public:
    vector<string> fizzBuzz(int n) {
      vector<string> out; 
      for(int i = 1; i<=n; i++){
        string next = ""; 
        if(i % 3 == 0)
          next = "Fizz";
        if(i % 5 == 0)
          next += "Buzz";
        if(i % 3 != 0 && i % 5 != 0)
          next = std::to_string(i); 
        out.push_back(next); 
      }
      return out;
    }
};

