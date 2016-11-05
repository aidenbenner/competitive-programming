#include <cstdio>
#include <vector>

using namespace std;
int main(){
    int n; 
    scanf("%d", &n);

    vector<int> marks(n);

    double total = 0;
    for(int i = 0; i<n; i++){
        int r; 
        scanf("%d", &r);
        total += r;
    }

    int totNums = n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int r; 
        scanf("%d", &r);
        total += r;
        totNums++;
        printf("%0.03lf\n", total/totNums);
    }
    
}
