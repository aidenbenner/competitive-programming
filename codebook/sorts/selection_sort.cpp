#include <cstdio>

void selectionSort(int * arr, int n){
  for(int i = 0; i<n; i++){
    int min = i; 
    for(int k = i; k<n; k++){
      if(arr[k] < arr[min]){
        min = k;
      }
    }
    //swp
    int tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }
}

void printArr(int * arr, int n){
  for(int i = 0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int arr[] = {1,2,1,-4,7,3-23,6,32,753,123,65};
  selectionSort(arr, sizeof(arr)/sizeof(arr[0]));
  printArr(arr, sizeof(arr)/sizeof(arr[0]));
}
