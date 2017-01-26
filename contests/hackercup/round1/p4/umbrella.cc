#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define MOD 100000007
using namespace std;

int Rad[2001]; 

long long choose(long long n, long long spaces){
  if(n == 0){
    return 1; 
  }
  long long total = 1; 
  while(n > spaces){
    total *= n; 
    total %= MOD; 
    n = n - 1; 
  }
  return total; 
}

int main()
{
  int T; 
  cin >> T;
  for(int test = 1; test <=T; test++){
    int N, M, R; 
    cin >> N >> M; 
    memset(Rad,0,sizeof(Rad));

    long long sum = 0; 
    for(int i = 0; i<N; i++){
      cin >> Rad[i];
      sum += Rad[i] * 2; 
    }

    if(N == 1){
      printf("Case #%d: %d\n", test, M); 
      continue;
    }

    long long total = 0; 
    sort(Rad, Rad + N); 

    //sketch to set it = to N but rad[N] should be 0
    for(int z = 0; z < M; z++){
      
      for(int i = 0; i<=N; ++i){
        for(int k = 0; k<=N; k++){
          if(i == k && !(i == N && k == N)){
            continue;
          }
          int end_spaces = (k == N) + (i == N); 
          long long curr_sum = sum - Rad[i] - Rad[k]; 
          long long empty_spaces = M - 1 - curr_sum; 
          if(empty_spaces < 0)
            continue;
          long long items = empty_spaces + N - 2 ; 
          total += choose(items,empty_spaces); //ways to arrange items in 
          total %= MOD; 
          //add case where we move the edges in 

          //move both sides in 
        }
      }
      M--; 
    }

    printf("Case #%d: ", test); 
    cout << total << endl;
  }
}


