#include <queue>
#include <vector>
#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) { }
};


vector<queue<Node*>> getLists(Node *root) {
    vector<queue<Node*>> out;
    if (root == nullptr) return out;
    queue<Node*> next;
    queue<Node*> curr;
    next.push(root);

    while (!next.empty()) {
        out.push_back(next);
        curr = next;
        next = queue<Node*>();
        while (!curr.empty()) {
            auto n = curr.front();
            curr.pop();
            if (n->left != nullptr) {
                next.push(n->left);
            }
            if (n->right != nullptr) {
                next.push(n->right);
            }
        }
    }
    return out;
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
//    5
//  3    7
//1  4

bool validate_bst(Node *root, int mini, int maxi) {
    if (root == nullptr) return true;
    if (root->val > maxi) return false;
    if (root->val <= mini) return false;

    return validate_bst(root->left, mini, root->val) &&
        validate_bst(root->right, root->val, maxi);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    auto n = makeBalanced(a, 0, 9);
    assert(validate_bst(n, INT_MIN, INT_MAX));
    n->right = new Node(-1);
    assert(!validate_bst(n, INT_MIN, INT_MAX));
    n->right = new Node(n->val);
    assert(!validate_bst(n, INT_MIN, INT_MAX));
}

