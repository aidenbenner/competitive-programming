#include <iostream>
using namespace std;

struct StackNode
{
  StackNode *next;
  int val; 
};

class Stack {
  private:
    StackNode* firstNode; 
    StackNode* lastNode; 
    int size; 

  public:
    int pop(); 
    int peek(); 
    void push(int val); 
    bool isEmpty(); 
    Stack(); 
};

Stack::Stack ()
{
  this->size = 0; 
  this->firstNode == NULL;
  this->lastNode== NULL;
}

void Stack::push(int val)
{
  if(size == 0){
    this->firstNode = new StackNode; 
    this->firstNode->val = val; 
    this->firstNode->next = NULL; 
    this->lastNode = this->firstNode; 
  }
  else{
    StackNode *nextNode = new StackNode;
    nextNode->val = val; 
    nextNode->next = this->lastNode; 
    this->lastNode = nextNode; 
  }
  size++; 
}

int Stack::peek()
{
  if(size == 0)
  {
    return 0; 
  }
  return this->lastNode->val; 
}

bool Stack::isEmpty()
{
  return this->size <= 0; 
}

int Stack::pop()
{
  if(size == 0){
    return 0; 
  }

  int tmp = this->lastNode->val; 

  StackNode *holder = this->lastNode;
  this->lastNode = this->lastNode->next;  

  delete holder; 
  size--; 

  return tmp; 
}

int main()
{
  Stack test; 
  test.push(5); 
  test.push(20); 
  test.push(23); 
  test.push(-23); 
  cout << test.pop() << endl; 
  cout << test.pop() << endl; 
  test.push(69); 
  cout << test.pop() << endl; 
  cout << test.pop() << endl; 
  cout << test.pop() << endl; 
  cout << test.pop() << endl; 
  cout << test.pop() << endl; 
  cout << test.pop() << endl; 
}


