#include <stdio.h>
#include <iostream>

using namespace std; 
int main()
{
  int x; 
  int y;
  cin >> x >> y; 

  int out = x ^ y; 
  int sum = 0; 

  int check = 1; 
  for(int i = 1; i<32; i++){
    if((check & out) != 0) sum = sum + 1; 
    check = 1 << i; 
  }
  cout << sum << endl;
}
