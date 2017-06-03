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
        ind = 7;
        rep = ind - 15;
    }
    else if (ind <= 22){
        ind = 8;
        rep = ind - 19;
    }
    else {
        ind = 9;
        rep = ind - 22;
    }
    string out = "";
    if(lastIndex == ind){
        out += "#"; 
    }
    lastIndex = ind;
    for(int i = 0; i<rep; i++){
        out += mapping[ind];
    }
    return out; 
}




using namespace std;
int main(){
    for(int i = 0; i<9; i++){
        int n ; 
        scanf("%d", &n);
        mapping[i] = n;
    }

    string s;  
    cin >> s; 
    
    string out = "";
    for(int i = 0; i<s.length(); i++){
        out += charToNumStr(s[i]);
    }
    cout << out;
}
