#include <iostream>
#include <string>

using namespace std;

bool isMonkey(string s){
  if(s.size() == 0){
    return false;
  }



  if(s.size() == 1){
    if(s[0] == 'A'){
      return true;
    }
    return false;
  }

  if(s[0] == 'B'){
    int sind = s.find('S'); 
    if(sind == string::npos) return false; 
    
    int lev = 1; 
    for(int i = 1; i<s.size(); i++){
      if(s[i] == 'B') lev++; 
      if(s[i] == 'S') lev--; 
      if(lev == 0){
        sind = i; 
        break;
      }
    }

    if(!isMonkey(s.substr(1,sind - 1))){
        return false;
    }

    if(s.size() <= sind + 1){
      return true;
    }

    if(s[sind + 1] == 'N'){
      return isMonkey(s.substr(sind + 2,s.size() - (sind + 1)));
    }

  } else if(s[0] == 'A'){
    if(s[1] == 'N'){
      if(s.size() == 2) return false;
      return isMonkey(s.substr(2,s.size() - 2)); 
    }
  }
  return false;
}


int main()
{

  string str;
  cin >> str; 
  while(str != "X"){

    if(isMonkey(str)){
      cout << "YES" << endl;
    } else{
      cout << "NO" << endl;
    }
    cin >> str;
  }
}
