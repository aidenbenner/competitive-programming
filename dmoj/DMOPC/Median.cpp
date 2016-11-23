#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
int main(){
   int n;
   scanf("%d", &n);
   vector<int> marks(n); 
   for(int i = 0; i<n; i++){
       scanf("%d", &marks[i]);
   }
   sort(marks.begin(), marks.end());
   double roundedVal;
   if(n % 2 == 0){
        roundedVal = marks[n/2] + marks[n/2 - 1];     
        roundedVal /= 2;
   }
   else{
        roundedVal = marks[n/2];
   }
   printf("%ld\n", (long)round(roundedVal));
}
