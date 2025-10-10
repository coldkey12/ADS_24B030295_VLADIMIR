#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int maxWidth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int maxW = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        maxW = max(maxW, levelSize);

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }

    return maxW;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, Node*> nodes;
    nodes[1] = new Node(1);

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (nodes.find(x) == nodes.end()) {
            nodes[x] = new Node(x);
        }
        if (nodes.find(y) == nodes.end()) {
            nodes[y] = new Node(y);
        }

        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    cout << maxWidth(nodes[1]) << "\n";

    return 0;
}