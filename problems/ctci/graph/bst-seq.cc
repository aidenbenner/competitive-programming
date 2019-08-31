#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) { }
};

set<vector<int>> bstseq(Node *root) {
    set<vector<int>> out;
    if (root == nullptr) return out;
    vector<int> base(1, root->val);

    auto lefts = bstseq(root->left);
    auto rights = bstseq(root->right);

    for (auto l : lefts) {
        for (auto r : rights) {
            vector<int> tmp = base;
            tmp.insert(l.begin(), l.end(), tmp.end());
            tmp.insert(r.begin(), r.end(), tmp.end());
            out.insert(tmp);
            tmp = base;
            tmp.insert(r.begin(), r.end(), tmp.end());
            tmp.insert(l.begin(), l.end(), tmp.end());
            out.insert(tmp);
        }
    }

    if (lefts.size() + rights.size() == 0) {
        out.insert(base);
        return out;
    }
    if (lefts.size() == 0) {
        for (auto r : rights) {
            vector<int> tmp = base;
            tmp.insert(r.begin(), r.end(), tmp.end());
            out.insert(tmp);
        }
    }
    if (rights.size() == 0) {
        for (auto l : lefts) {
            vector<int> tmp = base;
            tmp.insert(l.begin(), l.end(), tmp.end());
            out.insert(tmp);
        }
    }

    return out;
}

int main() {
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);


    for(auto a : bstseq(root)) {
        for (auto x : a) {
            cout << x << " ";
        }
        cout << endl;
    }

}
