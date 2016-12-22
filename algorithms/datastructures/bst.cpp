#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node{
  struct Node * left; 
  struct Node * right;
  int val; 
} Node; 

class BST {
  public:
    BST(void); 
    ~BST(void); 
    void insert(double val); 
    double find(double val); 
    bool contains(double val);
    int get_size(); 

  private:
    Node* make_node(double val);
    int size; 
    Node * head; 
};


BST::BST(){
  this->size = 0; 
}

Node* BST::make_node(double val)
{
  Node *out = new Node;
  out->val = val; 
  out->left = NULL;
  out->right= NULL;
  return out;
}

void BST::insert(double val)
{
  if(size == 0){ 
    this->head = this->make_node(val); 
    size++;
  }
  Node *curr_node = this->head;

  while(curr_node != NULL){
    if(val < curr_node->val)
    {
      curr_node = curr_node->left; 
    }
    else
    {
      curr_node = curr_node->right; 
    }
  }
  curr_node = this->make_node(val); 
  this->size++;
}

bool BST::contains(double val){
  Node *curr = this->head;

  while(curr != NULL)
  {
    if(curr->val == val){return true;}
    if(val < curr->val){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }

  return false;
}


int BST::get_size(){
  return this->size; 
}

void free_sub_tree(Node &node){
  if(node.left != NULL){
    free_sub_tree(*node.left);
    delete node.left; 
  }
  if(node.right != NULL){
    free_sub_tree(*node.right);
    delete node.right; 
  }
}

BST::~BST(){
  free_sub_tree(*this->head);
}

int main()
{
  BST *bt = new BST(); 
  bt->insert(5); 
  bt->insert(20); 

  cout << bt->contains(20);
}




