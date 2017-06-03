#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
using namespace std;

typedef long long ll;

// BEGIN AVL
template <typename T> 
struct Node { 
  T val; 
  Node<T> *left; 
  Node<T> *right;
  ll lchild;
  ll rchild;
  ll height; 

  Node(T v) : val(v), lchild(0), rchild(0), left(nullptr), right(nullptr), height(1){  }

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

};


template <typename T> 
Node<T> * insert(Node<T> *root, T val){
  if(root == nullptr){
    return new Node<T>(val); 
  }

  if(val < root->val) {
    root->left = insert(root->left, val); 
    root->lchild++; 
  }
  else {
    root->right = insert(root->right, val); 
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
T getKthSmallest(Node<T> *root, ll n) { 
  if(root == nullptr) return 0; 
  if(n == root->lchild + 1){
    return root->val; 
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

  Node<T> *curr; 
  Node<T> *parent; 
  if(a->lchild + a->rchild < b->lchild + b->rchild){
    curr = a; 
    parent = b; 
  }
  else{ 
    curr = b; 
    parent = a; 
  }

  parent = insert(parent, curr); 
  Node<T> *merge(parent, curr->right); 
  Node<T> *merge(parent, curr->left); 
  curr = delnode(curr,curr->val); 
}


//END AVL

void test() {
  Node<int> *root = nullptr; 

  vector<int> vr; 

  root = insert(root, 4); 
  root = insert(root, 2); 
  root = insert(root, 5); 
  root = insert(root, 6); 
  root = insert(root, 9); 
  root = insert(root, -3); 
  assert(6 == lookup(root,9)); 
  root = delnode(root,-3); 
  assert(5 == lookup(root,9)); 
  root = delnode(root,5); 
  assert(4 == lookup(root,9)); 
  

  root = nullptr; 
  for(int i = 0; i<99999; i++){
    int r = rand(); 
    if(lookup(root,r) == -1){
      vr.push_back(r); 
      root = insert(root, r); 
      assert(lookup(root,r) != -1); 
    }
  }
  sort(vr.begin(), vr.end());
  for(int i = 0; i<vr.size(); i++){
    cout << lookup(root,vr[i]) << " " << (i + 1) << endl; 
    assert(lookup(root,vr[i]) == (i + 1) );
  }
  for(int i = 0; i<99999; i++){
    assert(getKthSmallest(root,i+1) == vr[i]); 
    cout << vr[i] << endl;
  }

  for(int i = 0; i<vr.size(); i++){
    root = insert(root, vr[i]); 
  }

  for(int i = 0; i<vr.size(); i++){
    root = delnode(root, vr[i]); 
  }
}

int main(){
  Node<ll> *root = nullptr; 
  //test(); 
  ll N, M; 
  scanf("%lld %lld", &N, &M); 
  ll lastans = 0; 

  while(N--){
    ll v;
    scanf("%lld", &v); 
    root = insert(root, v); 
  }

  while(M--){
    char c; 
    ll v;
    scanf(" %c %lld", &c, &v); 

    if(c == 'I'){
      root = insert(root,v ^ lastans); 
    }
    else if(c == 'L'){
      v = v ^ lastans;
      lastans = lookup(root,v); 
      printf("%lld\n", lastans);
    }
    else if(c == 'S'){
      v = v ^ lastans;
      lastans = getKthSmallest(root,v); 
      printf("%lld\n", lastans);
    }
    else{
      root = delnode(root,v ^ lastans); 
    }
  }

  preorder(root);
  printf("\n"); 
}
