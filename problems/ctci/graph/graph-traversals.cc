#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) { }
};

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " " << endl;
    inorder(root->right);
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(2);
    root->left->left = new Node(-5);
    root->right = new Node(7);
    root->right->left = new Node(6);
    inorder(root);
}
