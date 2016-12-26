Class Solution {
  public:
    bool canWinNim(int n) {
      //remove 1 to 3 stones
      
      //base case
      if(n % 4 == 0){
        return false;
      }
      return true;
    }
};
