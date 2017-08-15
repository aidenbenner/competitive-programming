#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;
class Solution {
public:

    int getArea(int A, int B, int C, int D){
      return (D - B) * (C - A);
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

      int cA, cB, cC, cD = 0;
      int Aa = getArea(A,B,C,D); 
      int Ba = getArea(E,F,G,H);
      int total = Aa + Ba;

      if(A <= E){
        // A is leftmost
        if(E <= C){
          cA = E; 
          cB = max(B,F);
          cC = min(C,G);

          if(H <= D){
            // A is highest
            if(B <= H){
              cD = H; 
            }
            else{
              return total;
            }
          }
          else{
            if(F <= D){
              cD = D; 
            }
            else{
              return total;
            }
          }

          return total - getArea(cA,cB,cC,cD);
        }
        return total;
      }
      else{
        return computeArea(E,F,G,H,A,B,C,D);
      }
    }
};


