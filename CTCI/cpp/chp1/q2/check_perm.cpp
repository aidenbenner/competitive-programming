#include <iostream>
#include <unordered_map>

using namespace std;


bool isPermute(string a, string b)
{
  if(a.size() != b.size()){
    return false;
  }

  //they must have all the same characters + amounts
  int check[26]; 

  for(int i = 0; i<26; i++){
    check[i] = 0; 
  }


  for(int i = 0; i<a.length(); i++){
    check[a[i] - 'a']++;
    check[b[i] - 'a']--; 
  }

  for(int i = 0; i<26; i++){
    if(check[i] != 0){
      return false; 
    }
  }
  return true;
}



int main()
{
  cout << isPermute("aaaaa","aaaaa"); 
  cout << endl;
  cout << isPermute("cat","tac"); 
  cout << endl;
  cout << isPermute("the quick brown fox jumps","jumps the brown fox quick"); 
  cout << endl;
  cout << isPermute("abcdef","fed"); 
  cout << endl;
  cout << isPermute("aaa","aba"); 
  cout << endl;
  cout << isPermute("aca","caa"); 
  cout << endl;
  

}
