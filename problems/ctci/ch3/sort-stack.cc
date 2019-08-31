#include<vector>
#include<iostream>
#include<stack>
using namespace std;

stack<int> sort(stack<int> a) {
    stack<int> tmp;
    while(a.size() != 0) {
        while(tmp.size() == 0 || a.top() >= tmp.top()) {
            tmp.push(a.top());
            a.pop();
            if (a.size() == 0) return tmp;
        }
        int x = a.top();
        a.pop();
        while (tmp.size() > 0 && x < tmp.top()) {
            a.push(tmp.top());
            tmp.pop();
        }
        tmp.push(x);
    }
    return tmp;
}

int main() {
    stack<int> x;
    x.push(5);
    x.push(1);
    x.push(3);
    x.push(4);
    x.push(2);
    x.push(7);
    x.push(5);

    x = sort(x);
    while (x.size() != 0) {
        cout << x.top() << endl;
        x.pop();
    }
}



