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
    int n;
    cin >> n;

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node<int> *currentNode = new Node<int>(value);

        if (head == NULL) {
            head = currentNode;
            tail = currentNode;
        } else {
            tail->next = currentNode;
            tail = currentNode;
        }
    }

    int pos, value;
    cin >> value;
    cin >> pos;

    Node<int> *newNode = new Node<int>(value);

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<int> *currentNode = head;
        for (int i = 0; i< pos - 1 && currentNode != NULL; i++) {
            currentNode = currentNode->next;
        }
        if (currentNode != NULL) {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    Node<int> *printNode = head;
    while (printNode != NULL) {
        cout << printNode->data << " ";
        printNode = printNode->next;
    }
}