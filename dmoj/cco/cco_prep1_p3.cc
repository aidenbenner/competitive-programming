#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-13
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int belongs[100001]; 

class BST{
  BST* left;
  BST* right;
  int rank;
  int val; 

  public: 

  int left_child; 
  int right_child; 
  int height; 

  BST(int r, int v) {
    left = nullptr;
    right = nullptr;
    left_child = 0; 
    right_child = 0; 
    rank = r; 
    val = v; 
    height = 1; 
  }


  void insert(int r, int v)
  {
    if(rank < r){
        right_child++;
      if(right == nullptr){
        BST *bs = new BST(r,v); 
        right = bs; 
        return;
      }
      right->insert(r,v); 
    }
    else{
        left_child++; 
      if(left== nullptr){
        BST *bs = new BST(r,v); 
        left = bs; 
        return;
      }
      left->insert(r,v); 
    }
  }

  int kth_largest(int k){

    if(left_child + 1 == k){
      return val;
    }
    if(k > left_child + right_child + 1){
      //cout << "less than child" << endl;
      return -2;
    }  

    if(k <= left_child){
      if(left == nullptr) return -7; 
      return left->kth_largest(k);
    }
    if(right == nullptr) return -3; 
    return right->kth_largest(k - left_child - 1); 
  }

  void merge(BST *b, int ind)
  {
    BST *tmp = b;  
    if(b == nullptr) return;
    belongs[b->val] = ind;
    this->merge(b->left, ind); 
    delete b->left;
    this->insert(b->rank, b->val); 
    this->merge(b->right, ind); 
    delete b->right;
  }

  void print_tree()
  {
    if(left != nullptr){
      left->print_tree();
    }
    cout << "TREE :      "; 
    cout << rank << "  " << val << endl;
    if(right != nullptr){
      right->print_tree();
    }
  }

  int size()
  {
    return 1 + left_child + right_child;
  }
};

vector<BST> trees;

BST * rightRotate(BST * y)
{
    BST *x = y->left;
    BST *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

BST *leftRotate(BST *x)
{
    BST *y = x->right;
    BST *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

void make_friend(int A, int B){

  BST *treeA = &trees[belongs[A]]; 
  BST *treeB = &trees[belongs[B]]; 

  //cout << "A" << endl;
  //treeA->print_tree(); 
  //cout << "B" << endl;
  //treeB->print_tree(); 
  //cout << "C" << endl;
  if(treeA->size() > treeB->size()){
    belongs[B] = belongs[A]; 
    treeA->merge(treeB, belongs[A]);
    //treeA->print_tree(); 
  }
  else{
    belongs[A] = belongs[B];
    treeB->merge(treeA, belongs[B]);
    //treeB->print_tree(); 
  }
}



int N, M; 
int main()
{
  cin >> N >> M;
  for(int i = 0; i<N; i++){
    int r;
    cin >> r; 
    BST b =  BST(r, i); 
    trees.push_back(b); 
    belongs[i] = i; 
  }


  for(int i = 0; i<M; i++){
    int A, B;
    cin >> B >> A; 
    A--;
    B--; 
    //cout << "A A " << endl;
    make_friend(B,A); 
  }

  int T;
  cin >> T;
  while(T--){
    char op; 
    int A, B; 
    cin >> op >> A >> B;
    A--;
    B--; 
    if(op == 'B'){
      make_friend(A,B); 
      continue;
    }
    B++;
//    cout << "QUERY " << B << endl;
    //trees[belongs[A]].print_tree(); 
    if(B > trees[belongs[A]].size()) {
      cout << -1 << endl;
      continue;
    }
    cout << (1 + trees[belongs[A]].kth_largest(B)) << endl;
  }
}
