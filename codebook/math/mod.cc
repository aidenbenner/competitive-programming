#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-13
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b); 
}

int modinv(int a, int m)
{
  int r = (a % m); 
  if(r == 1){ a };
}

int N; 
int main()
{
  cin >> N;




}