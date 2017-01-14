using namespace std; 
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:


    string get_time(int bits){
      //first 4 bits are hour 

      int hour = bits << (32 - 4); 
      hour = hour >> (32 - 4);
      hour = hour < 0 ? - hour : hour; 

      int minute = bits >> 4; 
      if(hour > 11){
        return ""; 
      }
      if(minute > 59){
        return ""; 
      }

      string minstr = minute < 10 ? "0" + to_string(minute) : to_string(minute);

      return to_string(hour) + ":" + minstr;
    }




    vector<string> permute (int prefix, int n) 
    {
      //use only first 10 bits
      //first 4 bits are hour 

      vector<string> out; 
      if(n == 0){
        string time = get_time(prefix); 
        if(time == "") return out; 

        out.push_back(time); 
        return out;
      }

      for(int i = 0; i<(14); i++){
        if((prefix << i) & 1){
          continue;
        }

        prefix = prefix | (1 << i);

        
        auto out2 = permute(prefix,n-1); 
        for(int k = 0; k<out2.size(); k++){
          out.push_back(out2[k]); 
        }

        prefix =  prefix & (~(1 << i));
      }
      return out; 
    }


    vector<string> readBinaryWatch(int num) {
      auto out = permute(0,num); 
      vector<string> out2; 
      //remove duplicates
      
      unordered_set<string> used; 

      for(int i = 0; i<out.size(); i++){
        auto itr = used.find(out[i]); 
        if(itr == used.end()){
          out2.push_back(out[i]); 
          used.insert(out[i]);
        }
        
      }

      return out2; 

    }
};
