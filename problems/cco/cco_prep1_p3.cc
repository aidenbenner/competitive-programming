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

//dis set
//                       
const int DIS_SET_SIZE = 100005;
int disp[DIS_SET_SIZE];
int disr[DIS_SET_SIZE];


int ds_create(int x){
  disp[x] = x; 
  disr[x] = 0; 
}

int ds_find(int x) {
  if(x != disp[x]) return disp[x] = ds_find(disp[x]); 
  return x; 
}

int ds_merge(int x, int y){
  x = ds_find(x);
  y = ds_find(y); 

  if(disr[x] > disr[y]){
    disp[y] = x; 
  }
  else{
    disp[x] = y; 
  }
  if(disr[x] == disr[y])
    disr[y] = disr[y] + 1;
}


// BEGIN AVL
template <typename T> 
struct Node { 
  T val; 
  int ind; 
  Node<T> *left; 
  Node<T> *right;
  ll lchild;
  ll rchild;
  ll height; 

  Node(T v, int c) : val(v), ind(c), lchild(0), rchild(0), left(nullptr), right(nullptr), height(1){  }

  ll getRightHeight() { 
    if(this->right == nullptr) return 0; 
    return this->right->height;
  }

  ll getLeftHeight() { 
    if(this->left == nullptr) return 0; 
    return this->left->height;
  }

  ll updateHeight() { 
    height = max(getLeftHeight() , getRightHeight()) + 1;
  }

  ll getAvl() {
    return getRightHeight() - getLeftHeight();
  }

  int size() {
    return lchild + rchild;
  }

};


template <typename T> 
Node<T> * insert(Node<T> *root, T val, int n){
  if(root == nullptr){
    return new Node<T>(val, n); 
  }

  if(val < root->val) {
    root->left = insert(root->left, val, n); 
    root->lchild++; 
  }
  else {
    root->right = insert(root->right, val, n); 
    root->rchild++; 
  }

  root->updateHeight(); 
  ll avl = root->getAvl(); 
  if(abs(avl) <= 1) return root;

  //cout << "  avl " << avl << endl;
  if(-avl > 0){
    if(-root->left->getAvl() >= 0){
      return rightrotate(root);
    }
    return leftrightrotate(root); 
  }
  else{
    if(-root->right->getAvl() <= 0){
      return leftrotate(root); 
    }
    return rightleftrotate(root); 
  }
} 

template <typename T> 
Node<T> * delnode(Node<T>* root, T val, bool first = false){
  if(lookup(root,val) == -1) return root;
  return deletenode(root, val); 
}

template <typename T> 
Node<T> * deletenode(Node<T>* root, T val, bool first = false){
  if(root == nullptr){
    return nullptr; 
  }

  if(val < root->val) {
    root->left = deletenode(root->left, val); 
    root->lchild--; 
  }
  else if(val > root->val){
    root->right = deletenode(root->right, val); 
    root->rchild--; 
  } else {
    if(root->left == nullptr && root->right == nullptr){
      delete root; 
      return nullptr; 
    }

    else if(root->left == nullptr){
      Node<T> * curr = root->right;
      delete root;
      return curr;
    }
    else if(root->right == nullptr){
      Node<T> * curr = root->left;
      delete root;
      return curr;
    }

    Node<T> * curr = root->right;
    while(curr->left != nullptr){
      curr = curr->left; 
    }
    root->val = curr->val; 
    root->right = deletenode(root->right, curr->val); 
    root->rchild--; 
  }

  root->updateHeight(); 
  ll avl = root->getAvl(); 
  if(abs(avl) <= 1) return root;

  if(-avl > 0){
    if(-root->left->getAvl() >= 0){
      return rightrotate(root);
    }
    return leftrightrotate(root); 
  }
  else{
    if(-root->right->getAvl() <= 0){
      return leftrotate(root); 
    }
    return rightleftrotate(root); 
  }
}

template <typename T> 
void preorder(Node<T> *root){
  if(root != nullptr){
    preorder(root->left);
    printf("%lld ", root->val);
    preorder(root->right);
  }
}

template <typename T> 
ll lookup(Node<T> * root, T val){
  if(root == nullptr){
    return -1; 
  }
  if(val < root->val){
    return lookup(root->left,val);
  } else if(val > root->val){
    ll tmp = lookup(root->right,val);
    if(tmp == -1){
      return tmp;
    }
    return root->lchild +1 + tmp;
  } else {
    ll tmp = lookup(root->left,val);
    return tmp == -1 ? root->lchild + 1 : tmp;
  }
}

template <typename T> 
Node<T> * rightrotate(Node<T>* c){
  Node<T>* b = c->left; 
  Node<T>* a = c->left->left; 

  c->left = b->right; 
  b->right = c; 
  b->left = a; 

  c->updateHeight(); 
  b->updateHeight(); 

  c->lchild = b->rchild;
  b->rchild += 1 + c->rchild; 
  return b;
}

template <typename T> 
Node<T> * leftrotate(Node<T>* c){
  Node<T>* b = c->right; 
  Node<T>* a = c->right->right; 
  c->right = b->left; 
  b->left = c; 
  b->right = a; 
  c->updateHeight(); 
  b->updateHeight(); 
  c->rchild = b->lchild;
  b->lchild += 1 + c->lchild; 
  return b;
}

template <typename T> 
int getKthSmallest(Node<T> *root, ll n) { 
  if(root == nullptr) return 0; 
  if(n > 1 + root->lchild + root->rchild){
    return -1; 
  }
  if(n == root->lchild + 1){
    return root->ind; 
  }
  if(n < root->lchild + 1){
    return getKthSmallest(root->left, n); 
  }
  else{
    return getKthSmallest(root->right, n - root->lchild - 1); 
  }
}

template <typename T> 
Node<T> * leftrightrotate(Node<T>* c){
  c->left = leftrotate(c->left); 
  return rightrotate(c); 
}

template <typename T> 
Node<T> * rightleftrotate(Node<T>* c){
  c->right = rightrotate(c->right); 
  return leftrotate(c); 
}


template <typename T> 
Node<T> *merge(Node<T>*a, Node<T>*b){
  if(a == nullptr) return b; 
  if(b == nullptr) return a; 

  a = merge(a, b->left); 
  a = insert(a, b->val, b->ind); 
  return merge(a, b->right); 
}

//END AVL
               
Node<int>* tre[100005];

void make_friend(int A, int B){
  int a = ds_find(A);
  int b = ds_find(B); 

  auto treeA = tre[a]; 
  auto treeB = tre[b]; 

  if(treeA == treeB) return;

  ds_merge(a,b); 
  int c = ds_find(a); 
  if(treeA->size() >= treeB->size()){
    tre[c] = merge(treeA, treeB);
  }
  else{
    tre[c] = merge(treeB, treeA);
  }
}



int N, M; 
int main()
{
  scanf("%d %d", &N, &M); 
  for(int i = 0; i<N; i++){
    int r;
    scanf("%d ", &r); 

    Node<int> * b = new Node<int>(r,i); 
    tre[i] = b; 
    ds_create(i); 
  } 

  for(int i = 0; i<M; i++){
    int A, B;
    scanf("%d %d", &A, &B); 
    A--;
    B--; 
    make_friend(A,B); 
  }

  int T;
  scanf("%d", &T);
  while(T--){
    char op; 
    int A, B; 
    scanf(" %c %d %d", &op, &A, &B); 
    A--;
    B--; 
    if(op == 'B'){
      make_friend(B,A); 
      continue;
    }
    B++;
    int out = getKthSmallest(tre[ds_find(A)], B); 
    if(out == -1){ printf("-1\n"); continue;}
    printf("%d\n",  (1 + out) );
  }
}
