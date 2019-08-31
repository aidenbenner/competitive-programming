#include <queue>
#include <vector>
#include <iostream>
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

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    auto c = getLists(makeBalanced(a, 0, 9));
    for (auto x : c) {
        while(!x.empty()) {
            cout << x.front()->val << " ";
            x.pop();
        }
        cout << "\n" << endl;
    }
}

