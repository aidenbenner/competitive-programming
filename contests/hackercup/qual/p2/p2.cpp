#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main()
{

  int T; 

  ifstream in("a.in"); 
  ofstream out("a.out"); 

  in >> T; 

  for(int z = 1; z<=T; z++)
  {
    int N;
    in >> N; 
    vector<int> items; 
    for(int i = 0; i<N; i++){
      int k; 
      in >> k; 
      items.push_back(k); 
    }

    sort(items.begin(), items.end()); 

    //we want each trip to be as close to 50 as possible 
    //and we want to take the most amount of trips
    
    int trips = 0; 
    for(int i = items.size() - 1; i>=0; i--)
    {
      //check if ith item is bigger than 50, otherwise grab first too
      bool sent = false; 
      int curr_weight = items[i]; 
      items.erase(items.begin() + i); 
      int first_weight= curr_weight; 
      while(!sent)
      {
        if(curr_weight < 50){
          if(i == 0){
            //if we can't make 50 with what we currently have we send this on the last trip 
            sent = true;
            break; 
          } 
          curr_weight += first_weight; 
          items.erase(items.begin() + 0); 
          i--; 
        }
        else{
          sent = true;
          trips++;
          break; 
        }
      }
    }
    out << "Case #" << z << ":" << " " << trips << endl; 
  }
}
