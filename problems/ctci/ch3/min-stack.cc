
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
class Stack {
    public:
        vector<int> arr;
        vector<int> min_ind;

        void push(int x) {
            if (arr.size() == 0) {
                arr.push_back(x);
                min_ind.push_back(0);
                return;
            }

            int m = min();
            arr.push_back(x);
            if (x < m) {
                min_ind.push_back(arr.size() - 1);
            }
        }

        int pop() {
            int out = arr.back();
            arr.pop_back();
            if (min_ind.back() == arr.size()) {
                min_ind.pop_back();
            }
            return out;
        }

        int min() {
            assert(arr.size() > 0);
            return arr[min_ind.back()];
        }
};


int main() {
    auto s = Stack();
    s.push(5);
    assert(s.min() == 5);
    s.push(1);
    assert(s.min() == 1);
    s.push(2);
    assert(s.min() == 1);
    s.pop();
    s.pop();
    assert(s.min() == 5);
    s.push(3);
    s.push(2);
    s.push(2);
    s.push(1);
    s.push(4);
    assert(s.min() == 1);
    s.pop(); s.pop();
    assert(s.min() == 2);
}
