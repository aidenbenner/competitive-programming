#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
  set<int> st; 


  int Q; 

  cin >> Q; 
  for(int i = 0; i<Q; i++){
    int type, arg; 
    cin >> type >> arg;


    switch(type){
      case 1: st.insert(arg);break; 
      case 2: st.erase(arg);break; 
      case 3: 
              auto index = st.find(arg);
              if(index != st.end()) cout << "Yes\n"; 
              else cout << "No\n"; 
              break; 
    }
  }




}
