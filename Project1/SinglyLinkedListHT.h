#include "LinkedList.h"

#ifndef PROJECT1_SINGLYLINKEDLISTHT_H
#define PROJECT1_SINGLYLINKEDLISTHT_H


class SinglyLinkedListHT : public SinglyLinkedList {
    Node* tail;
public:
    SinglyLinkedListHT(): tail(nullptr){};
    void AddBack(int element)override;
};


#endif //PROJECT1_SINGLYLINKEDLISTHT_H
