class Solution {
  public: 
    int gcd(int a, int b){
      return b == 0 ? a : gcd(b, a%b);
    }

    bool canMeasureWater(int x, int y, int z) {
      if(x + y < z) return false; 
      
      if(z == 0) return true;

      if(x == 0 || y == 0){
        if(z == y + x) return true;
        return false;
      }


      


      int denom = gcd(x,y); 
      if(z % denom == 0){
        return true;
      }
      return false;
    }
};
