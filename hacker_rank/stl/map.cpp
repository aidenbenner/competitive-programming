#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main() {
  map<string,int> mp; 
  int Q; 
  cin >> Q; 

  for(int i = 0; i<Q; i++){
    int type; 
    string name; 
    cin >> type; 
    cin >> name;
    switch(type){
      case 1: {int grade;
              cin >> grade;
              auto itr2 = mp.find(name); 
              if(itr2 == mp.end()){
                mp.insert(make_pair(name,grade)); 
              }
              else itr2->second += grade; 
              break;}
      case 2: mp.erase(name);
              break;
      case 3:
              auto itr = mp.find(name);
              if(itr == mp.end()) cout << "0" << endl;
              else{
                cout << itr->second << endl;
              }
              break;
    }

  }

}

