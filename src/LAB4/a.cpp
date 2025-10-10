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

bool pathExists(Node* root, string path) {
    Node* current = root;
    for (char c : path) {
        if (current == nullptr) {
            return false;
        }
        if (c == 'L') {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current != nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;
        if (pathExists(root, path)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}