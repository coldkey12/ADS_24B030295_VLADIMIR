#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    Node<int> *head = NULL;

    while (true) {
        int n;
        if (!(cin >> n)) break;

        if (n == 0) {
            break;
        } else if (n == 1) {
            int val, pos;
            cin >> val >> pos;
            Node<int> *newNode = new Node<int>(val);
            if (pos == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                Node<int> *currentNode = head;
                for (int i = 0; i < pos - 1 && currentNode != NULL; i++) {
                    currentNode = currentNode->next;
                }
                newNode->next = currentNode->next;
                currentNode->next = newNode;
            }
        } else if (n == 2) {
            int pos;
            cin >> pos;
            if (pos == 0) {
                if (head) {
                    Node<int> *temp = head;
                    head = head->next;
                    delete temp;
                }
            } else {
                Node<int> *current = head;
                for (int i = 0; i < pos - 1 && current != NULL; i++) {
                    current = current->next;
                }
                if (current && current->next) {
                    Node<int> *temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
            }
        } else if (n == 3) {
            if (head == NULL) {
                cout << "-1" << endl;
            } else {
                Node<int> *currentNode = head;
                while (currentNode != NULL) {
                    cout << currentNode->data << " ";
                    currentNode = currentNode->next;
                }
                cout << endl;
            }
        } else if (n == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            if (p1 != p2) {
                Node<int> *removed;
                if (p1 == 0) {
                    removed = head;
                    head = head->next;
                } else {
                    Node<int> *prev = head;
                    for (int i = 0; i < p1 - 1; i++) {
                        prev = prev->next;
                    }
                    removed = prev->next;
                    prev->next = removed->next;
                }
                if (p2 == 0) {
                    removed->next = head;
                    head = removed;
                } else {
                    Node<int> *prev = head;
                    for (int i = 0; i < p2 - 1; i++) {
                        prev = prev->next;
                    }
                    removed->next = prev->next;
                    prev->next = removed;
                }
            }
        } else if (n == 5) {
            Node<int> *prev = NULL;
            Node<int> *current = head;
            while (current != NULL) {
                Node<int> *next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        } else if (n == 7) {
            int x;
            cin >> x;
            if (!head || !head->next || x == 0) continue;
            Node<int>* temp = head;
            int len = 1;
            while (temp->next) {
                temp = temp->next;
                len++;
            }
            x = x % len;
            if (x == 0) continue;
            temp->next = head;
            Node<int> *newTail = head;
            for (int i = 0; i < len - x - 1; i++) {
                newTail = newTail->next;
            }
            Node<int> *newHead = newTail->next;
            newTail->next = NULL;
            head = newHead;
        } else if (n == 6) {
            int x;
            cin >> x;
            if (!head || !head->next || x == 0) continue;
            Node<int> *temp = head;
            int len = 1;
            while (temp->next) {
                temp = temp->next;
                len++;
            }
            x = x % len;
            if (x == 0) continue;
            temp->next = head;
            Node<int> *newTail = head;
            for (int i = 0; i < x - 1; i++) {
                newTail = newTail->next;
            }
            Node<int> *newHead = newTail->next;
            newTail->next = NULL;
            head = newHead;
        }
    }
    return 0;
}