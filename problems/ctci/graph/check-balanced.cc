#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) { }
};


int height(Node *root) {
    if (root == nullptr) return -1;
    
    int l = height(root->left);
    int r = height(root->right);
    if (l == -10) return l;
    if (r == -10) return r;

    if (abs(l - r) >= 2) {
        return -10;
    }

    return max(l, r) + 1;
}

bool isBalanced(Node *root) {
    return height(root) != -10;
}


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
    Node *n = makeBalanced(a, 0, 9);
    print(n);
    cout << isBalanced(n) << endl;
    n->right = nullptr;
    cout << isBalanced(n) << endl;
}





