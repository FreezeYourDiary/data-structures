#ifndef PROJECT1_LINKEDLIST2_H
#define PROJECT1_LINKEDLIST2_H

#include "List.h"
#include <iostream>
#include "DNode.h"

class DLinkedList : public List {
private:
    Node* head; 
    Node* tail; 
 

public:
    DLinkedList();

 
    ~DLinkedList() override;

    void AddFront(int element) override;

    void AddBack(int element) override;

    void Add(int element, int index) override;

    bool RemoveFront() override;

    bool RemoveBack() override;

    bool Remove(int index) override;

    bool Find(int element) override;

    int ReturnElement(int index) override;

    int ReturnSize() override;

    bool isEmpty() override;

    void Print() override;
};

#endif //PROJECT1_LINKEDLIST2_H