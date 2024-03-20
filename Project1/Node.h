#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H
class Node {

    int number;
    Node* next;
public:
    explicit Node(int number)
            : number(number), next(nullptr) {};
    friend class SinglyLinkedList;
    friend class SinglyLinkedListHT;

};

#endif //PROJECT2_LINKEDLIST_H