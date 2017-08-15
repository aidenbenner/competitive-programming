
/*
 * A* Path Finding Algorithm 
 * Djkstra is a greedy algorithm, will find a solution but it finds it by exploring the shortest path currently availible
 * Djkstra is also dumb when it comes to uniform graphs (uniform grids)j k
 * A* is a small extension to djkstra that makes edge selection smarter
 * New heuristic is 'how far do we have to go'
 * This can be the euclidean distance  
 * The new edge seleciton at each step is distance from start + euclidean distance to end
 */

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef vector<vector<int>> AdjList;

struct Point {
  double x;
  double y;

  Point(double x, double y){
    this->x = x;
    this->y = y;
  }

  double getDist(Point& b){
    double dx = b.x - this->x;
    double dy = b.y - this->y;
    return sqrt(dx * dx + dy * dy);
  }

};

vector<Point> points;
AdjList adjList;
int astar(int start, int end){

  bool visited[points.size()]; 
  fill(visited, visited + points.size(), false);

  priority_queue<int> pq;



}


int main() {

  int N;
  cin >> N;


  for(int i = 0; i<N; i++){
    double x, y;
    cin >> x >> y;

    points.push_back(Point(x,y));
    
    adjList.push_back(vector<int>());
  }

  int M;
  cin >> M;

  for(int i = 0; i<M; i++){
    int a,b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
}

