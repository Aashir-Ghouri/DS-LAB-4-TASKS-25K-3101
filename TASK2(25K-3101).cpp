#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val) {
        if (head == NULL) {
            return;
        }

        if (head->data == val && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        do {
            if (curr->data == val) {
                if (curr == head) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << "(HEAD VALUE)" << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.printList();

    list.insertAtBeginning(5);
    list.printList();

    list.insertAtPosition(15, 3);
    list.printList();

    list.deleteNode(20);
    list.printList();

    return 0;
}
