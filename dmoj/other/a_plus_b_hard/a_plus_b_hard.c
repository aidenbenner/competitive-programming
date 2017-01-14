#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define max(a,b) a > b ? a : b 

int char_to_int(char a){
  return a - '0'; 
}

void add_chars(char * a, char * b)
{
  printf("hit");
  int a_len = strlen(a);
  int b_len = strlen(b);
  //need to check if either is negative

  bool aneg = (a[0] == '-'); 
  bool bneg = (b[0] == '-'); 

  int tmp[max(a_len,b_len) + 1]; 
  int tmp_size = max(a_len,b_len) + 1;

  //fill tmp with 0s 
  for(int i = 0; i< max(a_len,b_len) + 1; i++){
    tmp[i] = 0;
  }
  
  if(!(aneg ^ bneg)){
    //add normally
    int start = aneg && bneg;
    for(int i = start; i<a_len; i++){
      int result = char_to_int(a[i]);
      result += char_to_int(b[i]); 

      if(result > 10){
        //need to add digit from left
        int incre = i + 1; 
        while(tmp[incre] >= 10){
          tmp[incre - 1]++; 
          tmp[incre] = tmp[incre] % 10;
          incre--;
        }
      }
      tmp[i+1] = result % 10;
    }
    //print negative of both numbers are neagtive
    if(aneg && bneg){
      printf("-");
    }
    bool leading_zero = true; 

    for(int i = 0; i<tmp_size; i++){
      if(tmp[i] == 0){
        if(leading_zero) continue;
      }
      else{
        leading_zero = false; 
        printf("%d", tmp[i]); 
      }
    }
    printf("\n"); 
  }

  //SUBTRACTION 
  for(int i = 0; i<a_len; i++){

  }
}


int main()
{
  int N;  
  scanf("%d", &N); 
  char * num_1 = malloc(sizeof(char) * 100 ); 
  char * num_2 = malloc(sizeof(char) * 100 ); 

  assert(num_1);
  assert(num_2);

  for(int i = 0; i<N; i++)
  {
    scanf("%s %s", num_1, num_2); 
    printf("%s %s", num_1, num_2);
    add_chars(num_1,num_2); 
  }
}
