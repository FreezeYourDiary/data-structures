#ifndef PROJECT1_DNODE_H
#define PROJECT1_DNODE_H

class DNode {
    int number;
    DNode* prev;
    DNode* next;
public:

    DNode(int number) : number(number), prev(nullptr), next(nullptr) {}
    friend class DLinkedList;
};

#endif //PROJECT1_DNODE_H