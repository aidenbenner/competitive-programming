#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <assert.h>
#include <vector>
#define INF 1e9

using namespace std;
int M, N;
int *MEMO; 

int *queue ; 
string *names; 

int getMax(int a, int b){
  int max = -INF;
  for(int i = a; i<=b;i++){
    if(queue[i] > max){
      max = queue[i];
    }
  }
  assert(max != -INF);
  return max;
}

int *group_size; 
int sp(int ind){
  if(ind < 0){
    return 0;
  }
  if(MEMO[ind] != INF){
    return MEMO[ind]; 
  }
  if(ind == 0){
    MEMO[ind] = queue[0]; 
    return queue[0]; 
  }

  int minSteps = INF;
  for(int i  = 0; i<M; i++){
    int val = getMax(ind - i, ind) + sp(ind-i-1);
    if(minSteps > val){
      minSteps = val; 
    }
  }
  return MEMO[ind] = minSteps;
}

vector<int> groups; 
void findGroup(int ind){
  if(ind < 0 ){
      return; 
  }
  for(int i = M-1; i>=0; i--){
    int val = getMax(ind - i, ind) + sp(ind-i-1);
  //  printf("ind %d i %d val %d memo %d \n", ind, i, val, MEMO[ind]);
    if(val == MEMO[ind]){
      if(ind - i < 0){
        continue; 
      }
      findGroup(ind - i - 1);
      group_size[ind-i] = i + 1;
      break;
    }
  }
}

int main(){
  scanf("%d %d", &M, &N);
  queue = new int[N];
  names = new string[N];
  MEMO = new int[N];
  group_size = new int[N];


  for(int i = 0; i<N; i++){
    cin >> names[i]; 
    scanf("%d", &queue[i]);
    MEMO[i] = INF;
    group_size[i] = 0;
  }
  printf("Total Time: %d\n", sp(N-1));
  findGroup(N-1);
  int counter = 0; 
  for(int i = 0; i<N; i++){
    int groupS = group_size[i]; 
    for(int k = 0; k<groupS; k++){
      cout << names[i] + " ";
      i++;
    }
    i--;
    printf("\n");
  }
}
