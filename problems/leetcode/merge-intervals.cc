/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:

    struct itr {
      int start;
      int end;

      bool operator< (itr const& b){
        return this->start < b.start;
      }
    
      itr() {

      }

      itr(int s, int e){
        this->start = s;
        this->end = e; 
      }
    };

    itr merge(itr const& a, itr const& b){
      itr out;
      out.start = min(a.start, b.start); 
      out.end = max(a.end, b.end); 
      return out;
    }

    bool canMerge(itr const& a, itr const& b){
      return a.start <= b.start && b.start <= a.end; 
    }

    vector<Interval> merge(vector<Interval>& intervals) {
      if(intervals.size() <= 1) return intervals;
      vector<itr> itrs;
      for(int i = 0; i<intervals.size(); i++){
        itrs.push_back(itr(intervals[i].start, intervals[i].end));
      }

      sort(itrs.begin(), itrs.end()); 

      vector<Interval> out;
      vector<itr> preout;

      preout.push_back(itrs[0]);
      for(int i = 0; i<intervals.size(); i++){
        if(canMerge(preout.back(), itrs[i])){
          preout[preout.size() - 1] = merge(preout[preout.size() - 1], itrs[i]);
        }
        else{
          preout.push_back(itrs[i]); 
        }
      }

      for(int i =0 ; i<preout.size(); i++){
        out.push_back(Interval(preout[i].start, preout[i].end));
      }

      return out;
    }
};
