#include <iostream>
#include <unordered_set>


using namespace std; 
int main()
{
  //determine if strings have all unique characters
  unordered_set<char>  check;  

  string s;
  cin >> s; 

  for(int i = 0; i<s.length(); i++){
    auto itr = check.find(s[i]); 
    if(itr != check.end()){
      cout << "Not unique" << endl; 
    }
    check.insert(s[i]); 
  }
  //cout << "unique" << endl;
  
  


  //xor magic method
  //32 bit intereger
  unsigned int checker = 0; 
  //only 26 characters

  cout << "XOR" << endl; 
  for(int i = 0; i<s.length(); i++){
    int value = s[i] - 'a'; 

    //check if 
    if((checker & (1 << value)) != 0){
      cout << "not unqiue" << endl; 
    }
    //toggles valueth bit
    checker |= (1 << value); 

  }

}


