#include <vector>
#include <iostream>

using namespace std;
int N; 

vector<int> nums; 

int DP[201]; 

int recr(int n, int top, int rem){
  if(n <= 2){
    return 0; 
  }
  if(top >= N){
    top = 0; 
  }
  
  if(n == rem || n == 0){
    return 0;
  }

  int score = nums[top] + nums[n - 2] + nums[n - 3]; 
  rem--; 

  int out = max(out, out + recr(n-1, top, rem)); 
      out = max(out, out + recr(n-2, top, rem));
      out = max(out, out + recr(n-3, top, rem));
  return out;
}


int main()
{
  nums.resize(201); 
  cin >> N; 
  while(N != 0){
    for(int i = 0; i<N; i++)
      cin >> nums[i];
    cout << recr(N, N - 1) << endl;
    cin >> N; 
  }
}
