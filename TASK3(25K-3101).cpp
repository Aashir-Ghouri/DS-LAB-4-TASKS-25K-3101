#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
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
        while (count < pos - 1) {
            temp = temp->next;
            count++;
        }
        Node* nextNode = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nextNode;
        nextNode->prev = newNode;
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
        do {
            if (curr->data == val) {
                Node* prevNode = curr->prev;
                Node* nextNode = curr->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                if (curr == head) {
                    head = nextNode;
                }
                delete curr;
                return;
            }
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
            cout << temp->data << "<->";
            temp = temp->next;
        } while (temp != head);
        cout <<"(HEAD VALUE)" << endl;
    }
};

int main() {
    CircularDoublyLinkedList list;

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
