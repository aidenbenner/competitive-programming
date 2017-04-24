#include <iostream>
using namespace std;

const int DIS_SET_SIZE = 100005;
int disp[DIS_SET_SIZE];
int disr[DIS_SET_SIZE];


int ds_create(int x){
  disp[x] = x; 
  disr[x] = 0; 
}

int ds_find(int x) {
  if(x != disp[x]) return ds_find(disp[x]); 
  return x; 
}

int ds_merge(int x, int y){
  x = ds_find(x);
  y = ds_find(y); 

  if(disr[x] > disr[y]){
    disp[y] = x; 
  }
  else{
    disp[x] = y; 
  }
  if(disr[x] == disr[y])
    disr[y] = disr[y] + 1;
}

int main(){
  ds_create(5); 
  ds_create(0); 
  ds_create(1); 
  ds_create(2); 
  ds_create(3); 
  ds_create(4); 

  cout << ds_find(0) << endl;
  cout << ds_find(1) << endl;
  cout << ds_find(2) << endl;
  cout << ds_find(3) << endl;
  cout << ds_find(4) << endl;
  cout << ds_find(5) << endl;

  cout << ds_find(0) << endl;
  ds_merge(5,0); 
  cout << ds_find(0) << endl;
  cout << ds_find(5) << endl;
  ds_merge(3,0); 
  cout << ds_find(3) << endl;
  cout << ds_find(0) << endl;
  ds_merge(4,0); 
  cout << ds_find(3) << endl;
  cout << ds_find(4) << endl;

  cout << ds_find(0) << endl;
  cout << ds_find(1) << endl;
  cout << ds_find(2) << endl;
  cout << ds_find(3) << endl;
  cout << ds_find(4) << endl;
  cout << ds_find(5) << endl;
  
}
