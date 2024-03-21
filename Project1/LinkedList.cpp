#include "LinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
        // pomocnicza, która przechowuje adres current węzła,
        // aby  nie utracić referencji do węzła, który ~~zostanie usunięty.
    }
    head = nullptr;
}

void SinglyLinkedList::AddFront(int element) {
    Node* newNode = new Node(element);
    newNode->next = head; //czyli nowy węzeł wskazuje na obecny pierwszy element listy.
    head = newNode; //aktualizacja headu teraz już jako ten pierwszy element
}

void SinglyLinkedList::AddBack(int element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        head = newNode;
        // czyli zamiast isEmpty.
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void SinglyLinkedList::Add(int element, int index) {
    if (index < 0) {
        std::cout << "Invalid index\n";
        return;
    }
    if (index == 0) {
        AddFront(element);
    } else {
        Node* newNode = new Node(element);
        Node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            // no size fix
            std::cout << "Invalid index\n";
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

bool SinglyLinkedList::RemoveFront() {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool SinglyLinkedList::RemoveBack() {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return false;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    return true;
}

bool SinglyLinkedList::Remove(int index) {
    if (index < 0) {
        std::cout << "Invalid index\n";
        return false;
    }
    if (index == 0) {
        return RemoveFront();
    }
    Node* current = head;
    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        std::cout << "Invalid index\n";
        return false;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}

//todo w postaci zwracania liczby
bool SinglyLinkedList::Find(int element) {
    Node* current = head;
    while (current != nullptr) {
        if (current->number == element) {
            std::cout << "Liczba: " << element << std::endl;
            std::cout << "Pod adresem: " << current << std::endl;
            return true;
        }
        current = current->next;
    }
    std::cerr<<"Nieprawidlowy index";
    return false;
}

int SinglyLinkedList::ReturnElement(int index) {
    if (index < 0) {
        std::cout << "Invalid index\n";
        return 1;
    }
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    //size fix
    }
    if (current == nullptr) {
        //since not size
        std::cout << "Invalid index\n";
        return 1;
    }
    return current->number;
}

void SinglyLinkedList::Print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "\nliczba: \n" << current->number << "\nAdres:\n " << current;
        current = current->next;
    }
    std::cout << std::endl;
}
