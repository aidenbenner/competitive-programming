#include <stdio.h>

void swap (int * arr, int a , int b){
  int tmp = arr[b]; 
  arr[b] = arr[a];
  arr[a] = tmp; 
}

void quicksort(int * a, int n){
  if(n <= 1) return;
  int pivot = a[0]; 
  int wall = 0; 
  for(int i = 0; i<n; i++)
  {
    if(a[i] < a[0]) {
      wall++; 
      swap(a,i,wall);
    }
  }
  swap(a,0,wall);
  quicksort(a, wall);
  quicksort(a+wall+1, n-wall-1);
}

int main () 
{
  int a[] = {1,2,-34,23,43,-654,23,43,-56,243,-456,543}; 
  quicksort(a, sizeof(a)/sizeof(a[0]));
  for(int i = 0; i<sizeof(a)/sizeof(a[0]); i++)
    printf("%d ", a[i]);
  printf("\n");
}

