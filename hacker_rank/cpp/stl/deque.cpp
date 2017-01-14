#include <iostream>
#include <deque> 
using namespace std;
void printKMax(int arr[], int n, int k){
  //Write your code here.
  deque<int> dq; 
  
  int max = -1e9; 
  for(int i = 0; i<n; i++){
    dq.push_front(arr[i]); 
    if(arr[i] > max){
      max = arr[i]; 
    }

    if(dq.size() >= k){
      if(arr[i - k] == max){
        //search dq for new max
        max = -1e9; 
        for(int j = 0; j < k; j++){
          if(arr[i - k + j + 1] > max)
            max = arr[i - k + j + 1]; 
        }
      }
      dq.pop_back(); 
      cout << max << " "; 
    }
  }
  cout << endl; 
}
int main(){

  int t;
  cin >> t;
  while(t>0) {
    int n,k;
    cin >> n >> k;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}
