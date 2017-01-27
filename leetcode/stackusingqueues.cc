/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
#include <queue>
#include <iostream>

using namespace std;
class MyStack {
  public:

    queue<int> first; 
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
      first.push(x); 
      for(int i = 0; first.size() - 1; i++){
        first.push(first.front()); 
        first.pop(); 
      }
    }

    /** Removes the element on top of the stack and returns that element. */ 
    int pop() { 
      int out = first.front(); 
      first.pop();
      return out; 
    }

    /** Get the top element. */
    int top() {
      return first.front(); 
    }

    /** Returns whether the stack is empty. */
    bool empty() {
      return first.size() == 0; 
    }
};

