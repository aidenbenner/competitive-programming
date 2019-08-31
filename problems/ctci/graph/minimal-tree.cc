#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) { }
};

Node* makeBalanced(int *a, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    cout << start << " " << end << " " << a[mid] << endl;

    Node* out = new Node(a[mid]);
    out->left = makeBalanced(a, start, mid - 1);
    out->right  = makeBalanced(a, mid + 1, end);
    return out;
}

void print(Node *n) {
    if (n == nullptr) return;
   // cout << "called" << endl;
    //if (n->left != nullptr)
   // cout << n->left->val << endl;
    //if (n->left != nullptr)
   // cout << n->right->val << endl;
    cout << n->val << endl;
    print(n->left);
    print(n->right);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    print(makeBalanced(a, 0, 9));
}
