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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void arrangeList() {
        if (head == NULL || head->next == NULL) {
            return;
        }

        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;

        while (curr != NULL) {
            if (curr->data % 2 == 0) {
                if (evenStart == NULL) {
                    evenStart = curr;
                    evenEnd = curr;
                } else {
                    evenEnd->next = curr;
                    evenEnd = curr;
                }
            } else {
                if (oddStart == NULL) {
                    oddStart = curr;
                    oddEnd = curr;
                } else {
                    oddEnd->next = curr;
                    oddEnd = curr;
                }
            }
            curr = curr->next;
        }

        if (oddStart == NULL) {
            head = evenStart;
            return;
        }

        if (evenStart == NULL) {
            head = oddStart;
            return;
        }

        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    void takeInput() {
        cout << "Enter numbers (-9999 to stop): ";
        int val;
        while (cin >> val && val != -9999) {
            insert(val);
        }
    }
};

int main() {
    LinkedList list;

    list.takeInput();

    cout << "Input List: ";
    list.printList();

    list.arrangeList();

    cout << "Output List: ";
    list.printList();

    return 0;
}
