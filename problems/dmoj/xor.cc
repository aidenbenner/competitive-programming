#include <iostream>

using namespace std;

int main()
{
  int T; 
  cin >> T; 
  while(T--){
    int a,b; 
    cin >> a >> b;

    long long out = 0; 

    int diff = b - a; 

    for(int i = 0; i<32; i++){
      int bitA = (a >> i) & 1;
      int bitB = (b >> i) & 1;

      int num1 = 0;  

      if(!bitA && !bitB){
        num1 = 0; 
      }

      if(bitA && !bitB){
        num1 += (1 << i) - a % (1 << i);
      }

      if(!bitA && bitB){
        num1 += a % (1 << i);
      }

      if(bitA && bitB){
        num1 += a % (1 << i);
        num1 += (1 << i) - a % (1 << i);
      }

      out = out | ((num1 % 2) << i); 
      cout << i << "   " << num1 << "  " << out << endl;
    }
    cout << out << endl;
  }
}
