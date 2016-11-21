#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int b, int c)
{
  int tmp = a[c]; 
  a[c] = a[b];
  a[b] = tmp;
}


void mergesort (int * a, int * tmp, int n)
{
  if(n <= 1 ) return; 
  mergesort(a,     tmp, n/2);
  mergesort(a+n/2, tmp,n - n/2);

  int u = 0;
  int l = n/2;
  int i = 0;
  for(i = 0; u<n/2 && l < n; i++)
  {
    if(a[u] < a[l]){
       tmp[i] = a[u];
       u++; 
    }
    else{
      tmp[i] = a[l];
      l++; 
    }
  }
  while(u < n/2){
     tmp[i] = a[u];
     u++; 
     i++; 
  }
  while(l < n){
     tmp[i] = a[l];
     l++; 
     i++; 
  }

  for(int i = 0; i<n; i++){
    a[i] = tmp[i];
  }
}


void sort (int * a, int n)
{
  int * tmp = malloc(sizeof(int) * n);
  mergesort(a,tmp,n);
  free(tmp);
}


int main ()
{
  int arr[] = {-23,43,54,34591,-45,-546,54,9,32,-543,65};
  sort(arr, sizeof(arr)/sizeof(arr[0]));
  for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
    printf("%d ", arr[i]); 
  printf("\n");
}
