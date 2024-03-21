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
//    void PrintNode(){
//
//    }// w sumie nie widze sensu bo nie zmniejsza ilości kodu skoro używamy tylko dla SinglyLinkedList&HT.
    // !!!tylko teraz wpadłem na pomysł dać to jako klas rodzica dla DNode i po prostu dodać implementacje.

};

#endif //PROJECT2_LINKEDLIST_H