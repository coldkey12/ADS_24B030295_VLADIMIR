#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* findNode(Node* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }
    if (val < root->val) {
        return findNode(root->left, val);
    }
    return findNode(root->right, val);
}

int getSize(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int target;
    cin >> target;

    Node* targetNode = findNode(root, target);
    cout << getSize(targetNode) << "\n";

    return 0;
}