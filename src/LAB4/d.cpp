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

void calculateLevelSums(Node* root, vector<long long>& levelSums) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        long long levelSum = 0;

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            levelSum += curr->val;

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        levelSums.push_back(levelSum);
    }
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

    vector<long long> levelSums;
    calculateLevelSums(root, levelSums);

    cout << levelSums.size() << "\n";
    for (int i = 0; i < levelSums.size(); i++) {
        cout << levelSums[i];
        if (i < levelSums.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}