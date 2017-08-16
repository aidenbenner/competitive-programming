
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

/*
 * parent = (ind - 1) / 2 
 * left = ind * 2 + 1
 * right = ind * 2 + 2
 */

template < typename T >
void swap(vector<T>& v, int a, int b){
  T tmp = v[a]; 
  v[a] = v[b]; 
  v[b] = tmp;
}

// min heap
class Heap {
  public:

    Heap(){
      size = 0; 
    }

    ll Peek(){
      if(size == 0) return 0;  
      return hp.front(); 
    }

    ll Poll(){
      ll out = hp[0]; 
      swap(hp, size - 1, 0); 
      size--;
      HeapifyDown(0); 
      return out;
    }

    void Push(ll val) {
      if(hp.size() > size){
        hp[size] = val; 
      }
      else{
        hp.push_back(val); 
      }
      size++;
      HeapifyUp(); 
    }

  private:
    int size; 
    vector<ll> hp; 

    int getParent(int ind){ return (ind - 1) / 2; }
    int getLeft(int ind){ return ind * 2 + 1; }
    int getRight(int ind){ return ind * 2 + 2; }

    bool hasLeftChild(int ind){ return getLeft(ind) < size; }
    bool hasRightChild(int ind){ return getRight(ind) < size; }

    void HeapifyUp(){
      int currInd = size - 1; 
      while(currInd != 0 && hp[currInd] < hp[getParent(currInd)]){
        swap(hp, currInd, getParent(currInd));
        currInd = getParent(currInd);
      }
    }

    void HeapifyDown(int ind){
      int curr = ind; 
      while((hasLeftChild(ind) && hp[getLeft(ind)] < hp[ind]) || (hasRightChild(ind) && hp[getRight(ind)] < hp[ind])){
        if(hasLeftChild(ind) && hp[getLeft(ind)] < hp[getRight(ind)]){
          swap(hp, getLeft(ind), ind); 
          curr = getLeft(ind);
        } else{
          swap(hp, getRight(ind), ind); 
          curr = getRight(ind);
        }
      }
    }
};


int main(){
  Heap h; 
  h.Push(5); 
  cout << h.Peek() << endl;
  h.Push(10); 
  cout << h.Peek() << endl;
  h.Push(2); 
  cout << h.Peek() << endl;
  h.Push(-5); 
  cout << h.Poll() << endl;
  cout << h.Poll() << endl;
  cout << h.Poll() << endl;
  cout << h.Poll() << endl;
}
