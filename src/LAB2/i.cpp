#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string book;
            cin >> book;
            Node* node = new Node(book);
            if (!head) {
                head = tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            cout << "ok" << endl;
        } else if (command == "add_back") {
            string book;
            cin >> book;
            Node* node = new Node(book);
            if (!tail) {
                head = tail = node;
            } else {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            cout << "ok" << endl;
        } else if (command == "erase_front") {
            if (!head) {
                cout << "error" << endl;
            } else {
                Node* temp = head;
                cout << temp->data << endl;
                head = head->next;
                if (head) head->prev = NULL;
                else tail = NULL;
                delete temp;
            }
        } else if (command == "erase_back") {
            if (!tail) {
                cout << "error" << endl;
            } else {
                Node* temp = tail;
                cout << temp->data << endl;
                tail = tail->prev;
                if (tail) tail->next = NULL;
                else head = NULL;
                delete temp;
            }
        } else if (command == "front") {
            if (!head) cout << "error" << endl;
            else cout << head->data << endl;
        } else if (command == "back") {
            if (!tail) cout << "error" << endl;
            else cout << tail->data << endl;
        } else if (command == "clear") {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = NULL;
            cout << "ok" << endl;
        } else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}