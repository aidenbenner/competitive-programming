#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std; 

int main()
{
  double eps = 0.000000001; 
  int T; 
  ifstream in("a.in"); 
  ofstream out("a.out"); 
  in >> T; 
  int P, X, Y; 
  for(int i = 1; i<=T; i++){
    in >> P >> X >> Y; 

    int cx = X - 50; 
    int cy = Y - 50; 

    double r = cx * cx + cy * cy; 
    r = sqrt(r); 

    double theta = atan2(cx,cy); 
    double thresh = 2 * M_PI * P / 100.0; 
    if(P == 0){
      thresh = -100; 
    }
    if(P == 100){
      thresh = 1000000; 
    }

    if((theta < thresh + eps && r < 50 + eps)){
      out << "Case #" << i << ": black" << endl; 
      continue;
    }
    out << "Case #" << i << ": white" << endl; 
  }
}
