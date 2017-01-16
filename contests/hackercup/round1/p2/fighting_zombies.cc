#include <bitset>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

vector < pair<int,int> > cords; 

vector< bitset<55> > rects;
bitset<55> temp_b ;

int main()
{
  int T; 
  cin >> T; 

  for(int test = 1; test<=T; test++){
    int N, R;
    cin >> N >> R;

    rects.clear(); 
    cords.clear(); 
    temp_b.reset(); 

    cords.resize(N); 
    for(int i = 0; i<N; i++){
      int X, Y; 
      cin >> X >> Y; 
      cords[i].first = X;
      cords[i].second = Y; 
    }

    for(int i = 0; i<cords.size(); i++){
      for(int k = 0; k<cords.size(); k++){
        //determine if there exists 
        int pX = cords[i].first;
        int pY = cords[k].second;

        temp_b.reset();
        for(int j = 0; j<cords.size(); j++){
          int p2X = cords[j].first;
          int p2Y = cords[j].second;

          if(pX - p2X >= 0 && pX - p2X <= R && pY - p2Y >=0 && pY - p2Y <= R){
            temp_b[j] = 1; 
          }
        }
        rects.push_back(temp_b); 
      }
    }

    int Rmax = 0; 
    temp_b.reset(); 
    for(int i = 0; i<rects.size(); i++){
      for(int k = 0; k<rects.size(); k++){
        temp_b = rects[i] | rects[k];
        Rmax = max(Rmax, (int)temp_b.count());
      }
    }
    cout << "Case #" << test << ": " << Rmax << endl;
 
  }
}

