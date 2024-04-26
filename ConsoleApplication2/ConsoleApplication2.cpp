#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void reverseDoublyLinkedList(Node*& head) {                   // Time=O(n)
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    stack<Node*> nodeStack;
    Node* current = head;

    while (current != nullptr) {
        nodeStack.push(current);
        current = current->next;
    }

    head = nodeStack.top();
    current = head;
    nodeStack.pop();
    while (!nodeStack.empty()) {
        Node* nextNode = nodeStack.top();
        current->next = nextNode;
        nextNode->prev = current;
        current = nextNode;
        nodeStack.pop();
    }
    current->next = nullptr; 
}

Node* findFromEnd(Node* head, int k) {                          // Time=O(n)
    if (head == nullptr || k <= 0) {
        return nullptr;
    }
    
    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < k; ++i) {
        if (fast == nullptr) {
            return nullptr; 
        }
        fast = fast->next;
    }
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

void printDoublyLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

   cout << "Original Doubly Linked List: ";
    printDoublyLinkedList(head);

    reverseDoublyLinkedList(head);

   cout << "Reversed Doubly Linked List: ";
    printDoublyLinkedList(head);

    int k = 2;
    Node* kthNode = findFromEnd(head, k);
    if (kthNode != nullptr) {
        cout << "The " << k << "nd node from the end is: " << kthNode->data << endl;
    }
    else {
       cout << "List is shorter than " << k << " nodes." << endl;
    }

    return 0;
}
