#include "SinglyLinkedListHT.h"

void SinglyLinkedListHT::AddBack(int element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

SinglyLinkedListHT::~SinglyLinkedListHT() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}
