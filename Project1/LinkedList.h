#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H
#include "List.h"
#include <iostream>

class Node {
public:
    int number;
    Node* next;

    Node(int number);// używamy przy tworzeniu nowych węzłów
};

class SinglyLinkedList : public List {
    Node* head; //następny element na liscie
    int size;

public:
    SinglyLinkedList();

    ~SinglyLinkedList();

    void AddFront(int element) override;

    void AddBack(int element) override;

    void Add(int element, int index) override;

    bool RemoveFront() override;

    bool RemoveBack() override;

    bool Remove(int index) override;

    bool Find(int element) override;

    int ReturnElement(int index) override;

    int ReturnSize() override {
        return size;
    }

    bool isEmpty() override {
        return size == 0;
    }

    void Print() override;
};


#endif //PROJECT1_LINKEDLIST_H
