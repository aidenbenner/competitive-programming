#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int main()
{    
  int N;
  scanf("%d", &N);
  int out = 0; 

  char quest[N];

  for(int i = 0; i<N; i++){
    scanf("%c", &quest[i]);
  }

  char c;
  for(int i = 0; i<N; i++){
    scanf("%c", &c);
    if(quest[i] == c){
      out++; 
    }
  }
  printf("%d", out); 
}
