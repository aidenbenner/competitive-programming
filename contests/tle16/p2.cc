
#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define INF 1e9
#define EPS 1e-14
#define pb push_back
#define PI 3.14159265359 

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 
int main()
{
  double x,y;

  cin >> x >> y;
  double x2,y2;
  cin >> x2 >> y2;

  double angle = PI / 4; 

  double area = (y + x * tan(1))/2.0; 
  double area2 = (y2 + x2 * tan(1))/2.0; 
  area = max(area, area2);

  printf("%.9lf", area); 
}
