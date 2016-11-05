#include <cstdio>
#include <list>


using namespace std;
int main(void){
    int n; 
    scanf("%d", &n); 

    list<double> streams; 
    
    for(int i = 0; i<n; i++){
        int a; 
        scanf("%d", &a);
        streams.push_back(a);
    }

    int action = 0; 
    scanf("%d", &action);
    while(action != 77){
        if(action == 99){
            int num, percent;
            scanf("%d %d", &num, &percent);
            double newFlow = streams.; 
        }
        else if(action == 66){

        }
        scanf("%d", &action);
    }
}
