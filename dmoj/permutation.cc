#include <string>
#include <iostream>

using namespace std;

void permute(string base, string prefix)
{
  if(base.size() == 0){
    cout << prefix << endl;
    return; 
  }
  for(int i = 0; i<base.size(); i++){
    permute(base.substr(0,i) + base.substr(i + 1, base.size()), prefix + base[i]);  
  }
}

int main()
{
  permute("abc", "");
}
