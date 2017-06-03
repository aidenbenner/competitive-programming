#include <cstdio>
#include <vector>
#include <iostream>
#include <list> 

typedef std::vector<std::vector<int>> AdjList;  
typedef std::list<int> IList; 
typedef std::vector<int> IVector; 

bool findCycles(AdjList graph){
    bool visited[graph.size()];
    for(int i = 0; i<graph.size(); i++){
        visited[i] = false;
    }
    //get random starting point  
    // start point is any unvisited node
    
    bool unvisitedExists = false;
    while(unvisitedExists){
        //start from all the unvisited nodes  
        int curr = 0; 
        unvisitedExists = false; 
        for(int k = 0; k<graph.size(); k++){
            if(visited[k]){
                visited[k] = true;
                curr = k;
                unvisitedExists = true; 
            }
        }
        if(!unvisitedExists){
            break; 
        }

        std::vector<int> frontier(graph[curr]);
        do{
            IVector next; 
            for(IVector::iterator it = frontier.begin(); it != frontier.end(); it++){
                if(visited[*it]){
                    //cycle 
                    return true; 
                }
                else{
                    visited[*it] = true;
                }
                //copy to end of next
                std::copy( graph[*it].begin(), graph[*it].end(), back_inserter(next) ); 

            }
            frontier = next;
        }while(frontier.size() > 0);
    }
    return 0;
}


int main(void){
    int n,  m;
    scanf("%d %d", &n, &m);
    std::vector<std::vector<int>> adjList (n, std::vector<int>(0,1));  

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
    }
}
