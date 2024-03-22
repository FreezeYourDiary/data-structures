#include "LinkedList.h"

#ifndef PROJECT1_SINGLYLINKEDLISTHT_H
#define PROJECT1_SINGLYLINKEDLISTHT_H


class SinglyLinkedListHT : public SinglyLinkedList {
    Node* tail;
public:
    SinglyLinkedListHT(): SinglyLinkedList(), tail(nullptr){};
    ~SinglyLinkedListHT();
    void AddBack(int element)override;
    void Clear() override;
};


#endif //PROJECT1_SINGLYLINKEDLISTHT_H