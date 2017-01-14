#include <iostream>
#include <unordered_map>
#include <vector>

struct Edge
{
  char end;
  double weight;
};

class Solution {
public:
    double get_shortest_path()
    {
      
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {

      unordered_map<char,vector<Edge> > adjList; 

      for(int i = 0; i<equations.size(); i++)
      {
        Edge e, e2; 
        e.end = equations[i]->second; 
        e2.end = equations[i]->first;
        e.weight = values[i]; 
        e2.weight = values[i]; 
        adjList[equations[i]->first].push_back(e); 
        adjList[equations[i]->second].push_back(e2); 
      }
      
      auto itr = adjList.begin(); 

      while(itr != adjList.end())
      {
        cout << itr->first << " " << itr->second.end << " " <<  itr->second.weight << endl; 
      


        it++; 
      }
      

      for(int i = 0; i<queries; i++)
      {

      }
};
