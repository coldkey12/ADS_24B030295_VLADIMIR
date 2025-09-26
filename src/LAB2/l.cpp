#include <iostream>
using namespace std;

struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(NULL) {}
};

long long findMaxSum(Node* head) {
    if (!head) return 0;
    long long maxSum = head->val;
    long long currentSum = head->val;
    head = head->next;
    while (head != NULL) {
        currentSum = (currentSum > 0 ? currentSum + head->val : head->val);
        if (currentSum > maxSum) maxSum = currentSum;
        head = head->next;
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        Node* newNode = new Node(x);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << findMaxSum(head) << "\n";

    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}