#include <string>
#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;
int main()
{
  int N;
  cin >> N;

  string line; 
      getline(cin, line); 
  for(int i = 0; i<N; i++){

    string syl[4]; 
    for(int k = 0; k<4; k++){
      getline(cin, line); 

      int sylInd = 0; 
      for(int j = line.size() - 1; j>=0; j--){
        line[j] = tolower(line[j]);
        if(line[j] == 'a' 
            || line[j] == 'e'
            || line[j] == 'i'
            || line[j] == 'o'
            || line[j] == 'u'
            || line[j] == ' '){
          sylInd = j;
          break;
        }
      }
      syl[k] = line.substr(sylInd, line.size() - sylInd); 
    }


    if(syl[0] == syl[1] && syl[1] == syl[2] && syl[2] == syl[3]){
      cout << "perfect" << endl; 
    }
    else if(syl[0] == syl[1] && syl[2] == syl[3]){
      cout << "even" << endl; 
    }
    else if(syl[0] == syl[2] && syl[1] == syl[3]){
      cout << "cross" << endl; 
    }
    else if(syl[0] == syl[3] && syl[1] == syl[2]){
      cout << "shell" << endl; 
    }
    else{
      cout << "free" << endl;
    }
      
  }
}
