#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str){
    stringstream ss(str);
    
    vector<int> *outVec = new vector<int>(20);

    int a;
    char c;
    do{
        ss >> a >> c; 
        outVec->push_back(a);
    }while(!ss.eof());
   
    return *outVec;
}



int main(){

}
