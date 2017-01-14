#include <string>
#include <iostream>

using namespace std;


void permute(string prefix, string s)
{
  if(s == ""){
    cout << prefix << endl; 
  }
  for(int i = 0; i<s.length(); i++){
    char c = s[i]; 
    string next = s; 
    next.erase(i,1); 
    permute(prefix + c, next); 
  }
}

int main()
{
  permute("", "abcd"); 



}
