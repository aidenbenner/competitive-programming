#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
  public:
    vector< vector<string> > recr(string beginWord, string endWord, unordered_set<string> & dict)
    {
      vector<vector<string> > outList; 

      cout << beginWord << " " << endWord << endl; 
      if(beginWord == endWord){
        vector<string> temp;
        temp.push_back(endWord); 
        outList.push_back(temp); 
        return outList;
      }

      auto itr = dict.find(beginWord); 
      if(itr == dict.end()){
        return outList; 
      }

      for(int i = 0; i<beginWord.size(); i++){
        //try every possible letter change
        if(beginWord[i] != endWord[i]){
          //add all comibinations of this word

          char tmp = beginWord[i]; 
          beginWord[i] = endWord[i];
          auto outVec = recr(beginWord, endWord, dict); 

          cout << "ASDDD" << outVec.size() << "  " << beginWord << endl; 

          //create a vector for each new 
          for(int k = 0; k<outVec.size(); k++){
            vector<string>  temp;
            temp.push_back(beginWord); 



            temp.insert(temp.end(), outVec[k].begin(), outVec[k].end()); 
            outList.push_back(temp);  
          }
          beginWord[i] = tmp;
        }
      }
      return outList;
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict; 
      dict.insert(beginWord); 
      for(int i = 0; i<wordList.size(); i++){
        dict.insert(wordList[i]); 
      }
      return recr(beginWord, endWord, dict); 
    }
};

int main()
{

  vector<string> wordList; 
  wordList.push_back("hot"); 
  wordList.push_back("dot"); 
  wordList.push_back("dog"); 
  wordList.push_back("lot"); 
  wordList.push_back("log"); 
  wordList.push_back("cog"); 

  Solution s; 

  auto vec = s.findLadders("hit", "cog", wordList); 
  for(int i = 0; i<vec.size(); i++){
    for(int k = 0; k<vec[i].size(); k++){
      cout << vec[i][k] << " "; 
    }
    cout << endl;
  }
}
