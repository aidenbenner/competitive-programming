#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int mapping[10]; 

int lastIndex = 0;
string charToNumStr(int c){
    //find usual character number 
    //1-24
    int ind = c - 'a' + 1;
    int rep = ind % 3;
    if(rep == 0){
        rep = 3;
    }

    if(ind <= 15){
        //15 --> 6 
        ind = (ind-1) / 3.0 + 2;
    }
    else if (ind <= 19){
        rep = ind - 15;
        ind = 7;
    }
    else if (ind <= 22){
        rep = ind - 19;
        ind = 8;
    }
    else {
        rep = ind - 22;
        ind = 9;
    }
    string out = "";
    if(lastIndex == ind){
        out += "#"; 
    }
    lastIndex = ind;

    for(int k = 0; k<9; k++){
        if(mapping[k] == ind){
            ind = k + 1;
            break;
        }
    }
    for(int i = 0; i<rep; i++){
        //look for key mapped
        out += std::to_string(ind) ;
    }
    return out; 
}




using namespace std;
int main(){
    for(int i = 0; i<9; i++){
        int n ; 
        scanf("%d", &n);
        //index = number - 1 is now mapped to 
        mapping[i] = n;
    }

    string s;  
    cin >> s; 
    
    string out = "";
    for(int i = 0; i<s.length(); i++){
        out += charToNumStr(s[i]);
    }
    cout << out << endl;
}
