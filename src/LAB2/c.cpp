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
        Node<int>* newNode = new Node<int>(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node<int> *currentNode = head;
    int index = 0;
    while (currentNode != NULL) {
        if (index % 2 == 0) {
            cout << currentNode->data << " ";
        }
        currentNode = currentNode->next;
        index++;
    }

    return 0;
}