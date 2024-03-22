#include "SinglyLinkedListHT.h"

void SinglyLinkedListHT::AddBack(int element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;   //ten "aktualizuje" koniec listy. W sensie ¿e to co by³o nullptr teraz nowy element.
        tail = newNode;         //tu tail listy jest ustawiony jako wêzê³ dodany przez nas
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

void SinglyLinkedListHT::Clear() {
    SinglyLinkedList::Clear();
    tail = nullptr;
}
