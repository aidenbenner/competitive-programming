#include<string>
://leetcode.com/problems/course-schedule/ include<string>
#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
class Solution {
  public:
    long nextGreaterElement(long n) {
      string str = to_string(n);

      for(int i = str.length() - 1; i>=0; i--){
        int minb = 1e9;
        int swpInd = -1; 
        for(int k = i + 1; k<str.length(); k++){

          int a = ((int)str[i] - '0');
          int b = ((int)str[k] - '0');

          if(b > a){
            if(b < minb){
              minb = b;
              swpInd = k;
            }
          }
        }
        if(swpInd != -1){

          char tmp = str[i];
          str[i] = str[swpInd];
          str[swpInd] = tmp;

          sort(str.begin() + i + 1, str.end());

          long out; 
          sscanf(str.c_str(), "%ld", &out);
          if(out > INT_MAX){
            return -1; 
          }
          return out;
        }
      }
      return -1; 
    }
};
