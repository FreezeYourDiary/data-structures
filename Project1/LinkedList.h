#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H
#include "List.h"
#include <iostream>

class Node {
public:
    int number;
    Node* next;

    Node(int number) : number(number), next(nullptr) {}// używamy przy tworzeniu nowych węzłów
};

class SinglyLinkedList : public List {
private:
    Node* head; //następny element na liscie
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    ~SinglyLinkedList()  {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void AddFront(int element) override {
        Node* newNode = new Node(element);
            // int number;
            // Node* next;
        newNode->next = head; //obecny początek listy, 0->,1,2,3,4,5
        head = newNode; // czyli to teraz początek listy
        size++;
    }

    void AddBack(int element) override {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = newNode;
            // czy lista jest pusta.
        } else {
            Node* current = head;
            // 1,2,3,4,5 ->nullptr
            // dopoki nie nullptr, przesuwamy się listą
            while (current->next != nullptr) {
                current = current->next;
            }
            //kiedy nullptr [czyli koniec listy], ten sąsiad który był nullptr(czyli go nie istniało), przypisujemy wartośc newNode;
            current->next = newNode;
        }
        size++;
    }

    void Add(int element, int index) override {
        if (index < 0 || index > size) {
            std::cout << "Invalid index\n";
            return;
        }
        // przypadki dla krańców zakresu
        if (index == 0) {
            AddFront(element);
        } else if (index == size) {
            AddBack(element);

        } else {
            Node* newNode = new Node(element); // wstawiany do listy na pozycji index
            Node* current = head; //gdy stwarzamy lilse -> nullptr

            for (int i = 0; i < index - 1; i++) {
                current = current->next; //index-1
            }
            // Ustawiamy wskaźnik next nowego węzła tak, aby wskazywał na węzeł, który wcześniej znajdował
            // się na pozycji index. Oznacza to, że nowy węzeł będzie teraz wskazywał na ten sam element,
            // na który wcześniej wskazywał węzeł poprzedzający index.
            newNode->next = current->next; // index
            // Ustawiamy wskaźnik next węzła poprzedzającego pozycję index tak, aby wskazywał na nowy węzeł.
            // W ten sposób nowy węzeł zostaje "wstawiony" do listy na pozycji index.
            current->next = newNode;
            size++;
        }
    }

    bool RemoveFront() override {
        if (isEmpty()) {
            std::cout << "List is empty\n";
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    bool RemoveBack() override {
        if (isEmpty()) {
            std::cout << "List is empty\n";
            return false;
        }
        if (size == 1) {
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
        size--;
        return true;
    }

    bool Remove(int index) override {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index\n";
            return false;
        }
        if (index == 0) {
            return RemoveFront();
        } else if (index == size - 1) {
            return RemoveBack();
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
    }

    bool Find(int element) override {
        Node* current = head;
        while (current != nullptr) {
            if (current->number == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int ReturnElement(int index) override {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index\n";
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->number;
    }

    int ReturnSize() override {
        return size;
    }

    bool isEmpty() override {
        return size == 0;
    }

    void Print() override {
        Node* current = head;
        while (current != nullptr) {
            std::cout <<"\nliczba: \n" << current->number << "\n Adres:\n " << &current->number;
            current = current->next;
        }
        std::cout << std::endl;
    }
};


#endif //PROJECT1_LINKEDLIST_H
