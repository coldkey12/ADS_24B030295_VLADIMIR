#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int cnt;
    Node* left;
    Node* right;
    Node(int k) : key(k), cnt(1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            node->cnt++;
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            node->cnt--;
            if (node->cnt == 0) {
                if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                Node* temp = findMin(node->right);
                node->key = temp->key;
                node->cnt = temp->cnt;
                temp->cnt = 1;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        return node;
    }

    int count(Node* node, int key) {
        if (node == nullptr) {
            return 0;
        }

        if (key < node->key) {
            return count(node->left, key);
        } else if (key > node->key) {
            return count(node->right, key);
        } else {
            return node->cnt;
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    int count(int key) {
        return count(root, key);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    BST bst;

    while (q--) {
        string op;
        int key;
        cin >> op >> key;

        if (op == "insert") {
            bst.insert(key);
        } else if (op == "delete") {
            bst.deleteKey(key);
        } else if (op == "cnt") {
            cout << bst.count(key) << "\n";
        }
    }

    return 0;
}