#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main(){
    int low, up;
    scanf("%d %d", &low, &up);
    int sum = 0; 
    for(int i = low; i <= up; i++){
        string in; 
        in = to_string(i);  

        bool print = true; 
        for(int k = 0; k < in.length(); k++){
            if( in[k] == '8' || in[k] == '0' || in[k] == '1'){
                if( in[(in.length() - 1 - k)] == in[k] ){
                    continue;
                }
                else{
                    print = false;
                    break;
                }
            }
            else if( in[k] == '6' || in[k] == '9'){
                //check if in last half of string
                if( in[k] == '6'){
                    if( in[(in.length() - 1 -  k)] == '9' ){
                        continue;
                    }
                    else{
                        print = false; 
                        break;
                    }
                }
                else{
                    if( in[(in.length() - 1 - k)] == '6' ){
                        continue;
                    }
                    else{
                        print = false; 
                        break;
                    }
                }
            }
            else {
                print = false;
                break;
            }
        }
        if(print){
            sum++;
        }
    }
    
    printf("%d", sum);

    // 0 , 1 , 8, 9 and 6 are mirrors
}
