#include <iostream>
using namespace std;
class Solution {
  public:
    int getSum(int a, int b) {
      int sum = 0; 
      //if a xor b, c = 1 
      //if a && b  c << 1 = 1
      for(int i = 0; i<32; i++){
        int bit = 1 << i; 
        int sum_bit = sum & bit; 
        int a_bit = a & bit; 
        int b_bit = b & bit; 

        if(!a_bit && !b_bit) {
          continue;

        }

        if(sum_bit){
          if(a_bit || b_bit){
            int count = 1; 
            while(sum >> (i + count) & 1){
              count++; 
            }
            //if i == 31 throw away result
            if(i != 31) {
              sum = sum | (1 << (i + count));  
            }
          }
          if (a_bit && b_bit){

          }
          else {
            sum = sum & (~bit);
          }
        }
        else{
          if(a_bit && b_bit){
            int count = 1; 
            while(sum >> (i + count) & 1){
              count++; 
            }
            sum = sum | (1 << (i + count));  
          }
          else if(a_bit || b_bit){
            sum = sum | bit;
          }
        }
      }
      return sum;
    }
};

int main(){
  Solution * s = new Solution;
  cout << s->getSum(1,-1); 
}
