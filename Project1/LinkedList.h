#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H
#include "List.h"
#include <iostream>
#include "Node.h"

class SinglyLinkedList : public List {
protected:
    Node* head; //następny element na liscie
//  int size;

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

    bool isEmpty() override {
        return head==nullptr; // skoro size nie używany
    }

    void Print() override;

    void Load(const char* filename)override;
};


#endif //PROJECT1_LINKEDLIST_H