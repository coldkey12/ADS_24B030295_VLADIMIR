#include <iostream>
using namespace std;

struct Node {
    char c;
    Node *next;
    Node(char ch) : c(ch), next(NULL) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int freq[26] = {0};
        Node *head = NULL;
        Node *tail = NULL;

        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            freq[c - 'a']++;

            Node *newNode = new Node(c);
            if (tail == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            while (head != NULL && freq[head->c - 'a'] > 1) {
                Node *tmp = head;
                head = head->next;
                delete tmp;
                if (head == NULL) tail = NULL;
            }

            if (head == NULL) cout << "-1 ";
            else cout << head->c << " ";
        }
        cout << "\n";

        // free remaining nodes
        while (head != NULL) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    return 0;
}